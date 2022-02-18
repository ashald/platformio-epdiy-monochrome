# platformio-epdiy-monochrome
A sample PlatformIO project demonstrating how to use EPDiy in simple monochrome mode

# Requirements
1. An ESP32 with [EPDiy](https://github.com/vroland/epdiy) compatible display (e.g., [Lilygo T5 E-Paper 4.7](http://www.lilygo.cn/prod_view.aspx?TypeId=50061&Id=1384&FId=t3:50061:3))
2. [PlatformIO CLI](https://docs.platformio.org/en/latest/core/installation.html) to run this

# Instructions
1. Adjust `env` in `platformio.ini` as/if needed
2. `pio run -t upload `
3. `pio device monitor`