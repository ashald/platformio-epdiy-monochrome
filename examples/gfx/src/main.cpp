#include <Arduino.h>

#include "gfx.h"

// FONT used for title / message body - Only after display library
// Converting fonts with ümlauts: ./fontconvert *.ttf 18 32 252
#include <Fonts/FreeSansOblique24pt7b.h>
#include <Fonts/ubuntu/Ubuntu_M48pt8b.h>

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

gfx GFX(EINK_WIDTH, EINK_HEIGHT);

void setup() {
  ESP_LOGI(TAG, "[%ld] setup():", millis());
  GFX.init(fb);
  GFX.flush(EPD_WHITE);
  GFX.flush(EPD_BLACK);

  GFX.setCursor(30, 300);
  GFX.setFont(&Ubuntu_M48pt8b);
  GFX.println("GFX Demo");
  GFX.setCursor(30, 400);
  GFX.setFont(&FreeSansOblique24pt7b);
  GFX.println("Just for fun: Print some fast geometric forms");

  GFX.setFont(&Ubuntu_M48pt8b);
  GFX.fillCircle(400, 100, 50, 1);
  GFX.fillCircle(600, 100, 50, 1);

  GFX.flush(EPD_WHITE);
  GFX.render();
  delay(3000);
  GFX.buffer_clear();
}

uint16_t loop_counter = 0;
uint16_t circle_radius = 25;
uint16_t x_ini = 60;
uint16_t y_ini = 60;
uint16_t x_circle = x_ini;
uint16_t y_circle = y_ini;
uint8_t loops = 0;

void loop() {
  if (loops > 1) {
    return;
  }
  if (y_circle > EPD_HEIGHT - circle_radius) {
    y_circle = y_ini;
    x_circle = x_ini;
    GFX.buffer_clear();
    GFX.flush(EPD_WHITE);
    GFX.flush(EPD_BLACK);
    loops++;
  }
  if (y_circle < y_ini * 2) {
    GFX.fillRect(x_circle, y_circle, 20, 20, 1);
  } else if (y_circle > y_ini * 3 && y_circle < y_ini * 8) {
    GFX.setCursor(x_circle, y_circle);
    GFX.write(rand() % 50 + 48);
  } else {
    if (rand() % 2 + 1 == 1) {
      GFX.fillCircle(x_circle, y_circle, 20, 1);
    } else {
      GFX.fillTriangle(x_circle, y_circle, x_circle + 20, y_circle,
                       x_circle + 20, y_circle + 20, 1);
    }
  }
  x_circle = x_circle + x_ini;

  if (x_circle > EPD_WIDTH - circle_radius) {
    x_circle = x_ini;
    y_circle += y_ini;
  }

  GFX.render();
  delay(100);
}