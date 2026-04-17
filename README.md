# hardware

## Manufacturer Related Data (MRD)

```
MT7981> atsh
Reading from 0xef80000 to 0x5fb45260, size 0x20000 ... OK
Vendor name           : Zyxel Communications Corp.
Product model         : NWA50AX PRO
System type           : 10
MAC address           : 64dd68e4af98
Default country code  : ed
Boot module debug flag: 0
Hardware version      : Zyxel NWA50AX PRO MT7981
Serial number         : S250Y21048855
SNMP MIB level & OID  : 060102030405060708091011121314151617181920
Main feature bit      : 0
Other feature bits    : e1 80 00 00 00 00 00 00 00 00 88 00 00 00 00 00
                        03 00 00 00 00 00 00 00 00 00 00 00 00 00
MRD recovery flag     : 0
MT7981>
```

TIP: NAND mapping block management => NMBM


## flash

- **Winbond SPI NAND**
- **size: 256 MiB**
- **block size: 128 KiB (0x20000 bytes)**
- **page size: 2048 (0x800 bytes)**
- **OOB size: 128 (0x800 bytes)**

```
MT7981> mtd list
List of MTD devices:
* spi-nand0
  - device: spi_nand@0
  - parent: spi@1100a000
  - driver: spi_nand
  - path: /spi@1100a000/spi_nand@0
  - type: NAND flash
  - block size: 0x20000 bytes
  - min I/O: 0x800 bytes
  - OOB size: 128 bytes
  - OOB available: 56 bytes
  - 0x000000000000-0x000010000000 : "spi-nand0"
* nmbm0
  - type: Unknown
  - block size: 0x20000 bytes
  - min I/O: 0x800 bytes
  - OOB size: 128 bytes
  - OOB available: 56 bytes
  - 0x000000000000-0x00000f000000 : "nmbm0"
          - 0x000000000000-0x000000100000 : "bl2"
          - 0x000000100000-0x000000180000 : "u-boot-env"
          - 0x000000180000-0x000000380000 : "factory"
          - 0x000000380000-0x000000580000 : "fip"
          - 0x000000580000-0x000003780000 : "ubi"
          - 0x000003780000-0x000006980000 : "ubi_1"
          - 0x000006980000-0x00000a580000 : "rootfs_data"
          - 0x00000a580000-0x00000e000000 : "logs"
          - 0x00000e000000-0x00000ef00000 : "myzyxel"
          - 0x00000ef00000-0x00000ef80000 : "bootconfig"
          - 0x00000ef80000-0x00000f000000 : "mrd"
MT7981>
MT7981> nand list
List of NAND devices:
* spi-nand0
  - device: spi_nand@0
  - parent: spi@1100a000
  - driver: spi_nand
  - type: NAND flash
  - block size:        0x20000 bytes
  - page size:         0x800 bytes
  - OOB size:          128 bytes
  - OOB available:     56 bytes
  - 0x000000000000-0x000010000000 : "spi-nand0"
MT7981>
```

## bootlog

```
F0: 102B 0000
FA: 1040 0000
FA: 1040 0000 [0200]
F9: 0000 0000
V0: 0000 0000 [0001]
00: 0000 0000
BP: 2400 0041 [0000]
G0: 1190 0000
EC: 0000 0000 [1000]
T0: 0000 024B [010F]
Jump to BL

NOTICE:  BL2: v2.7(release):645p0c0-49-g10d224bb-dirty
NOTICE:  BL2: Built : 17:12:31, Oct 20 2022
NOTICE:  WDT: disabled
NOTICE:  EMI: Using DDR4 settings

dump toprgu registers data:
1001c000 | 00000000 0000ffe0 00000000 00000000
1001c010 | 00000fff 00000000 00f00000 00000000
1001c020 | 40000000 00000000 00000000 00000000
1001c030 | 003c0003 003c0003 00000000 00000000
1001c040 | 00000000 00000000 00000000 00000000
1001c050 | 00000000 00000000 00000000 00000000
1001c060 | 00000000 00000000 00000000 00000000
1001c070 | 00000000 00000000 00000000 00000000
1001c080 | 00000000 00000000 00000000 00000000

dump drm registers data:
1001d000 | 00000000 00000000 00000000 00000000
1001d010 | 00000000 00000000 00000000 00000000
1001d020 | 00000000 00000000 00000000 00000000
1001d030 | 00a003f1 000000ff 00100000 00000000
1001d040 | 00027e71 000200a0 00020303 000000ff
1001d050 | 00000000 00000000 00000000 00000000
1001d060 | 00000002 00000000 00000000 00000000
drm: 500 = 0xc
[DDR Reserve] ddr reserve mode not be enabled yet
DDR RESERVE Success 0
[EMI] ComboMCP not ready, using default setting
NOTICE:  TREFI = 3.9
BYTE_swap:0
BYTE_swap:0
Window Sum 564, worse bit 2, min window 68
Window Sum 564, worse bit 10, min window 68
[TxChooseVref] Worse bit 8, Min win 24, Win sum 406, Final Vref 40
Window Sum 94, worse bit 7, min window 2
Window Sum 184, worse bit 11, min window 16
Window Sum 154, worse bit 7, min window 8
Window Sum 234, worse bit 11, min window 22
Window Sum 220, worse bit 5, min window 16
Window Sum 276, worse bit 11, min window 30
Window Sum 262, worse bit 5, min window 26
Window Sum 288, worse bit 8, min window 34
Window Sum 292, worse bit 2, min window 34
Window Sum 318, worse bit 11, min window 36
Window Sum 312, worse bit 2, min window 36
Window Sum 336, worse bit 8, min window 40
Window Sum 334, worse bit 2, min window 40
Window Sum 354, worse bit 8, min window 40
Window Sum 356, worse bit 2, min window 42
Window Sum 370, worse bit 8, min window 44
Window Sum 364, worse bit 2, min window 42
Window Sum 392, worse bit 8, min window 46
Window Sum 378, worse bit 2, min window 44
Window Sum 404, worse bit 10, min window 48
Window Sum 390, worse bit 1, min window 48
Window Sum 420, worse bit 11, min window 50
Window Sum 404, worse bit 5, min window 48
Window Sum 410, worse bit 2, min window 50
Window Sum 438, worse bit 8, min window 52
Window Sum 424, worse bit 1, min window 52
Window Sum 440, worse bit 8, min window 54
Window Sum 426, worse bit 2, min window 52
Window Sum 452, worse bit 10, min window 54
Window Sum 432, worse bit 3, min window 52
Window Sum 454, worse bit 10, min window 54
Window Sum 438, worse bit 2, min window 52
Window Sum 442, worse bit 1, min window 54
Window Sum 460, worse bit 10, min window 54
NOTICE:  EMI: Detected DRAM size: 512MB
NOTICE:  EMI: complex R/W mem test passed
NOTICE:  CPU: MT7981 (1300MHz)
NOTICE:  SPI_NAND parses attributes from parameter page.
NOTICE:  SPI_NAND Detected ID 0xef
NOTICE:  Page size 2048, Block size 131072, size 268435456
NOTICE:  Initializing NMBM ...
NOTICE:  Signature found at block 2047 [0x0ffe0000]
NOTICE:  First info table with writecount 0 found in block 1920
NOTICE:  Second info table with writecount 0 found in block 1923
NOTICE:  NMBM has been successfully attached in read-only mode
NOTICE:  BL2: Booting BL31
NOTICE:  BL31: v2.7(release):650p0c0-fake-c0-4-g91e93c1f-dirty
NOTICE:  BL31: Built : 11:05:22, Jan  5 2023
NOTICE:  Hello BL31!!!


U-Boot 2022.07-rc3 (Jan 05 2023 - 11:04:38 +0800)

CPU:   MediaTek MT7981
Model: mt7981-rfb
DRAM:  512 MiB
Core:  38 devices, 16 uclasses, devicetree: embed

Initializing NMBM ...
spi-nand: spi_nand spi_nand@0: Winbond SPI NAND was found.
spi-nand: spi_nand spi_nand@0: 256 MiB, block size: 128 KiB, page size: 2048, OOB size: 128
Could not find a valid device for nmbm0
Signature found at block 2047 [0x0ffe0000]
First info table with writecount 0 found in block 1920
Second info table with writecount 0 found in block 1923
NMBM has been successfully attached

Loading Environment from MTD... *** Warning - bad CRC, using default environment

In:    serial@11002000
Out:   serial@11002000
Err:   serial@11002000
Net:
Warning: ethernet1@15100000 (eth0) using random MAC address - 02:c5:22:60:3c:6c
eth0: ethernet1@15100000
Warning: ethernet@15100000 (eth1) using random MAC address - be:0e:c5:09:a0:32
, eth1: ethernet@15100000
Zyxel version: V1.08
Reading from 0xef00000, size 0x20000
Succeeded
Reading from 0xef80000 to 0x5fb44f10, size 0x20000 ... OK
Autoboot in 2 seconds, press "<Esc><Esc>" to stop
ubi0: attaching mtd6
ubi0: scanning is finished
ubi0: attached mtd6 (name "ubi", size 50 MiB)
ubi0: PEB size: 131072 bytes (128 KiB), LEB size: 126976 bytes
ubi0: min./max. I/O unit sizes: 2048/2048, sub-page size 2048
ubi0: VID header offset: 2048 (aligned 2048), data offset: 4096
ubi0: good PEBs: 400, bad PEBs: 0, corrupted PEBs: 0
ubi0: user volume: 3, internal volumes: 1, max. volumes count: 128
ubi0: max/mean erase counter: 9/7, WL threshold: 4096, image sequence number: 476886840
ubi0: available PEBs: 2, total reserved PEBs: 398, PEBs reserved for bad PEB handling: 38
Reading from volume 'kernel' to 0x46000000, size 0x0 ... OK
## Loading kernel from FIT Image at 46000000 ...
   Using 'config-1' configuration
   Trying 'kernel-1' kernel subimage
     Description:  ARM64 OpenWrt Linux-6.12.71
     Type:         Kernel Image
     Compression:  lzma compressed
     Data Start:   0x460000e8
     Data Size:    4562828 Bytes = 4.4 MiB
     Architecture: AArch64
     OS:           Linux
     Load Address: 0x48000000
     Entry Point:  0x48000000
     Hash algo:    crc32
     Hash value:   73d0296b
     Hash algo:    sha1
     Hash value:   19776bbc7384183bc24d5fbeb98055f6cb258258
   Verifying Hash Integrity ... crc32+ sha1+ OK
## Loading fdt from FIT Image at 46000000 ...
   Using 'config-1' configuration
   Trying 'fdt-1' fdt subimage
     Description:  ARM64 OpenWrt zyxel_nwa50ax-pro device tree blob
     Type:         Flat Device Tree
     Compression:  uncompressed
     Data Start:   0x4645a1b8
     Data Size:    22738 Bytes = 22.2 KiB
     Architecture: AArch64
     Load Address: 0x44000000
     Hash algo:    crc32
     Hash value:   b2cef3a1
     Hash algo:    sha1
     Hash value:   e77723644e40ebf616079b8524ba2ef01ba0fc8b
   Verifying Hash Integrity ... crc32+ sha1+ OK
   Loading fdt from 0x4645a1b8 to 0x44000000
   Booting using the fdt blob at 0x44000000
   Uncompressing Kernel Image
   Loading Device Tree to 000000005f7f2000, end 000000005f7fa8d1 ... OK

Starting kernel ...

[    0.000000] Booting Linux on physical CPU 0x0000000000 [0x410fd034]
[    0.000000] Linux version 6.12.71 (sven@sfr-pc) (aarch64-openwrt-linux-musl-gcc (OpenWrt GCC 14.3.0 r32716-360b1c8d11) 14.3.0, GNU ld (GNU Binutils) 2.44) #0 SMP Thu Mar  5 17:27:01 2026
[    0.000000] Machine model: Zyxel NWA50AX Pro
[    0.000000] earlycon: uart8250 at MMIO32 0x0000000011002000 (options '')
[    0.000000] printk: legacy bootconsole [uart8250] enabled
Press the [f] key and hit [enter] to enter failsafe mode
Press the [1], [2], [3] or [4] key and hit [enter] to select the debug level
```

# u-boot

## tftp boot

```
atna 192.168.1.73
atnf initramfs.bin
atns "192.168.1.254; tftpboot; setenv fdt_high 0xffffffffffffffff; bootm"
```

## fip

* stock fip dts extracted from "/dev/mtd3" ("Factory")

```
/dts-v1/;

/ {
        compatible = "mediatek,mt7981", "mediatek,mt7981-rfb";
        interrupt-parent = <0x01>;
        #address-cells = <0x01>;
        #size-cells = <0x01>;
        model = "mt7981-rfb";

        cpus {
                #address-cells = <0x01>;
                #size-cells = <0x00>;

                cpu@0 {
                        device_type = "cpu";
                        compatible = "arm,cortex-a53";
                        reg = <0x00>;
                };

                cpu@1 {
                        device_type = "cpu";
                        compatible = "arm,cortex-a53";
                        reg = <0x01>;
                };
        };

        gpt_dummy20m {
                compatible = "fixed-clock";
                clock-frequency = <0xc65d40>;
                #clock-cells = <0x00>;
                u-boot,dm-pre-reloc;
                phandle = <0x02>;
        };

        timer {
                compatible = "arm,armv8-timer";
                interrupt-parent = <0x01>;
                clock-frequency = <0xc65d40>;
                interrupts = <0x01 0x0d 0x08 0x01 0x0e 0x08 0x01 0x0b 0x08 0x01 0x0a 0x08>;
                arm,cpu-registers-not-fw-configured;
        };

        timer@10008000 {
                compatible = "mediatek,mt7986-timer";
                reg = <0x10008000 0x1000>;
                interrupts = <0x00 0x82 0x04>;
                clocks = <0x02>;
                clock-names = "gpt-clk";
                u-boot,dm-pre-reloc;
        };

        watchdog@1001c000 {
                compatible = "mediatek,mt7986-wdt";
                reg = <0x1001c000 0x1000>;
                interrupts = <0x00 0x6e 0x04>;
                #reset-cells = <0x01>;
                status = "disabled";
        };

        interrupt-controller@c000000 {
                compatible = "arm,gic-v3";
                #interrupt-cells = <0x03>;
                interrupt-parent = <0x01>;
                interrupt-controller;
                reg = <0xc000000 0x40000 0xc080000 0x200000>;
                interrupts = <0x01 0x09 0x04>;
                phandle = <0x01>;
        };

        apmixedsys@1001e000 {
                compatible = "mediatek,mt7981-fixed-plls";
                reg = <0x1001e000 0x1000>;
                #clock-cells = <0x01>;
                u-boot,dm-pre-reloc;
                phandle = <0x03>;
        };

        topckgen@1001b000 {
                compatible = "mediatek,mt7981-topckgen";
                reg = <0x1001b000 0x1000>;
                clock-parent = <0x03>;
                #clock-cells = <0x01>;
                u-boot,dm-pre-reloc;
                phandle = <0x05>;
        };

        infracfg_ao@10001000 {
                compatible = "mediatek,mt7981-infracfg_ao";
                reg = <0x10001000 0x80>;
                clock-parent = <0x04>;
                #clock-cells = <0x01>;
                u-boot,dm-pre-reloc;
                phandle = <0x06>;
        };

        infracfg@10001000 {
                compatible = "mediatek,mt7981-infracfg";
                reg = <0x10001000 0x30>;
                clock-parent = <0x05>;
                #clock-cells = <0x01>;
                u-boot,dm-pre-reloc;
                phandle = <0x04>;
        };

        pinctrl@11d00000 {
                compatible = "mediatek,mt7981-pinctrl";
                reg = <0x11d00000 0x1000 0x11c00000 0x1000 0x11c10000 0x1000 0x11d20000 0x1000 0x11e00000 0x1000 0x11e20000 0x1000 0x11f00000 0x1000 0x11f10000 0x1000 0x1000b000 0x1000>;
                reg-names = "gpio_base", "iocfg_rt_base", "iocfg_rm_base", "iocfg_rb_base", "iocfg_lb_base", "iocfg_bl_base", "iocfg_tm_base", "iocfg_tl_base", "eint";

                gpio-controller {
                        gpio-controller;
                        #gpio-cells = <0x02>;
                        phandle = <0x0b>;
                };

                spi0-pins-func-1 {
                        phandle = <0x0e>;

                        mux {
                                function = "flash";
                                groups = "spi0", "spi0_wp_hold";
                        };

                        conf-pu {
                                pins = "SPI0_CS", "SPI0_HOLD", "SPI0_WP";
                                drive-strength = <0x08>;
                                bias-pull-up = <0x67>;
                        };

                        conf-pd {
                                pins = "SPI0_CLK", "SPI0_MOSI", "SPI0_MISO";
                                drive-strength = <0x08>;
                                bias-pull-down = <0x67>;
                        };
                };

                spi1-pins-func-1 {

                        mux {
                                function = "spi";
                                groups = "spi1_1";
                        };
                };

                spi1-pins-func-3 {
                        phandle = <0x08>;

                        mux {
                                function = "uart";
                                groups = "uart1_2";
                        };
                };

                one-pwm-pins {

                        mux {
                                function = "pwm";
                                groups = "pwm0_1";
                        };
                };

                two-pwm-pins {
                        phandle = <0x07>;

                        mux {
                                function = "pwm";
                                groups = "pwm0_1", "pwm1_0";
                        };
                };

                three-pwm-pins {

                        mux {
                                function = "pwm";
                                groups = "pwm0_1", "pwm1_0", "pwm2";
                        };
                };
        };

        pwm@10048000 {
                compatible = "mediatek,mt7981-pwm";
                reg = <0x10048000 0x1000>;
                #clock-cells = <0x01>;
                #pwm-cells = <0x02>;
                interrupts = <0x00 0x89 0x04>;
                clocks = <0x04 0x05 0x06 0x2d 0x06 0x03 0x06 0x04 0x06 0x04>;
                assigned-clocks = <0x05 0x51>;
                assigned-clock-parents = <0x05 0x00>;
                clock-names = "top", "main", "pwm1", "pwm2", "pwm3";
                status = "okay";
                pinctrl-names = "default";
                pinctrl-0 = <0x07>;
        };

        serial@11002000 {
                compatible = "mediatek,hsuart";
                reg = <0x11002000 0x400>;
                interrupts = <0x00 0x7b 0x04>;
                clocks = <0x06 0x12>;
                assigned-clocks = <0x05 0x50 0x06 0x25>;
                assigned-clock-parents = <0x05 0x00 0x04 0x01>;
                mediatek,force-highspeed;
                status = "okay";
                u-boot,dm-pre-reloc;
        };

        serial@11003000 {
                compatible = "mediatek,hsuart";
                reg = <0x11003000 0x400>;
                interrupts = <0x00 0x7c 0x04>;
                clocks = <0x06 0x13>;
                assigned-clocks = <0x05 0x50 0x06 0x26>;
                assigned-clock-parents = <0x05 0x00 0x04 0x01>;
                mediatek,force-highspeed;
                status = "disabled";
                pinctrl-names = "default";
                pinctrl-0 = <0x08>;
        };

        serial@11004000 {
                compatible = "mediatek,hsuart";
                reg = <0x11004000 0x400>;
                interrupts = <0x00 0x7c 0x04>;
                clocks = <0x06 0x14>;
                assigned-clocks = <0x05 0x50 0x06 0x27>;
                assigned-clock-parents = <0x05 0x00 0x04 0x01>;
                mediatek,force-highspeed;
                status = "disabled";
        };

        snand@11005000 {
                compatible = "mediatek,mt7986-snand";
                reg = <0x11005000 0x1000 0x11006000 0x1000>;
                reg-names = "nfi", "ecc";
                clocks = <0x06 0x18 0x06 0x17 0x06 0x19>;
                clock-names = "pad_clk", "nfi_clk", "nfi_hclk";
                assigned-clocks = <0x05 0x4d 0x05 0x4c>;
                assigned-clock-parents = <0x05 0x06 0x05 0x06>;
                status = "disabled";
        };

        syscon@15000000 {
                compatible = "mediatek,mt7981-ethsys", "syscon";
                reg = <0x15000000 0x1000>;
                clock-parent = <0x05>;
                #clock-cells = <0x01>;
                #reset-cells = <0x01>;
                phandle = <0x09>;
        };

        ethernet1@15100000 {
                compatible = "mediatek,mt7981-eth", "syscon";
                reg = <0x15100000 0x80000>;
                resets = <0x09 0x06>;
                reset-names = "fe";
                mediatek,ethsys = <0x09>;
                mediatek,sgmiisys = <0x0a>;
                #address-cells = <0x01>;
                #size-cells = <0x00>;
                status = "okay";
                mediatek,gmac-id = <0x01>;
                phy-mode = "sgmii";
                reset-gpios = <0x0b 0x0c 0x00>;
                reset-assert-us = <0x258>;
                reset-deassert-us = <0x4e20>;
                phy-handle = <0x0c>;

                eth-phy@5 {
                        reg = <0x05>;
                        phy-mode = "sgmii";
                        phandle = <0x0c>;
                };

                fixed-link {
                        speed = <0x3e8>;
                        full-duplex;
                };
        };

        ethernet@15100000 {
                compatible = "mediatek,mt7981-eth", "syscon";
                reg = <0x15100000 0x20000>;
                resets = <0x09 0x06>;
                reset-names = "fe";
                mediatek,ethsys = <0x09>;
                mediatek,sgmiisys = <0x0d>;
                #address-cells = <0x01>;
                #size-cells = <0x00>;
                status = "okay";
                mediatek,gmac-id = <0x00>;
                phy-mode = "sgmii";
                mediatek,switch = "mt7531";
                reset-gpios = <0x0b 0x27 0x00>;

                fixed-link {
                        speed = <0x3e8>;
                        full-duplex;
                };
        };

        syscon@10060000 {
                compatible = "mediatek,mt7986-sgmiisys", "syscon";
                reg = <0x10060000 0x1000>;
                pn_swap;
                #clock-cells = <0x01>;
                phandle = <0x0d>;
        };

        syscon@10070000 {
                compatible = "mediatek,mt7986-sgmiisys", "syscon";
                reg = <0x10070000 0x1000>;
                #clock-cells = <0x01>;
                phandle = <0x0a>;
        };

        spi@1100a000 {
                compatible = "mediatek,ipm-spi";
                reg = <0x1100a000 0x100>;
                clocks = <0x06 0x1a 0x05 0x4e>;
                assigned-clocks = <0x05 0x4e 0x04 0x28>;
                assigned-clock-parents = <0x05 0x02 0x05 0x02>;
                clock-names = "sel-clk", "spi-clk";
                interrupts = <0x00 0x8c 0x04>;
                status = "okay";
                #address-cells = <0x01>;
                #size-cells = <0x00>;
                pinctrl-names = "default";
                pinctrl-0 = <0x0e>;
                must_tx;
                enhance_timing;
                dma_ext;
                ipm_design;
                support_quad;
                tick_dly = <0x02>;
                sample_sel = <0x00>;

                spi_nand@0 {
                        compatible = "spi-nand";
                        reg = <0x00>;
                        spi-max-frequency = <0x3197500>;
                };
        };

        spi@1100b000 {
                compatible = "mediatek,ipm-spi";
                reg = <0x1100b000 0x100>;
                interrupts = <0x00 0x8d 0x04>;
                status = "disabled";
        };

        spi@11009000 {
                compatible = "mediatek,ipm-spi";
                reg = <0x11009000 0x100>;
                clocks = <0x06 0x1a 0x05 0x4e>;
                assigned-clocks = <0x05 0x4e 0x04 0x28>;
                assigned-clock-parents = <0x05 0x02 0x05 0x02>;
                clock-names = "sel-clk", "spi-clk";
                interrupts = <0x00 0x8e 0x04>;
                status = "disabled";
        };

        mmc@11230000 {
                compatible = "mediatek,mt7981-mmc";
                reg = <0x11230000 0x1000 0x11c20000 0x1000>;
                interrupts = <0x00 0x8f 0x04>;
                clocks = <0x05 0x34 0x05 0x33 0x06 0x1f>;
                assigned-clocks = <0x05 0x55 0x05 0x54>;
                assigned-clock-parents = <0x05 0x1c 0x05 0x02>;
                clock-names = "source", "hclk", "source_cg";
                status = "disabled";
        };

        chosen {
                stdout-path = "/serial@11002000";
                tick-timer = "/timer@10008000";
        };

        memory@40000000 {
                device_type = "memory";
                reg = <0x40000000 0x20000000>;
        };

        zy_platform {

                zy_platform_gpios {

                        btn_rst_mb {
                                pin = <0x01>;
                                input-enable;
                        };

                        led_power {
                                pin = <0x04>;
                                output-high;
                        };

                        poe_status {
                                pin = <0x05>;
                                input-enable;
                        };

                        led_mgmt {
                                pin = <0x06>;
                                output-low;
                        };

                        led_sys {
                                pin = <0x07>;
                                output-low;
                        };

                        rst_mb {
                                pin = <0x09>;
                                output-high;
                        };

                        apd_dc_in {
                                pin = <0x0a>;
                                input-enable;
                        };

                        board_info_1 {
                                pin = <0x22>;
                                input-enable;
                        };

                        board_info_2 {
                                pin = <0x23>;
                                input-enable;
                        };
                };
        };
};
```

* zyxel dt node "zy_platform"

board/mediatek/common/zy_init.c:
```
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
```

see: https://docs.u-boot.org/en/latest/usage/cmd/gpio.html

* "input-enable" => gpio_direction_input(gpio); => u-boot cli: 'gpio input <gpio>'
* "output-low"   => gpio_direction_output(gpio, 0); => u-boot cli: 'gpio clear <gpio>'
* "output-high"  => gpio_direction_output(gpio, 1); => u-boot cli: 'gpio set <gpio>')

```
MT7981> gpio status
Bank mt7981_pinctrl:
mt7981_pinctrl1: input: 1 [x] ZY-GPIO-REQUEST
mt7981_pinctrl4: output: 1 [x] ZY-GPIO-REQUEST
mt7981_pinctrl5: input: 1 [x] ZY-GPIO-REQUEST
mt7981_pinctrl6: output: 0 [x] ZY-GPIO-REQUEST
mt7981_pinctrl7: output: 0 [x] ZY-GPIO-REQUEST
mt7981_pinctrl9: output: 1 [x] ZY-GPIO-REQUEST
mt7981_pinctrl10: input: 1 [x] ZY-GPIO-REQUEST
mt7981_pinctrl12: output: 1 [x] ethernet1@15100000.reset-gpios
mt7981_pinctrl34: input: 0 [x] ZY-GPIO-REQUEST
mt7981_pinctrl35: input: 0 [x] ZY-GPIO-REQUEST
mt7981_pinctrl39: output: 1 [x] ethernet@15100000.reset-gpios
MT7981>
MT7981>
MT7981> gpio toggle mt7981_pinctrl7
gpio: pin mt7981_pinctrl7 (gpio 7) value is 1
MT7981> gpio toggle mt7981_pinctrl7
gpio: pin mt7981_pinctrl7 (gpio 7) value is 0
MT7981> gpio toggle mt7981_pinctrl7
gpio: pin mt7981_pinctrl7 (gpio 7) value is 1
MT7981> gpio toggle mt7981_pinctrl7
gpio: pin mt7981_pinctrl7 (gpio 7) value is 0
MT7981> gpio toggle mt7981_pinctrl6
gpio: pin mt7981_pinctrl6 (gpio 6) value is 1
MT7981> gpio toggle mt7981_pinctrl7
gpio: pin mt7981_pinctrl7 (gpio 7) value is 1
MT7981> gpio toggle mt7981_pinctrl7
gpio: pin mt7981_pinctrl7 (gpio 7) value is 0
MT7981> gpio toggle mt7981_pinctrl6
gpio: pin mt7981_pinctrl6 (gpio 6) value is 0
MT798gpio toggle mt7981_pinctrl4
gpio: pin mt7981_pinctrl4 (gpio 4) value is 0
MT7981> gpio toggle mt7981_pinctrl4
gpio: pin mt7981_pinctrl4 (gpio 4) value is 1
MT7981> gpio toggle mt7981_pinctrl4
gpio: pin mt7981_pinctrl4 (gpio 4) value is 0
MT7981> gpio toggle mt7981_pinctrl4
gpio: pin mt7981_pinctrl4 (gpio 4) value is 1
MT7981> gpio set mt7981_pinctrl4
gpio: pin mt7981_pinctrl4 (gpio 4) value is 1
MT7981> gpio toogle mt7981_pinctrl12
gpio: pin mt7981_pinctrl12 (gpio 12) value is 0
MT7981> gpio toogle mt7981_pinctrl12
gpio: pin mt7981_pinctrl12 (gpio 12) value is 1
MT7981>
MT7981>
MT7981>
MT7981> gpio toogle mt7981_pinctrl12
gpio: pin mt7981_pinctrl12 (gpio 12) value is 0
MT7981> gpio toogle mt7981_pinctrl12
gpio: pin mt7981_pinctrl12 (gpio 12) value is 1
MT7981> gpio toogle mt7981_pinctrl39
gpio: pin mt7981_pinctrl39 (gpio 39) value is 0
MT7981>
```

* gpio usage

| pin | state | name | function |
| --- | --- | --- | --- |
| mt7981_pinctrl1 | input 1 | btn_rst_mb | reset button |
| mt7981_pinctrl4 | output 1 | led_power | toogle => 0 (system led: off), 1 (system led: green) |
| mt7981_pinctrl5 | input 1 | poe_status | poe pse status |
| mt7981_pinctrl6 |  output 0 | led_mgmt | toogle => 0 (system led: green), 1 (system led: blue) |
| mt7981_pinctrl7 |  output 0 | led_sys | toogle => 0 (system led: green), 1 (system led: orange) |
| mt7981_pinctrl9 | output 1 | rst_mb | unknow => reset mainboard |
| mt7981_pinctrl10 | input 1 | apd_dc_in | external powersupply status |
| mt7981_pinctrl12 | output 1 | ethernet1@15100000.reset-gpios | toogle => 0 (eth0 down), 1 (eth0 up) |
| mt7981_pinctrl34 | input 0 | board_info_1 | unknown |
| mt7981_pinctrl35 | input 0 | board_info_2 | unknown |
| mt7981_pinctrl39 | output 1 | ethernet@15100000.reset-gpios | no function |

## u-boot commands - zyxel

### privileged mode

* enable priv mode on "mrd" partition

=> read offset "0x1fffff" from "mrd" parition (0x00 )

- "0000": on privileged mode
- "0001": privileged mode

```
# dd if=/dev/mtd10 bs=1 skip=$((0x1ffff)) count=1 conv=notrunc 2>/dev/null | hexdump
0000000 0000
0000001
```

=> write "0x1" to offset "0x1fffff" from "mrd" parition

```
# insmod mtd-rw i_want_a_brick=1
# printf '\x01' | dd of=mtd10_mrd.img bs=1 seek=$((0x1ffff)) conv=notrunc
[..]
# dd if=/dev/mtd10 bs=1 skip=$((0x1ffff)) count=1 conv=notrunc 2>/dev/null | hexdump
0000000 0001
0000001
# rmmod mtd-rw
```

=> set "AreaCode" to 0x01 ("Boot module debug flag")

[..]
0001fff0  00 00 00 00 00 00 00 ff  64 dd 68 e4 af 98 ed **01**  |........d.h.....|
[..]

```
# hexdump -C /dev/mtd10
00000000  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
0001ff00  00 00 00 00 00 00 00 00  00 00 00 00 00 53 49 47  |.............SIG|
0001ff10  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
*
0001ff30  5a 79 78 65 6c 20 4e 57  41 35 30 41 58 20 50 52  |Zyxel NWA50AX PR|
0001ff40  4f 20 4d 54 37 39 38 31  00 00 00 00 00 00 00 00  |O MT7981........|
0001ff50  53 32 35 30 59 32 31 30  34 38 38 35 35 00 30 39  |S250Y21048855.09|
0001ff60  2d 30 31 31 30 30 31 41  41 00 00 00 00 00 00 00  |-011001AA.......|
0001ff70  00 00 06 01 02 03 04 05  06 07 08 09 10 11 12 13  |................|
0001ff80  14 15 16 17 18 19 20 00  00 02 00 00 00 10 00 00  |...... .........|
0001ff90  5a 79 78 65 6c 20 43 6f  6d 6d 75 6e 69 63 61 74  |Zyxel Communicat|
0001ffa0  69 6f 6e 73 20 43 6f 72  70 2e 00 00 00 00 00 00  |ions Corp.......|
0001ffb0  4e 57 41 35 30 41 58 20  50 52 4f 00 00 00 00 00  |NWA50AX PRO.....|
0001ffc0  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
0001ffd0  00 00 00 00 ff ff 0a ff  e1 80 00 00 00 00 00 00  |................|
0001ffe0  00 00 88 00 00 00 00 00  03 00 00 00 00 00 00 00  |................|
0001fff0  00 00 00 00 00 00 00 ff  64 dd 68 e4 af 98 ed 01  |........d.h.....|
00020000  ff ff ff ff ff ff ff ff  ff ff ff ff ff ff ff ff  |................|
*
00080000
#
```

* enable PRIVILEGED_MODE 

MRD Partition Content

u-boot/include/zyxel_util.h:
```
[..]
/* Manufacturer Related Data */
typedef struct mrd {
   uint8_t BspHeapBlkSize[16];
   uint8_t BspHeapBlkCnt[16];
   uint8_t HardwareVersion[32];
   uint8_t SerialNumber[32];
   uint8_t Reserved0[32];
   uint8_t VendorName[32];
   uint8_t ProductName[32];
   uint32_t Reserved4;
   uint16_t Reserved1;
   uint8_t SystemType;
   uint8_t Reserved2;
   uint8_t FeatureBits[30]; /* Other Feature Bits */
   uint8_t FeatureBit; /* Main Feature Bits */
   uint8_t Reserved3;
   uint8_t EtherAddr[6];
   uint8_t CountryCode;
   uint8_t AreaCode;
} __attribute__((__packed__)) MRD;
[..]
```

u-boot/board/mediatek/common/zyxel_util.c:
```
[..]
int zy_util_init(void)
{
   MRD mrd;

   dumpDualImageInfoFromBootconfig();

   mrd_read(&mrd);

   eng_debug = (mrd.AreaCode > 0) ? 1 : 0;

   return 0;
}
[..]
```

board/mediatek/common/load_data.c:
```
[..]
static int env_read_cli_set(const char *varname, const char *defval,
               const char *prompt, char *buffer, size_t bufsz)
{
   [..]
   if (eng_debug)
       flag |= FLAG_PRIVILEGED_MODE;
   return cmd_process(flag, 4, argv, &repeatable, NULL);
}
[..]
```

u-boot/common/cli_hush.c:
```
[..]
   flag = FLAG_PARSE_SEMICOLON;
   if (eng_debug)
       flag |= FLAG_PRIVILEGED_MODE;
   rcode = parse_stream_outer(&input, flag);
[..]
```

=> **Boot module debug flag: 1**

```
MT7981> atsh
Reading from 0xef80000 to 0x5fb45260, size 0x20000 ... OK
Vendor name           : Zyxel Communications Corp.
Product model         : NWA50AX PRO
System type           : 10
MAC address           : 64dd68e4af98
Default country code  : ed
Boot module debug flag: 1
Hardware version      : Zyxel NWA50AX PRO MT7981
Serial number         : S250Y21048855
SNMP MIB level & OID  : 060102030405060708091011121314151617181920
Main feature bit      : 0
Other feature bits    : e1 80 00 00 00 00 00 00 00 00 88 00 00 00 00 00
                        03 00 00 00 00 00 00 00 00 00 00 00 00 00
MRD recovery flag     : 0
MT7981>
```

* all commands

```
MT7981> help
?         - alias for 'help'
at        - print OK
atbl      - Upload and program bl2 (bl2.img) via tftp.
atds      - show dual image info
atgo      - boot
athe      - show available commands
atna      - set board IP for tftp
atnb      - Upload and program bootloader (fip.bin) via tftp.
atnf      - set filename for tftp
atns      - set server IP for tftp
atnx      - do full firmware update via tftp
atnz      - do firmware update via tftp
atsh      - dump Manufacturer Related Data (MRD)
atsr      - reboot
atwe      - write MAC address
base      - print or set address offset
bdinfo    - print Board Info structure
blkcache  - block cache diagnostics and control
boot      - boot default, i.e., run 'bootcmd'
bootd     - boot default, i.e., run 'bootcmd'
bootefi   - Boots an EFI payload from memory
bootelf   - Boot from an ELF image in memory
bootflow  - Boot flows
booti     - boot Linux kernel 'Image' format from memory
bootm     - boot application image from memory
bootmenu  - ANSI terminal bootmenu
bootp     - boot image via network using BOOTP/TFTP protocol
bootvx    - Boot vxWorks from an ELF image
chpart    - change active partition of a MTD device
cmp       - memory compare
coninfo   - print console devices and information
cp        - memory copy
crc32     - checksum calculation
echo      - echo args to console
editenv   - edit environment variable
env       - environment handling commands
erase     - erase FLASH memory
exit      - exit script
false     - do nothing, unsuccessfully
fdt       - flattened device tree utility commands
flinfo    - print FLASH memory information
go        - start application at address 'addr'
gpio      - query and control gpio pins
gzwrite   - unzip and write memory to block device
help      - print command description/usage
iminfo    - print header information for application image
imxtract  - extract a part of a multi-image
itest     - return true/false on integer compare
loadb     - load binary file over serial line (kermit mode)
loads     - load S-Record file over serial line
loadx     - load binary file over serial line (xmodem mode)
loady     - load binary file over serial line (ymodem mode)
loop      - infinite loop on address range
lzmadec   - lzma uncompress a memory region
md        - memory display
mm        - memory modify (auto-incrementing address)
mtd       - MTD utils
mtdparts  - define flash/nand partitions
mtkautoboot- Display MediaTek bootmenu
mtkboardboot- Boot MTK firmware
mtkload   - MTK image loading utility
mtkupgrade- MTK firmware/bootloader upgrading utility
mw        - memory write (fill)
nand      - NAND utility
net       - NET sub-system
nfs       - boot image via network using NFS protocol
nm        - memory modify (constant address)
nmbm      - NMBM utility commands
panic     - Panic with optional message
ping      - send ICMP ECHO_REQUEST to network host
pinmux    - show pin-controller muxing
printenv  - print environment variables
protect   - enable or disable FLASH write protection
pwm       - control pwm channels
random    - fill memory with random pattern
reset     - Perform RESET of the CPU
run       - run commands in an environment variable
saveenv   - save environment variables to persistent storage
setenv    - set environment variables
setexpr   - set environment variable as the result of eval expression
sf        - SPI flash sub-system
showvar   - print local hushshell variables
sleep     - delay execution for some time
smc       - Issue a Secure Monitor Call
source    - run script from memory
test      - minimal test like /bin/sh
tftpboot  - boot image via network using TFTP protocol
true      - do nothing, successfully
unlz4     - lz4 uncompress a memory region
unzip     - unzip a memory region
version   - print monitor, compiler and linker version
MT7981>
```

* env

```
MT7981> printenv
baudrate=115200
bootargs=console=ttyS0,115200n1 earlycon=uart8250,mmio32,0x11002000 loglevel=1
bootcmd=atgo
bootdelay=2
bootfile=ZLD-current
eth1addr=ee:fc:44:57:6d:9e
ethaddr=16:96:4f:ac:96:ee
fdtcontroladdr=5ffc1b10
ipaddr=192.168.1.2
loadaddr=0x46000000
mtddevname=bl2
mtddevnum=0
mtdids=nmbm0=nmbm0
mtdparts=nmbm0:1m(bl2),512k(u-boot-env),2m(factory),2m(fip),50m(ubi),50m(ubi_1),60m(rootfs_data),59904k(logs),15m(myzyxel),512k(bootconfig),512k(mrd)
netmask=255.255.255.0
partition=nmbm0,0
serverip=192.168.1.103
stderr=serial@11002000
stdin=serial@11002000
stdout=serial@11002000

Environment size: 585/131068 bytes
MT7981>
```

* misc

```
MT7981> net list
eth0 : ethernet1@15100000 16:96:4f:ac:96:ee active
eth1 : ethernet@15100000 ee:fc:44:57:6d:9e
MT7981>
MT7981> bdinfo
boot_params = 0x0000000040000100
DRAM bank   = 0x0000000000000000
-> start    = 0x0000000040000000
-> size     = 0x0000000020000000
flashstart  = 0x0000000000000000
flashsize   = 0x0000000000000000
flashoffset = 0x0000000000000000
baudrate    = 115200 bps
relocaddr   = 0x000000005ff32000
reloc off   = 0x000000001e132000
Build       = 64-bit
current eth = ethernet1@15100000
ethaddr     = 16:96:4f:ac:96:ee
IP addr     = 192.168.1.2
fdt_blob    = 0x000000005ffc1b10
new_fdt     = 0x0000000000000000
fdt_size    = 0x0000000000000000
lmb_dump_all:
 memory.cnt  = 0x1
 memory[0]      [0x40000000-0x5fffffff], 0x20000000 bytes flags: 0
 reserved.cnt  = 0x1
 reserved[0]    [0x5f7fb920-0x5fffffff], 0x008046e0 bytes flags: 0
devicetree  = embed
arch_number = 0x0000000000000000
TLB addr    = 0x000000005fff0000
irq_sp      = 0x000000005f7ffd80
sp start    = 0x000000005f7ffd80
Early malloc usage: 6c8 / 4000
MT7981>
```

## u-boot config - zyxel

710p4c0_nwa50ax_pro/src/u-boot/Makefile:
```
VERSION = 2022
PATCHLEVEL = 07
SUBLEVEL =
EXTRAVERSION = -rc3
```

710p4c0_nwa50ax_pro/src/u-boot/configs/mt7981_spim_nand_rfb_defconfig:
```
CONFIG_ARCH_MEDIATEK=y
CONFIG_ARM=y
CONFIG_AUTOBOOT_KEYED_CTRLC=y
CONFIG_AUTOBOOT_KEYED=y
CONFIG_AUTOBOOT_PROMPT="Autoboot in %d seconds, press \"<Esc><Esc>\" to stop\n"
CONFIG_AUTOBOOT_STOP_STR="\x1b\x1b"
CONFIG_BLK=y
CONFIG_BOOTARGS="console=ttyS0,115200n1 earlycon=uart8250,mmio32,0x11002000 loglevel=1"
CONFIG_BOOTCOMMAND="atgo"
CONFIG_BOOTFILE="ZLD-current"
CONFIG_CLK=y

CONFIG_CMD_GPIO=y
CONFIG_CMD_MTDPARTS=y
CONFIG_CMD_MTD=y
CONFIG_CMD_NMBM=y
CONFIG_CMD_PING=y
CONFIG_CMD_PWM=y
CONFIG_CMD_SF_TEST=y
CONFIG_CMD_SMC=y

CONFIG_DEBUG_UART_BASE=0x11002000
CONFIG_DEBUG_UART_CLOCK=40000000
CONFIG_DEBUG_UART=y
CONFIG_DEFAULT_DEVICE_TREE="mt7981-spim-nand-rfb"
CONFIG_DEFAULT_FDT_FILE="mt7981-spim-nand-rfb"
CONFIG_DM_ETH=y
CONFIG_DM_MTD=y
CONFIG_DM_PWM=y
CONFIG_DM_SERIAL=y
CONFIG_DM_SPI_FLASH=y
CONFIG_DM_SPI=y
CONFIG_ENABLE_NAND_NMBM=y
CONFIG_ENV_IS_IN_MTD=y
CONFIG_ENV_MTD_NAME="nmbm0"
CONFIG_ENV_OFFSET=0x100000
CONFIG_ENV_OVERWRITE=y
CONFIG_ENV_SIZE=0x20000
CONFIG_ENV_SIZE_REDUND=0x80000
CONFIG_ENV_VARS_UBOOT_RUNTIME_CONFIG=y
CONFIG_HEXDUMP=y
CONFIG_HUSH_PARSER=y

# [zyxel] => u-boot/board/mediatek/common/zy_init.c last_stage_init() => zy_init() => fip dts (zy_platform { .. GPIOs .. })
CONFIG_LAST_STAGE_INIT=y

CONFIG_LOGLEVEL=7
CONFIG_LOG=y
CONFIG_LZO=y
CONFIG_MEDIATEK_BOOTMENU=y
CONFIG_MEDIATEK_ETH=y
CONFIG_MEDIATEK_LOAD_FROM_RAM=y
# CONFIG_MMC is not set
CONFIG_MT7981_BOOTMENU_UBI=y
CONFIG_MTDIDS_DEFAULT="nmbm0=nmbm0"
CONFIG_MTDPARTS_DEFAULT="nmbm0:1m(bl2),512k(u-boot-env),2m(factory),2m(fip),50m(ubi),50m(ubi_1),60m(rootfs_data),59904k(logs),15m(myzyxel),512k(bootconfig),512k(mrd)"
CONFIG_MTD_SPI_NAND=y
CONFIG_MTK_POWER_DOMAIN=y
CONFIG_MTK_SERIAL=y
CONFIG_MTK_SPIM=y
CONFIG_MTK_TIMER=y
CONFIG_NET_RANDOM_ETHADDR=y
CONFIG_NR_DRAM_BANKS=1
CONFIG_OF_EMBED=y
CONFIG_PHY_FIXED=y
CONFIG_PINCONF=y
CONFIG_PINCTRL_MT7981=y
CONFIG_PINCTRL=y
CONFIG_POSITION_INDEPENDENT=y
CONFIG_POWER_DOMAIN=y
CONFIG_PWM_MTK=y
CONFIG_RAM=y
CONFIG_REGMAP=y
CONFIG_SPI_FLASH_EON=y
CONFIG_SPI_FLASH_GIGADEVICE=y
CONFIG_SPI_FLASH_ISSI=y
CONFIG_SPI_FLASH_MACRONIX=y
CONFIG_SPI_FLASH_SPANSION=y
CONFIG_SPI_FLASH_STMICRO=y
CONFIG_SPI_FLASH_WINBOND=y
CONFIG_SPI=y
CONFIG_SYSCON=y
CONFIG_SYS_I2C_MTK=y
CONFIG_SYS_LOAD_ADDR=0x46000000
CONFIG_SYS_MALLOC_F_LEN=0x4000
CONFIG_SYS_PROMPT="MT7981> "
CONFIG_SYS_STDIO_DEREGISTER=y
CONFIG_SYS_TEXT_BASE=0x41e00000
CONFIG_TARGET_MT7981=y
CONFIG_TIMER=y
CONFIG_USE_BOOTARGS=y
CONFIG_USE_BOOTCOMMAND=y
CONFIG_USE_BOOTFILE=y
CONFIG_ZYXEL_VERSION="V1.09"
```

710p4c0_nwa50ax_pro/src/u-boot/arch/arm/dts $ cat mt7981-spim-nand-rfb.dts:
```
// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (c) 2021 MediaTek Inc.
 * Author: Sam Shih <sam.shih@mediatek.com>
 */

/dts-v1/;
#include "mt7981.dtsi"
#include <dt-bindings/gpio/gpio.h>

/ {
        #address-cells = <1>;
        #size-cells = <1>;
        model = "mt7981-rfb";
        compatible = "mediatek,mt7981", "mediatek,mt7981-rfb";
        chosen {
                stdout-path = &uart0;
                tick-timer = &timer0;
        };

        memory@40000000 {
                device_type = "memory";
                reg = <0x40000000 0x10000000>;
        };
};

&uart0 {
        status = "okay";
};

&uart1 {
        pinctrl-names = "default";
        pinctrl-0 = <&uart1_pins>;
        status = "disabled";
};

&eth {
        status = "okay";
        mediatek,gmac-id = <0>;
        phy-mode = "sgmii";
        mediatek,switch = "mt7531";
        reset-gpios = <&gpio 39 GPIO_ACTIVE_HIGH>;

        fixed-link {
                speed = <1000>;
                full-duplex;
        };
};

&pinctrl {
        spi_flash_pins: spi0-pins-func-1 {
                mux {
                        function = "flash";
                        groups = "spi0", "spi0_wp_hold";
                };

                conf-pu {
                        pins = "SPI0_CS", "SPI0_HOLD", "SPI0_WP";
                        drive-strength = <MTK_DRIVE_8mA>;
                        bias-pull-up = <MTK_PUPD_SET_R1R0_11>;
                };

                conf-pd {
                        pins = "SPI0_CLK", "SPI0_MOSI", "SPI0_MISO";
                        drive-strength = <MTK_DRIVE_8mA>;
                        bias-pull-down = <MTK_PUPD_SET_R1R0_11>;
                };
        };

        spic_pins: spi1-pins-func-1 {
                mux {
                        function = "spi";
                        groups = "spi1_1";
                };
        };

        uart1_pins: spi1-pins-func-3 {
                mux {
                        function = "uart";
                        groups = "uart1_2";
                };
        };

        /* pin15 as pwm0 */
        one_pwm_pins: one-pwm-pins {
                mux {
                        function = "pwm";
                        groups = "pwm0_1";
                };
        };

        /* pin15 as pwm0 and pin14 as pwm1 */
        two_pwm_pins: two-pwm-pins {
                mux {
                        function = "pwm";
                        groups = "pwm0_1", "pwm1_0";
                };
        };

        /* pin15 as pwm0, pin14 as pwm1, pin7 as pwm2 */
        three_pwm_pins: three-pwm-pins {
                mux {
                        function = "pwm";
                        groups = "pwm0_1", "pwm1_0", "pwm2";
                };
        };
};

&spi0 {
        #address-cells = <1>;
        #size-cells = <0>;
        pinctrl-names = "default";
        pinctrl-0 = <&spi_flash_pins>;
        status = "okay";
        must_tx;
        enhance_timing;
        dma_ext;
        ipm_design;
        support_quad;
        tick_dly = <2>;
        sample_sel = <0>;

        spi_nand@0 {
                compatible = "spi-nand";
                reg = <0>;
                spi-max-frequency = <52000000>;
        };
};

&pwm {
        pinctrl-names = "default";
        pinctrl-0 = <&two_pwm_pins>;
        status = "okay";
};

&watchdog {
        status = "disabled";
};
```

## u-boot config - openwrt 

```
ethaddr_factory=mtd read mrd $loadaddr 0x0 0x80000 ; setexpr macoffs $loadaddr + 0x1fff8 ; env readmem -b ethaddr $macoffs 0x6 ; setenv ethaddr_factory
```

## u-boot env

* with stock u-boot

/etc/fw_env.config:
```
# MTD device name       Device offset   Env. size       Flash sector size       Number of sectors
/dev/mtd1 0x0 0x20000 0x20000
```

```
# fw_printenv
baudrate=115200
bootargs=console=ttyS0,115200n1 earlycon=uart8250,mmio32,0x11002000 loglevel=1
bootcmd=atgo
bootdelay=2
bootfile=ZLD-current
eth1addr=a6:37:22:eb:b2:fb
ethaddr=46:6f:d7:9d:c5:b5
fdtcontroladdr=5ffc1b10
ipaddr=192.168.1.2
loadaddr=0x46000000
mtddevname=bl2
mtddevnum=0
mtdids=nmbm0=nmbm0
mtdparts=nmbm0:1m(bl2),512k(u-boot-env),2m(factory),2m(fip),50m(ubi),50m(ubi_1),60m(rootfs_data),59904k(logs),15m(myzyxel),512k(bootconfig),512k(mrd)
netmask=255.255.255.0
partition=nmbm0,0
serverip=192.168.1.103
stderr=serial@11002000
stdin=serial@11002000
stdout=serial@11002000
#
```


## ubootmod

* get partition layout

```
# strings /dev/mtd3|grep -i ENV
[..]
nmbm0:1m(bl2),512k(u-boot-env),2m(factory),2m(fip),50m(ubi),50m(ubi_1),60m(rootfs_data),59904k(logs),15m(myzyxel),512k(bootconfig),512k(mrd)
[..]
```

```
# cat /proc/mtd
dev:    size   erasesize  name
mtd0: 00100000 00020000 "BL2"
mtd1: 00080000 00020000 "u-boot-env"
mtd2: 00200000 00020000 "Factory"
mtd3: 00200000 00020000 "FIP"
mtd4: 03200000 00020000 "ubi"
mtd5: 03200000 00020000 "ubi_1"
mtd6: 03c00000 00020000 "rootfs-data"
mtd7: 03a80000 00020000 "logs"
mtd8: 00f00000 00020000 "myzyxel"
mtd9: 00080000 00020000 "bootconfig"
mtd10: 00080000 00020000 "mrd"
#
```

* openwrt u-boot mediathek patch

```
$ cd ~/src/openwrt/
$
$ make package/boot/uboot-mediatek/{clean,prepare} V=s QUILT=1
$
$ cd ~/src/openwrt/build_dir/target-aarch64_cortex-a53_musl/u-boot-mt7981_zyxel-nwa50ax-pro/u-boot-2025.10/
$
$ quilt push -a
$
$ quilt new 472-add-zyxel-nwa50ax-pro.patch
$
$ quilt add configs/mt7981_zyxel_nwa50ax-pro_defconfig
$ quilt add arch/arm/dts/mt7981-zyxel-nwa50ax-pro.dts
$ quilt add defenvs/zyxel_nwa50ax-pro_env
$
$ quilt refresh
$
$ quilt diff 
$
$ quilt diff > ~/src/openwrt/package/boot/uboot-mediatek/patches/472-add-zyxel-nwa50ax-pro.patch
$
$ cd ~/src/openwrt/
```

* **FLASH BACKUP**

```
# dd if=/dev/mtd0 bs=128k | gzip > /tmp/mtd0_BL2.img.gz
# dd if=/dev/mtd1 bs=128k | gzip > /tmp/mtd1_u-boot-env.img.gz 
# dd if=/dev/mtd2 bs=128k | gzip > /tmp/mtd2_Factory.img.gz
# dd if=/dev/mtd3 bs=128k | gzip > /tmp/mtd3_FIP.img.gz
# dd if=/dev/mtd4 bs=128k | gzip > /tmp/mtd4_ubi.img.gz
# dd if=/dev/mtd5 bs=128k | gzip > /tmp/mtd5_ubi_1.img
# dd if=/dev/mtd6 bs=128k | gzip > /tmp/mtd6_rootfs-data.img.gz
# dd if=/dev/mtd7 bs=128k | gzip > /tmp/mtd7_logs.img.gz
# dd if=/dev/mtd8 bs=128k | gzip > /tmp/mtd8_myzyxel.img.gz
# dd if=/dev/mtd9 bs=128k | gzip > /tmp/mtd9_bootconfig.img.gz
# dd if=/dev/mtd10 bs=128k | gzip > /tmp/mtd10_mrd.img.gz
# scp /tmp/mtd* foo@bar:
[..]
#
```

### mtk uartboot

* load u-boot by uart and run from memory

reset device, load payload and start minicom (or else)

```
MT7981> sleep 10; reset
(..)
./mtk_uartboot -a -p ./mt7981-ram-ddr4-bl2.bin -f openwrt-bl31.fip -s /dev/ttyUSB0; minicom
Using serial port: /dev/ttyUSB0
Handshake...
hw code: 0x7981
hw sub code: 0x8a00
hw ver: 0xca00
sw ver: 0x1
Baud rate set to 460800
sending payload to 0x201000...
Checksum: 0xff18
Setting baudrate back to 115200
Jumping to 0x201000 in aarch64...
Waiting for BL2. Message below:
==================================
NOTICE:  BL2: v2.13.0(release):OpenWrt v2025.07.11~78a0dfd9-1 (mt7981-ram-ddr4)
NOTICE:  BL2: Built : 09:25:10, Apr 13 2026
NOTICE:  WDT: [40000000] Software reset (reboot)
NOTICE:  EMI: Using DDR4 settings
NOTICE:  EMI: Detected DRAM size: 512MB
NOTICE:  EMI: complex R/W mem test passed
NOTICE:  CPU: MT7981 (1302MHz)
NOTICE:  Starting UART download handshake ...
==================================
BL2 UART DL version: 0x10
Baudrate set to: 921600
[..]
MT7981> tftpboot
ethernet@15100000 Waiting for PHY auto negotiation to complete......... TIMEOUT !
Using ethernet@15100000 device
TFTP from server 192.168.1.254; our IP address is 192.168.1.1
Filename 'openwrt-mediatek-filogic-zyxel_nwa50ax-pro-ubootmod-initramfs-recovery.itb'.
Load address: 0x46000000
Loading: *
Abort
MT7981>
```

* reset to get back to stock u-boot

```
MT7981> reset
```
