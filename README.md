# What
A wrapper around [EPDiy] for fast monochrome rendering, in a form of [PlatformIO](platformio.org) library.

# Why

## Performance
Compared to [EPDiy], this library only supports monochrom (black & white) rendering.

This allows using less memory, drawing over a buffer more efficiently, and updating the screen faster.
Partial update on [Lilygo T5 E-Paper 4.7] takes about 200ms, and clearing a screen takes about 300ms (which means that full update is about 500ms).

Monochrome mode allows storing 8 pixels per byte, resulting in minimal memory requirement. This, in turn, allows using SRAM, which is generally faster than  rather than PSRAM/SPIRAM. [Modules with PSRAM take long to boot] is another ESP32/Arudino specific issue which resulted into additional 500-8500ms of boot time. It was fixed in Jan 2022, but the fix is not widely available yet at the time of release.

## Convenience 
[EPDiy] provides a nice high-level API for grayscale updates, but otherwise you need to deal with complex low-level APIs.
This wrapper takes care of that job and provides a primitive interface for drawing pixels, and rendering the result, albeit in monochrome only.

# Usage

The API is defined in [`eink.h`](include/eink.h), and that's the only file you need to include in C:
```c
#include "eink.h"
```
or in C++
```cpp
extern "C" {
  #include "eink.h"
}
```

See [examples](examples/):
 * [basic](examples/basic/) - demonstrates primitive pixel operations
 * [gfx](examples/gfx/) - demonstrate more elaborate graphics operations (courtesy of @martinberlin).

# Requirements
1. An ESP32 with [EPDiy](https://github.com/vroland/epdiy) compatible display (e.g., [Lilygo T5 E-Paper 4.7](http://www.lilygo.cn/prod_view.aspx?TypeId=50061&Id=1384&FId=t3:50061:3))
2. [PlatformIO CLI](https://docs.platformio.org/en/latest/core/installation.html) to run this

[EPDiy]: https://github.com/vroland/epdiy
[Lilygo T5 E-Paper 4.7]: http://www.lilygo.cn/prod_view.aspx?TypeId=50061&Id=1384&FId=t3:50061:3
[Modules with PSRAM take long to boot]: https://github.com/espressif/arduino-esp32/issues/5737
