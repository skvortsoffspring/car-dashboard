#include <Adafruit_GC9A01A.h>
#include <Adafruit_GFX.h>
#include "oil.h"
#include <common.h>

#define UNIT "kg/cm2"

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);

void setup() {
  init(&tft);
  drawSymbol(&tft, logo);
  drawUnit(&tft, UNIT, 3, 170);
  drawBorder(&tft);
}

void loop() {
  sensorReadings(&tft, 12.5);
}