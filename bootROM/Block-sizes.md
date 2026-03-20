# This is what different block sizes(bs=?) do when uploading BL1 to the exynos usb boot bootROM

- **64 to 128** - I/O error
- **256** - no I/O error, but somehow it doesnt boot either?
- **512** - no I/O error, boots BL1 perfectly - recommended

It also works without defining block size. so anything above 512 should work
