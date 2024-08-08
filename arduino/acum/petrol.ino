#include <Adafruit_GC9A01A.h>
#include <Adafruit_GFX.h>
#include "petrol.h"
#include <common.h>

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);

void setup() {
  init(&tft);
  drawBorder(&tft);
  drawSymbol(&tft, logo);
}

void loop() {
  sensorReadings(&tft, 14, 7, "V", 3);
}