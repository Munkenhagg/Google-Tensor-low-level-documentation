# This is my guide for finding your VID, PID, and USB endpoints so that you can easily follow this guide

## VID & PID

to find your VID and PID, the easiest way is to run `lsusb` while not holding your power button. then hold down your power button and run `lsusb` again. the device that appeared is your very likely your pixel. An example of your device is `Bus 001 Device 004: ID 18d1:4f00 Google Inc. Pixel ROM Recovery` the first 4 numbers of the ID is your VID. the lst ones are PID.

## BL1 USB endpoints

- NOTE: you do **not** need this to [upload BL1 to bootROM](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/bootROM/How-to-upload-BL1.md). only to **upload BL2 to the BL1 protocol**
to find your BL1 endpoints is pretty simple. you will need your device ID found in the tutoriaal just above

to start off. you will need to follow the [How to upload BL1 to bootrom for USB boot guide](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/bootROM/How-to-upload-BL1.md) and do not release the power button. instead, quickly run `lsusb -v -d DEVICE_ID`. then you will see all of the information about it. you are now free to release the power button. in the info about the device, look for `EP 2 OUT` where you to the left should see the endpoint. then you will also need to EP 1 IN endpoint, it is shown a few lines under or above.
for me i got `0x02 EP 2 OUT` and `0x81 EP 1 IN`
now to fully verify it is the right endpoint you will need to run `lsusb -v -d DEVICE_ID` but now just while holding the power button, do not uplod bl1 before it **this** time. you will look for the same endpoints. but now the endpoint number could be different, so watch out for that. only use the one after bl1 is uploaded, dosnt matter if its the same tho.

but what probably is different is the Interrupt(EP 3 IN) endpoint.
so you should check the difference. to make sure it booted BL1 and didnt throw an error. EP 3 IN is not as important but it can be used as a check. as for me
in bootROM:
    0x83 EP 3 IN
in BL1:
    0x81 EP 3 IN
