# How to send data to the pixel using the exposed EP 2 OUT endpoint

First off, hold the power button. while holding, confirm that it is actually requesting usb boot. to do we will run this command `sudo cat /dev/ttyACM0` if you see something like `eub:req:9845001:bl1` then good. you are probably able to send a bl1.img or bl1.bin
to confirm that, we are going to hold to power button, and use `sudo dd if=/dev/urandom of=/dev/ttyACM0 bs=512 count=24` then to confiirm, we will run `sudo cat /dev/ttyACM0` without releasing the power button.
you should see first `bl1_header_fail` and then it starts to slowwly fill up with `irom_booting_failure` or similar. that confirms 100% that the bootROM parsed the image you sent it
