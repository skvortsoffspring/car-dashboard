#include <Adafruit_GC9A01A.h>
#include <Adafruit_GFX.h>
#include "acum.h"
#include <common.h>

#define UNIT "volt"

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);

void setup() {
  init(&tft);
  drawSymbol(&tft, logo);
  drawUnit(&tft, UNIT, 3, 170);
  drawBorder(&tft);
}

void loop() {
  sensorReadings(&tft, 14.4);
}