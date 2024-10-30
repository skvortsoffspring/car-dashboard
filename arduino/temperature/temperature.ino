#include <OneWire.h>
#include <DallasTemperature.h>
#include <common.h>
#include "temperature.h"

//#define FAHRENHEIT

// DS18B20
#define LOW_ALARM 40
#define HIGH_ALARM 95  // C/F
#define PIN_D2 2

#define BUZZER_PIN 3

#ifdef FAHRENHEIT
#define TEMP_UNIT "fahrenheit"
#define TEMP_SIZE 2
#define TEMP_POSITION 180
#else
#define TEMP_UNIT "celsius"
#define TEMP_SIZE 3
#define TEMP_POSITION 170
#endif

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);

OneWire oneWire(PIN_D2);
DallasTemperature sensors(&oneWire);
DeviceAddress insideThermometer;


void setup() {
  sensors.begin();

  init(&tft);
  drawSymbol(&tft, logo);
  drawUnit(&tft, TEMP_UNIT, TEMP_SIZE, TEMP_POSITION);
  drawBorder(&tft);


  sensors.setResolution(insideThermometer, 9);
}

void loop() {

  sensors.requestTemperatures();

#ifdef FAHRENHEIT
  const float temperature = sensors.getTempF(insideThermometer);
#else
  const float temperature = sensors.getTempC(insideThermometer);
#endif

  sensorReadings(&tft, temperature);

  if(temperature == DEVICE_DISCONNECTED_C){
    // to rs232
  }

  if (temperature <= LOW_ALARM) {
    warning(&tft, GC9A01A_CYAN, SYSTEM_COLOR);
  } else if (temperature > HIGH_ALARM) {
    warning(&tft, GC9A01A_RED, SYSTEM_COLOR);
  } else {
    warning(&tft, GC9A01A_BLACK, GC9A01A_BLACK);
  }
}