#include <common.h>
#include <asm/gpio.h> //for gpio_request()
#include <zyxel_util.h> //for zy_util_init()

#define FDT_FAILED_RETURN_VAL 999
#define ZY_PLATFORM_GPIO_FDT_PATH "/zy_platform/zy_platform_gpios"

int zy_gpio_init_from_dt(int offset)
{
	int ret_val;
	unsigned int gpio;

	for (offset = fdt_first_subnode(gd->fdt_blob, offset); offset > 0; offset = fdt_next_subnode(gd->fdt_blob, offset))
	{
		gpio = fdtdec_get_uint(gd->fdt_blob, offset, "pin", FDT_FAILED_RETURN_VAL);
		if (gpio == FDT_FAILED_RETURN_VAL){
			continue;
		}

		/* Request GPIO also set the Mux mode to 0 (normal GPIO mode) */
		ret_val = gpio_request(gpio, "ZY-GPIO-REQUEST");
		if (ret_val != 0) {
			continue;
		}

		ret_val = fdtdec_get_bool(gd->fdt_blob, offset, "input-enable");
		if (ret_val)
			gpio_direction_input(gpio);

		ret_val = fdtdec_get_bool(gd->fdt_blob, offset, "output-low");
		if (ret_val)
			gpio_direction_output(gpio, 0);

		ret_val = fdtdec_get_bool(gd->fdt_blob, offset, "output-high");
		if (ret_val)
			gpio_direction_output(gpio, 1);

#if 0
		/* You can check the request status of all GPIOs by the command "gpio status" if gpio_free() is "not" executed */
		gpio_free(gpio);
#endif
	}

	return 0;
}

/* Init GPIO from device-tree */
int zy_fdt_gpio_init(void)
{
	int node;
	int retval = -1;

	node = fdt_path_offset(gd->fdt_blob, ZY_PLATFORM_GPIO_FDT_PATH);
	if (node >= 0) {
		zy_gpio_init_from_dt(node);
		retval = 0;
	}

	return retval;
}

int zy_gpio_init(void)
{
	int retval = -1;

	/* Init/reset GPIO from device-tree */
	if (zy_fdt_gpio_init() == -1) {
		printf("Error: %s not specified in dts\n", ZY_PLATFORM_GPIO_FDT_PATH);
	} else {
		retval = 0;
	}

	return retval;
}

int zy_init(void)
{
	printf("Zyxel version: %s\n", CONFIG_ZYXEL_VERSION);

	zy_util_init();

	/* Init gpio setting */
	if (zy_gpio_init() == -1)
		printf("Error: %s() init gpio failed\n", __FUNCTION__);

	return 0;
}

/*
 * Go here before auto boot process.
 * CONFIG_LAST_STAGE_INIT must be set in include/config/xxx_defconfig first.
 */
int last_stage_init(void)
{
	zy_init();

	return 0;
}
