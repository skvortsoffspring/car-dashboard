#include "common.h"

void init(Adafruit_GC9A01A *tft){
  tft->begin();
  tft->setRotation(0);
  tft->fillScreen(GC9A01A_BLACK);
}

void drawBorder(Adafruit_GC9A01A *tft) {
  for (unsigned short i = 0; i < BORDER_SIZE ; i++) {
    tft->drawCircle(tft->width() / 2, tft->height() / 2, tft->width() / 2 - i, SYSTEM_COLOR);
  }
}

void warning(Adafruit_GC9A01A *tft, unsigned short colorFill, unsigned short colorBorder) {
  tft->fillCircle(180, 180, 12, colorFill);
  tft->drawCircle(180, 180, 13, colorBorder);
  tft->drawCircle(180, 180, 14, colorBorder);
}

void sensorReadings(Adafruit_GC9A01A *tft, short reading, const unsigned char sizeText, const char unit[], const unsigned char sizeTextUnit) {
  tft->setTextSize(sizeText);
  tft->setTextColor(SYSTEM_COLOR, GC9A01A_BLACK);

  char buff[4];
  snprintf(buff, sizeof(buff), "%3d", reading);

  tft->setCursor(36, 99);
  tft->print(buff);

  tft->setCursor(163, 124);

  tft->setTextSize(sizeTextUnit);
  tft->print(unit);
}

void drawSymbol(Adafruit_GC9A01A *tft, unsigned char logo[][COLS]) {
  const unsigned short offsetX = tft->width() / 2 - COLS/ 2;

  for (unsigned short row = 0; row < ROWS; row++) {
    for (unsigned short col = 0; col < COLS; col++) {
      for (unsigned short offset = 0; offset < 8; offset++) {
        if (logo[row][col] & (1 << offset))
          tft->drawPixel(offsetX + col, OFFSET_Y + row * 8 + offset, SYSTEM_COLOR);
      }
    }
  }
}
