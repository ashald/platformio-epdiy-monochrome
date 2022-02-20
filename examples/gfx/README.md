# What
A graphics library based on [Adafruit_GFX](https://github.com/martinberlin/Adafruit-GFX-Library-ESP-IDF.git#adafruit-master) by @martinberlin, that uses fast monochrome drawing via EPDiy.

See [`main.cpp`](src/main.cpp) for usage example, or [`gfx.h`](lib/gfx/gfx.h) and [`gfx.cpp`](lib/gfx/gfx.cpp) for implementation details.

# Run
1. Adjust `env` in `platformio.ini` as/if needed
2. `pio run -t upload `
3. `pio device monitor`
