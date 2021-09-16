# Loader固件说明

## MiniLoader

1. **MiniLoaderAll.bin**：默认烧写固件指向的MiniLoader固件

## uboot

uboot固件会读取开发板的SN来匹配对应的内核设备树，要求同一型号的开发板的SN的前6位必须一致。

1. uboot.img: 支持所有RK3566和RK3568开发板
2. **uboot-rk3568evb1-v10.img**: 由于RK3566-EVB2-V11开发板的SN是随机数，**首次**启动必须烧写这个uboot，重启成功后，可以替换为uboot.img。
