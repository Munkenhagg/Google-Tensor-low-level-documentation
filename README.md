# Google Tensor low-level documentation

###### **Only yet tested on tensor G1**

## Story

about a year ago, i got a pixel 6a for modding. i installed lineageOS 22.2-20250705-nightly for the pixel6a which is bluejay. it booted and worked. i then rooted it + installed GApps. but then i noticed, it looked near identical to the regular pixel home, and it was the pixel home aswell. then i got a notification about a google pixel update. so to check, i used bootctl to switch A/B slots. but then the phone wouldny boot, no display, no vibration, and windows just showed `COM7 SERIAL DEVICE` in device manager. i tried fastboot and adb - not being detect. i then gave up for a good while. but now recently when i tried debugging again, but from arch linux. i noticed that when i run `lsusb` it shows up as `ID 18d1:4f00 Google Inc. Pixel ROM Recovery`, which gave me hope. i then was quick to discover it exposes [bulk USB Endpoints](https://github.com/Munkenhagg/Google-Tensor-low-level-documentation/blob/main/bootROM/USB-endpoints.md) 