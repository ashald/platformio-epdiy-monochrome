# platformio-epdiy-monochrome
A sample PlatformIO project demonstrating how to use EPDiy in simple monochrome mode

# Requirements
1. An ESP32 with [EPDiy](https://github.com/vroland/epdiy) compatible display (e.g., [Lilygo T5 E-Paper 4.7](http://www.lilygo.cn/prod_view.aspx?TypeId=50061&Id=1384&FId=t3:50061:3))
2. [PlatformIO CLI](https://docs.platformio.org/en/latest/core/installation.html) to run this

# Run
1. Adjust `env` in `platformio.ini` as/if needed
2. `pio run -t upload `
3. `pio device monitor`

# Usage
See [main.cpp](src/main.cpp) for usage example, or [eink.h](src/eink.h) for the API documentation.
In order to use the simplified API you nonly need to include 1 file:
```c
#include "eink.h"
```
or in C++
```cpp
extern "C" {
  #include "eink.h"
}
```

# TODO
1. Make it PlatformIO library for easy reuse?
