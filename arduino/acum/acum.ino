#include <Adafruit_GC9A01A.h>
#include <Adafruit_GFX.h>
#include "acum.h"
#include <common.h>

#define TEXT_UNIT_SIZE 3
#define OFFSE_UNIT_PX_Y 170
#define UNIT "volt"

#define VREF 5.0  // value of your stabilizer voltage
#define R1 10000  // measure the resistance and make adjustments
#define R2 4700   // measure the resistance and make adjustments
#define ADC 1024

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);

void setup() {
  init(&tft);
  drawSymbol(&tft, logo);
  drawUnit(&tft, UNIT, TEXT_UNIT_SIZE, OFFSE_UNIT_PX_Y);
  drawBorder(&tft);
}

void loop() {
  sensorReadings(&tft, analogRead(A0) * VREF * ((R1 + R2) / R2) / ADC);
}