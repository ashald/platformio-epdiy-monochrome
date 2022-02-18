#include <Arduino.h>

extern "C" {
  #include "eink.h"
}

static const char* const TAG = "eink";

static uint8_t fb[EINK_BUFFER_SIZE] = {0};

void draw_horizontal_line(uint32_t y, uint8_t width) {
  for (int d = -width / 2; d < width / 2; d++) {
    for (int x = 0; x < EINK_WIDTH; x++) {
      eink_set_pixel(x, y + d, true, fb);
    }
  }
}

void draw_vertical_line(uint32_t x, uint8_t width) {
  for (int d = -5; d < 5; d++) {
    for (int y = 0; y < EINK_HEIGHT; y++) {
      eink_set_pixel(x + d, y, true, fb);
    }
  }
}

void setup() { ESP_LOGI(TAG, "[%ld] setup():", millis()); }

void loop() {
  ESP_LOGI(TAG, "[%ld] loop(): start", millis());

  eink_init();
  eink_power_on();

  ESP_LOGI(TAG, "[%ld] loop(): initialized", millis());

  eink_flush(false);
  eink_flush(true);

  eink_buffer_clear(fb);

  static bool line_direction = true;
  line_direction = !line_direction;
  if (line_direction) {
    draw_horizontal_line(EINK_HEIGHT / 2, 10);
  } else {
    draw_vertical_line(EINK_WIDTH / 2, 10);
  }

  eink_render(fb);

  eink_power_off();
  eink_deinit();

  ESP_LOGI(TAG, "[%ld] loop(): finish", millis());
  delay(2000);
}
