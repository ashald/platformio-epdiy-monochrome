#pragma once

#include <Adafruit_GFX.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <string>

#include "esp_log.h"
#include "esp_system.h"
#include "freertos/FreeRTOS.h"
#include "sdkconfig.h"

extern "C" {
    #include "eink.h"
}

#define EPD_WHITE 1
#define EPD_BLACK 0

class gfx : public virtual Adafruit_GFX {
 public:
  const char* TAG = "Epd";

  gfx(int16_t w, int16_t h);

  // Override Adafruit_GFX own drawPixel method
  void drawPixel(int16_t x, int16_t y, uint16_t color);
  void init(uint8_t* fb);
  void buffer_clear();
  void buffer_set(bool value);
  void flush(bool value);
  void render();

  uint8_t* framebuffer;
};