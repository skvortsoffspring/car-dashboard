#include <Adafruit_GC9A01A.h>
#include <Adafruit_GFX.h>
#include "petrol.h"
#include <common.h>

#define UNIT "litres"

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);

void setup() {
  init(&tft);
  drawSymbol(&tft, logo);
  drawUnit(&tft, UNIT, 3, 170);
  drawBorder(&tft);
}

void loop() {
  sensorReadings(&tft, 22.0);
}