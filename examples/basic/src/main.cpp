#include <Arduino.h>

extern "C" {
  #include "eink.h"
}

static const char* const TAG = "eink";

// Here we use static allocation in SRAM.
// Because we pack 8 pixels per bit, we need very little space,
// and do not need PSRAM/SPIRAM.
// Also, static allocation reduces startup time,
// and makes it easier to allocate larger fragments of memory
static uint8_t fb[EINK_BUFFER_SIZE] = {0};

// Sample drawing function
void draw_horizontal_line(uint32_t y, uint8_t width) {
  for (int d = -width / 2; d < width / 2; d++) {
    for (int x = 0; x < EINK_WIDTH; x++) {
      eink_set_pixel(x, y + d, true, fb);
    }
  }
}

// Sample drawing function
void draw_vertical_line(uint32_t x, uint8_t width) {
  for (int d = -5; d < 5; d++) {
    for (int y = 0; y < EINK_HEIGHT; y++) {
      eink_set_pixel(x + d, y, true, fb);
    }
  }
}

void setup() {
  ESP_LOGI(TAG, "[%ld] setup():", millis());
}

void loop() {
  ESP_LOGI(TAG, "[%ld] loop(): start", millis());

  eink_init(); // this actually can be called just once
  eink_power_on(); // screen starts consuming more power

  ESP_LOGI(TAG, "[%ld] loop(): initialized", millis());

  // These 2 are optional - clear artifacts for a higher-contrast result
  eink_flush(false); // white
  eink_flush(true);  // black

  // Make sure our frame-buffer is all clear
  eink_buffer_clear(fb);

  static bool line_direction = true;
  line_direction = !line_direction;
  if (line_direction) {
    draw_horizontal_line(EINK_HEIGHT / 2, 10);
  } else {
    draw_vertical_line(EINK_WIDTH / 2, 10);
  }

  // This actually updates the screen
  eink_render(fb);

  eink_power_off(); // board back to low power mode
  eink_deinit(); // this actually can be called just once when we no longer need the screen

  ESP_LOGI(TAG, "[%ld] loop(): finish", millis());
  delay(2000);
}
