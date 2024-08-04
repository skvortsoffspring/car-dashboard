#include <Adafruit_GC9A01A.h>
#include <Adafruit_GFX.h>
#include <DS18B20.h>
#include <math.h>
#include "temperature.h"

// DS18B20
#define LOW_ALARM 60
#define HIGH_ALARM 95
#define PIN_SENSOR 2

// DISPLAY
#define TFT_CS 10
#define TFT_DC 9
#define TFT_BL 8
#define SYSTEM_COLOR 0xF4A5

#define CHECK_BIT(var, pos) ((var) & (1 << (pos)))

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);
DS18B20 ds(PIN_SENSOR);

void drawBorder() {
  for (uint16_t i = 0; i < 5; i++) {
    tft.drawCircle(tft.width() / 2, tft.height() / 2, tft.width() / 2 - i, SYSTEM_COLOR);
  }
}

void drawSymbol() {
  const uint16_t offsetX = tft.width() / 2 - COLS / 2;
  const uint16_t offsetY = 20;

  for (uint8_t row = 0; row < ROWS; row++) {
    for (uint8_t col = 0; col < COLS; col++) {
      for (uint8_t offset = 0; offset < 8; offset++) {
        if (CHECK_BIT(logo[row][col], offset))
          tft.drawPixel(offsetX + col, offsetY + row * 8 + offset, SYSTEM_COLOR);
      }
    }
  }
}

void drawTemperatureRange(int16_t temperature) {

  const uint16_t size = 7;

  tft.setTextSize(size);
  tft.setTextColor(SYSTEM_COLOR, GC9A01A_BLACK);

  char tempString[4];
  snprintf(tempString, sizeof(tempString), "%3d", temperature);

  tft.setCursor(36, 99);

  tft.print(tempString);

  tft.setCursor(163, 134);

  tft.setTextSize(2);
  tft.print("\xF7");
  tft.println("C");
}

void warning(uint16_t colorFill, uint16_t colorBorder) {
  tft.fillCircle(180, 180, 12, colorFill);
  tft.drawCircle(180, 180, 13, colorBorder);
  tft.drawCircle(180, 180, 14, colorBorder);
}

void setup() {
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(GC9A01A_BLACK);

  drawBorder();
  drawSymbol();

  while (ds.selectNext()) {
    ds.setAlarms(LOW_ALARM, HIGH_ALARM);
  }
}

void loop() {
  const float temperature = ds.getTempC();
  ds.doConversion();

  drawTemperatureRange(temperature);

  if (temperature < ds.getAlarmLow()) {
    warning(GC9A01A_CYAN, SYSTEM_COLOR);
  } else if (temperature > ds.getAlarmHigh()) {
    warning(GC9A01A_RED, SYSTEM_COLOR);
  } else {
    warning(GC9A01A_BLACK, GC9A01A_BLACK);
  }
}