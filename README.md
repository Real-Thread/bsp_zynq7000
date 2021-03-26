# zynq7000

English | [中文页](README_zh.md)

## Compile the BSP

Open Env tool, switch the path to bsp_zynq7000 directory, and set RTT_ROOT. RTT_ROOT is the path of rt-thread source code:
```
set RTT_ROOT=your_rt-thread_source_code_path
```
Then execute the following command to compile the bsp_zynq7000:
```
scons
```
If the compilation is correct, rtthread.elf and rtthread.bin are generated.
## Run the BSP

Place the rtthread.bin in the SD card and run:

```
mmcinfo; fatload mmc 0 0x1ff00000 rtthread.bin; go 0x1ff00000
```

in the uboot console.

## License

This is a double license BSP code using GPL v2.0 and commercial license. You can follow the GPL v2.0 method to use the linked program source code in an open source way. You can also contact Real-Thread Electronic Technology Co., Ltd to obtain commercial license. 

Email of Real-Thread ：business@rt-thread.com