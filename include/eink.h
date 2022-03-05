#pragma once

#include "epd_driver.h"

#define EINK_HEIGHT      EPD_HEIGHT             // pixels
#define EINK_WIDTH       EPD_WIDTH              // pixels
#define EINK_BUFFER_SIZE EPD_WIDTH*EPD_HEIGHT/8 // bytes

// clear the given byte buffer which is assumed to be of EINK_BUFFER_SIZE
void eink_buffer_clear(uint8_t* buffer);

// set the entire buffer to the given value (true - black, false - white)
void eink_buffer_set(uint8_t* buffer, bool value);

// set the pixel (x, y) to the given value (true - black, false - white)
void eink_set_pixel(uint32_t x, uint32_t y, bool value, uint8_t* buffer);

// flush screen with given color by filling it 10 times
void eink_flush(bool value);

// render buffer
void eink_render(uint8_t* buffer);

// render buffer with pixels inverted (black for white, and white for black)
void eink_render_advanced(uint8_t* buffer, uint8_t cycles, bool inverse);

// initialize peripherals required to operate display, does not affect power consumption
void eink_init();

// deinitialize peripherals required to operate display, does not affect power consumption
void eink_deinit();

// power on the display - increases power consumption
void eink_power_on();

// power off the display - decreases power consumption
void eink_power_off();
