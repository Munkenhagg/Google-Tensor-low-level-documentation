# Google Tensor low-level documentation

##### **Only yet tested on tensor G1, Pixel 6a**

## Story / Main info

about a year ago, i got a pixel 6a for modding. i installed lineageOS 22.2-20250705-nightly for the pixel6a which is bluejay. it booted and worked. i then rooted it + installed GApps. but then i noticed, it looked near identical to the regular pixel home, and it was the pixel home aswell. then i got a notification about a google pixel update. so to check, i used bootctl to switch A/B slots. but then the phone wouldnt boot, no display, no vibration, and windows just showed `COM7 SERIAL DEVICE` in device manager. i tried fastboot and adb - not being detect. i then gave up for a good while. but now recently when i tried debugging again, but from arch linux. i noticed that when i run `lsusb` it shows up as `ID 18d1:4f00 Google Inc. Pixel ROM Recovery`, which gave me hope. i then was quick to discover it exposes [bulk USB Endpoints](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/bootROM/USB-endpoints.md). which allows me to [send data to the OUT endpoint](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/bootROM/How-to-send-data-to-pixel.md)
this is important because if there is an endpoint it is likely a good sign. in my case, it is. what i did was download the latest factory image for my phone from google, [codename](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/assets/codenames.md) bluejay. then i uploaded it to the endpoint at /dev/ttyACM0, see how to [upload BL1 to the bootROM](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/bootROM/How-to-upload-BL1.md).
while just uploading it doesnt make it permanent because it is just a temporary USB boot. tho i can confirm it works because when i run my quick [lsusb script](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/scripts/probe_bl1.c), it returns different results depending on what i send. if i send 0x01 0x00 0x00 0x00, it returns:

```output
Initializing libusb...
Opening device 18d1:4f00
Detaching kernel driver...
Claiming interface 0
Handshake response: 06
Sent 64 bytes
Waiting for response...
Read failed: -7
```

see [Handshake Responses](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/BL1/Handshake_responses.md)

i have currently not found a solution to upload BL2 to BL1. but i have atleast figured out how to boot it and talk to it.
My BL1 reverse engineering progress can be found at [BL1 Reverse Engineering Progress](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/BL1/RE_Progress.md)

## Other information

- The VID, PID, and endpoints may not be the same for all devices, as this has only bween done on my pixel 6a which uses the tensor G1. which you can find in the pixel 6 and pixel 6 pro aswell. to tweak it, please follow this [VID, PID and EP guide](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/assets/Find_your_VID_PID_EP.md). though my [VID PID and endpoints can be found here](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/BL1/VID_PID_EP.md)
