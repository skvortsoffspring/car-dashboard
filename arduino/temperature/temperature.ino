#include <DS18B20.h>
#include "temperature.h"
#include <common.h>

// DS18B20
#define LOW_ALARM 60
#define HIGH_ALARM 95
#define PIN_SENSOR 2

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);
DS18B20 ds(PIN_SENSOR);

void setup() {
  init(&tft);
  drawBorder(&tft);
  drawSymbol(&tft, logo);

  while (ds.selectNext()) {
    ds.setAlarms(LOW_ALARM, HIGH_ALARM);
  }
}

void loop() {
  const float temperature = ds.getTempC();
  ds.doConversion();

  sensorReadings(&tft, temperature, 7, "\xF7\C", 3);

  if (temperature < ds.getAlarmLow()) {
    warning(&tft, GC9A01A_CYAN, SYSTEM_COLOR);
  } else if (temperature > ds.getAlarmHigh()) {
    warning(&tft, GC9A01A_RED, SYSTEM_COLOR);
  } else {
    warning(&tft, GC9A01A_BLACK, GC9A01A_BLACK);
  }
}