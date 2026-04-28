#include <common.h>
#include <command.h> //for run_command()
#include <net.h>
#include "upgrade_helper.h"
#include "ubi_helper.h" //for ubi_probe_mtd_devices()
#include "colored_print.h" //for cprintln()
#include <zyxel_util.h>

#define FLASH_READ	0
#define FLASH_WRITE	1

static MRD dummy_mrd = {
	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
	"Zyxel dummy - dummy",
	"Z34131340 80-009-011DUMMY",
	{
		0x00, 0x00, 0x06, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x10, 0x11, 0x12, 0x13,
		0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x20, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00
	},
	"Zyxel Communications Corp.",
	"dummy",
	0x00000000,
	0xFFFF,
	0x0A,
	0xFF,
	{
		0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	},
	0x00,
	0xFF,
	{ 0x00, 0x13, 0x49, 0x00, 0x00, 0x01 },
	0xFF,
	0x01
};

int eng_debug = 0;
struct dualImageInfo dualIMAGE;

void dumpDualImageInfoFromBootconfig(void)
{
	const void *buf;
	char cmd[512];
	ulong addr = BOOTCONFIG_LOAD_ADDR;
	ulong length = sizeof(dualIMAGE);
	int size = 1;
	ulong bytes = size * length;
	char *dualInfo;
	char data;
	int num = NUMOFIMAGE/2;
	int arrNum=0;
	int startOfStatMaskbit=0,statMaskbit=0;
	int startOfLogMaskbit=0,logMaskbit=0;
	int startOfbImageMaskbit=0,bImageMaskbit=0;

	snprintf(cmd, sizeof(cmd), "nmbm nmbm0 read 0x%x 0x%x 0x%x", BOOTCONFIG_LOAD_ADDR, BOOTCONFIG_OFFSET, BOOTCONFIG_SIZE);
	run_command(cmd, 0);
	buf = map_sysmem(addr, bytes);
	dualInfo = (char *)buf;
	if(NUMOFIMAGE%2)
		num++;

	posOfStartbit(DUALIMAGE_IMGSTATE_MASK,startOfStatMaskbit,statMaskbit);
	posOfStartbit(DUALIMAGE_IMGLOG_MASK,startOfLogMaskbit,logMaskbit);
	while(num--)
	{
		arrNum = num * 2;
		if(arrNum != NUMOFIMAGE - 1){
			data = *dualInfo >> 4;
			dualIMAGE.image[arrNum + 1].state = (data >> startOfStatMaskbit) & statMaskbit;
			dualIMAGE.image[arrNum + 1].log   = (data >> startOfLogMaskbit) & logMaskbit;
		}

		data = *dualInfo;
		dualIMAGE.image[arrNum].state = (data >> startOfStatMaskbit) & statMaskbit;
		dualIMAGE.image[arrNum].log   = (data >> startOfLogMaskbit) & logMaskbit;

		dualInfo++;
	}

	data = *dualInfo;
	posOfStartbit(BOOTIMAGE_IMAGE_MASK,startOfbImageMaskbit,bImageMaskbit);
	dualIMAGE.bootImage    = (data >> startOfbImageMaskbit) & bImageMaskbit;
	dualIMAGE.upgradeImage = ((dualIMAGE.bootImage + 1) % NUMOFIMAGE) & BOOTIMAGE_IMAGE_MASK;
	unmap_sysmem(buf);

	return;
}

void writeDualImageInfoToBootconfig(void)
{
	uint8_t bootconfig[sizeof(struct dualImageInfo)] = {0};
	char cmd[512];
	char *dualInfo;
	char data;
	int num = NUMOFIMAGE/2;
	int arrNum=0;
	int startOfStatMaskbit=0,statMaskbit=0;
	int startOfLogMaskbit=0,logMaskbit=0;
	int startOfbImageMaskbit=0,bImageMaskbit=0;
	dualInfo = (char *)bootconfig;
	int i=0;

	if(NUMOFIMAGE%2)
		num++;

	posOfStartbit(DUALIMAGE_IMGSTATE_MASK,startOfStatMaskbit,statMaskbit);
	posOfStartbit(DUALIMAGE_IMGLOG_MASK,startOfLogMaskbit,logMaskbit);

	while(num--)
	{
		*dualInfo=0x0;
		data = 0x0;
		arrNum = num * 2;
		if(arrNum != NUMOFIMAGE - 1){
			data |= ((dualIMAGE.image[arrNum + 1].state & statMaskbit) << startOfStatMaskbit);
			data |= ((dualIMAGE.image[arrNum + 1].log & logMaskbit) << startOfLogMaskbit);
			*dualInfo |= data << 4;
		}
		data = 0x0;

		data |= ((dualIMAGE.image[arrNum].state & statMaskbit) << startOfStatMaskbit);
		data |= ((dualIMAGE.image[arrNum].log & logMaskbit) << startOfLogMaskbit);

		*dualInfo |= data;

		dualInfo++;
	}

	*dualInfo=0x0;
	posOfStartbit(BOOTIMAGE_IMAGE_MASK,startOfbImageMaskbit,bImageMaskbit);
	*dualInfo |= ((dualIMAGE.bootImage & bImageMaskbit) << startOfbImageMaskbit);
	for(i=0 ;i<sizeof(struct dualImageInfo);i++)
	{
		snprintf(cmd, sizeof(cmd), "mw.b 0x%x 0x%x", BOOTCONFIG_LOAD_ADDR+i, bootconfig[i]);
		run_command(cmd, 0);
	}
	snprintf(cmd, sizeof(cmd), "nmbm nmbm0 erase 0x%x 0x%x", BOOTCONFIG_OFFSET, BOOTCONFIG_SIZE);
	run_command(cmd, 0);
	snprintf(cmd, sizeof(cmd), "nmbm nmbm0 write 0x%x 0x%x 0x%x", BOOTCONFIG_LOAD_ADDR, BOOTCONFIG_OFFSET, BOOTCONFIG_SIZE);
	run_command(cmd, 0);
}

void setImageState(int image, ImageState stat)
{
	dualIMAGE.image[image].state = stat;
	return;
}

void setImageLog(int image, zyDualImageLog log)
{
	dualIMAGE.image[image].log = log;
	return;
}

void setBootImageNum(int ImageNum)
{
	dualIMAGE.bootImage = ImageNum;
	return;
}

void setUpgradeImageNum(int ImageNum)
{
	dualIMAGE.upgradeImage = ImageNum;
	return;
}

int getBootImageNum(void)
{
	return dualIMAGE.bootImage;
}

int getUpgradeImageNum(void)
{
	return dualIMAGE.upgradeImage;
}

int checkHaveNewImage(void)
{
	int imageNum=0;

	while(imageNum < NUMOFIMAGE)
	{

		if(dualIMAGE.image[imageNum].state == NEW_IMAGE)
		{
			setImageState(imageNum,FAIL_IMAGE);
			writeDualImageInfoToBootconfig();
			break;
		}
		imageNum++;
	}
	if(imageNum == NUMOFIMAGE){
		imageNum = getBootImageNum();
	}

	return imageNum;
}

struct mtd_info *zy_get_flash_mtd_dev(const char *name)
{
	struct mtd_info *mtd;

	ubi_probe_mtd_devices();

	mtd = get_mtd_device_nm(name);
	if (IS_ERR(mtd)) {
		cprintln(ERROR, "*** MTD partition '%s' not found! ***", name);
		return ERR_PTR(-ENOENT);
	}

	put_mtd_device(mtd);

	return mtd;
}

/*
 * Reference by uboot-ramips-2018.09-mt7621/board/ralink/common/cmd_mtkupgrade.c
 * CONFIG_CMD_MTDPARTS must be set in include/config/xxx_defconfig first.
 */
int zy_get_mtd_part_info(const char *partname, uint64_t *off, uint64_t *size)
{
	struct mtd_device *dev;
	struct part_info *part;
	u8 pnum;
	int ret;

	ret = mtdparts_init();
	if (ret)
		return ret;

	ret = find_dev_and_part(partname, &dev, &pnum, &part);
	if (ret)
		return ret;

	*off = part->offset;
	*size = part->size;
	return 0;
}

/* Reset default uboot environment */
int zy_reset_def_env(void)
{
	struct mtd_info *mtd;

	mtd = zy_get_flash_mtd_dev(CONFIG_ENV_MTD_NAME);
	if (IS_ERR(mtd))
		return -1;

	return mtd_erase_env(mtd, CONFIG_ENV_OFFSET, CONFIG_ENV_SIZE);
}

static int flash_part_rw_common(char *part_name, void *buf, size_t offset,
				size_t size, int mode)
{
	int ret = 0;
	void *block_buf = NULL;
	size_t block_size, length;
	uint64_t part_offset, part_size;
	struct mtd_info *mtd;

	mtd = zy_get_flash_mtd_dev(CONFIG_ENV_MTD_NAME);
	if (IS_ERR(mtd))
		return -1;

	block_size = mtd->erasesize;
	if (!mtd->erasesize)
		return -1;
	else
		block_size = mtd->erasesize;

	ret = zy_get_mtd_part_info(part_name, &part_offset, &part_size);
	if (ret)
		return -1;

	if ((offset > part_size) || (size > part_size))
		return -1;

	/* Round up to a multiple of block_size */
	length = (offset + size + block_size - 1) / block_size * block_size;
	block_buf = malloc(length);
	if (!block_buf) {
		printf("alloc memory size 0x%lx failed\n", length);
		ret = -ENOMEM;
		goto done;
	}

	ret = mtd_read_generic(mtd, part_offset, block_buf, length);
	if (ret) {
		printf("partition %s read [%llx-%llx] failed\n",
			part_name, part_offset, part_offset + length - 1);
		ret = -EIO;
		goto done;
	}

	switch (mode) {
		case FLASH_READ:
			memcpy(buf, block_buf + offset, size);
			break;
		case FLASH_WRITE:
			memcpy(block_buf + offset, buf, size);

			ret = mtd_erase_generic(mtd, part_offset, length);
			if (ret) {
				printf("partition %s erase [%llx-%llx] failed\n",
					part_name, part_offset, part_offset + length - 1);
				ret = -EIO;
				goto done;
			}

			ret = mtd_write_generic(mtd, part_offset, 0, block_buf, length, true);
			if (ret) {
				printf("partition %s write [%llx-%llx] failed\n",
					part_name, part_offset, part_offset + length - 1);
				ret = -EIO;
				goto done;
			}
			break;
		default:
			ret = -1;
			goto done;
	}

done:
	if (block_buf)
		free(block_buf);

	return ret;
}

int flash_part_read(char *part_name, void *buf, size_t offset, size_t size)
{
	return flash_part_rw_common(part_name, buf, offset, size, FLASH_READ);
}

int flash_part_write(char *part_name, void *buf, size_t offset, size_t size)
{
	return flash_part_rw_common(part_name, buf, offset, size, FLASH_WRITE);
}

ssize_t mrd_offset_get(void)
{
	struct mtd_info *mtd;

	mtd = zy_get_flash_mtd_dev(CONFIG_ENV_MTD_NAME);
	if (IS_ERR(mtd)) {
		return -1;
	}

	if (!mtd->erasesize)
		return -1;

	return mtd->erasesize - sizeof(MRD);
}

ssize_t mrd_read(MRD *mrd)
{
	ssize_t ret;
	ssize_t mrd_offset;

	ret = mrd_offset = mrd_offset_get();
	if (ret < 0)
		goto done;

	ret = flash_part_read(PART_NAME_MRD, mrd, mrd_offset, sizeof(MRD));

done:
	/* Return a dummy MRD if there are any errors */
	if (ret < 0)
		memcpy(mrd, &dummy_mrd, sizeof(MRD));

	return ret;
}

ssize_t mrd_write(MRD *mrd)
{
	ssize_t mrd_offset;

	mrd_offset = mrd_offset_get();
	if (mrd_offset < 0)
		return -1;

	return flash_part_write(PART_NAME_MRD, mrd, mrd_offset, sizeof(MRD));
}

ssize_t bl2_write(void)
{
	uint32_t data_size = 0;
	uint64_t part_off, part_size;
	struct mtd_info *mtd;
	int ret = -1;

	mtd = zy_get_flash_mtd_dev(CONFIG_ENV_MTD_NAME);
	if (IS_ERR(mtd)) {
		return -1;
	}

	/* Load data to CONFIG_SYS_LOAD_ADDR */
	data_size = net_loop(TFTPGET);
	if ((int) data_size < 0) {
		printf("TFTP client failure: %d\n", data_size);
		goto error;
	}

	zy_get_mtd_part_info(PART_NAME_BL2, &part_off, &part_size);
	if (data_size > part_size) {
		printf("image size: 0x%x over partition size: 0x%llx\n",
				data_size, part_size);
		goto error;
	}

	printf("Loaded %d (0x%x) bytes at 0x%08x \n\n", data_size,
			data_size, CONFIG_SYS_LOAD_ADDR);

	/* Write data */
	ret = flash_part_write(PART_NAME_BL2, (void *)CONFIG_SYS_LOAD_ADDR,
			0, data_size);

error:
	return ret;
}

ssize_t bootloader_write(void)
{
	uint32_t data_size = 0;
	uint64_t part_off, part_size;
	struct mtd_info *mtd;
	int ret = -1;

	mtd = zy_get_flash_mtd_dev(CONFIG_ENV_MTD_NAME);
	if (IS_ERR(mtd)) {
		return -1;
	}

	/* Load data to CONFIG_SYS_LOAD_ADDR */
	data_size = net_loop(TFTPGET);
	if ((int) data_size < 0) {
		printf("TFTP client failure: %d\n", data_size);
		goto error;
	}

	zy_get_mtd_part_info(PART_NAME_BOOTLOADER, &part_off, &part_size);
	if (data_size > part_size) {
		printf("image size: 0x%x over partition size: 0x%llx\n",
				data_size, part_size);
		goto error;
	}

	printf("Loaded %d (0x%x) bytes at 0x%08x \n\n", data_size,
			data_size, CONFIG_SYS_LOAD_ADDR);

	/* Write data */
	ret = flash_part_write(PART_NAME_BOOTLOADER, (void *)CONFIG_SYS_LOAD_ADDR,
			0, data_size);
	if (ret)
		goto error;

	/* Reset default uboot environment */
	ret = zy_reset_def_env();

error:
	return ret;
}

uint16_t model_get(void)
{
	MRD mrd;

	mrd_read(&mrd);

	return get_unaligned_le16(mrd.FeatureBits);
}

int zy_util_init(void)
{
	MRD mrd;

	dumpDualImageInfoFromBootconfig();

	mrd_read(&mrd);

	eng_debug = (mrd.AreaCode > 0) ? 1 : 0;

	return 0;
}
