# zynq7000

[English](README.md) | 中文页

## 编译

打开 Env 工具，切换路径到进入到 bsp_zynq7000 目录下，设置 RTT_ROOT，RTT_ROOT 是 rt-thread 源码的路径:

```
set RTT_ROOT=your_rt-thread_source_code_path
```

然后执行以下命令编译:

```
scons
```

如果编译正确无误，会产生 rtthread.elf、rtthread.bin 文件。

## 运行

在 SD 卡中放入 rtthread.bin，并在 uboot console 中执行以下命令启动：

```
mmcinfo; fatload mmc 0 0x1ff00000 rtthread.bin; go 0x1ff00000
```

## 许可协议

这是一份使用 GPLv2 及商业授权的双许可方式 BSP 代码，可以遵守 GPLv2.0 方式把这份代码链接后的程序源代码都开源的方式来使用，也可以联系睿赛德科技获得商业许可授权。睿赛德联系方式：

邮件地址：business@rt-thread.com


