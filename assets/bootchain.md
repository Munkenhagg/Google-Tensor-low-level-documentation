# this is how the default bootchain looks for pixels

SoC starts the BootROM
bootROM tries to start BL1, if bl1 doesnt exist it falls back to Pixel ROM Recovery
BL1 tries to start BL2, if BL2 doesnt exist tthen it starts its own protocol and waits for 30 seconds~
BL2 initializes more stuff then starts BL31(ARM trusted firmware), if it doesnt exist probably falls back to a protocol or just skips it
BL31 acts like secure boot, then starts BL33(android bootloader)
andrid bootloader loads the kernel and ramdisk from boot.img
kernel loads the OS, often from super.img or system, vendor, and alike partitions
