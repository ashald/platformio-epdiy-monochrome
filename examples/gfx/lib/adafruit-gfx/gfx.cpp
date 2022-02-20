#include "gfx.h"

#include <stdio.h>
#include <stdlib.h>

#include "esp_log.h"
#include "freertos/task.h"

gfx::gfx(int16_t w, int16_t h) : Adafruit_GFX(w, h) {}

void gfx::init(uint8_t* fb) {
  framebuffer = fb;
  eink_init();
}

void gfx::drawPixel(int16_t x, int16_t y, uint16_t color) {
  eink_set_pixel(x, y, (bool)color, framebuffer);
}

void gfx::buffer_clear() { eink_buffer_clear(framebuffer); }

void gfx::buffer_set(bool value) { eink_buffer_set(framebuffer, value); }

void gfx::flush(bool value) {
  if (value) {
    eink_flush(false);
  } else {
    eink_flush(true);
  }
}

void gfx::render() { eink_render(framebuffer); }