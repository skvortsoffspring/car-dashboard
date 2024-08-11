#include <DS18B20.h>
#include "temperature.h"
#include <common.h>

// DS18B20
#define LOW_ALARM 0
#define HIGH_ALARM 95
#define PIN_SENSOR 2

#define UNIT "celcius"

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);
DS18B20 ds(PIN_SENSOR);

void setup() {
  init(&tft);
  drawSymbol(&tft, logo);
  drawUnit(&tft, UNIT, 3, 170);
  drawBorder(&tft);

  while (ds.selectNext()) {
    ds.setAlarms(LOW_ALARM, HIGH_ALARM);
  }
}

void loop() {
  const float temperature = ds.getTempC();
  ds.doConversion();

  sensorReadings(&tft, temperature);

  if (temperature <= ds.getAlarmLow()) {
    warning(&tft, GC9A01A_CYAN, SYSTEM_COLOR);
  } else if (temperature > ds.getAlarmHigh()) {
    warning(&tft, GC9A01A_RED, SYSTEM_COLOR);
  } else {
    warning(&tft, GC9A01A_BLACK, GC9A01A_BLACK);
  }
}