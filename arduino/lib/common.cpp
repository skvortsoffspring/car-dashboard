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
  tft->fillCircle(WARNING_X, WARNING_Y, 12, colorFill);
  tft->drawCircle(WARNING_X, WARNING_Y, 13, colorBorder);
  tft->drawCircle(WARNING_X, WARNING_Y, 14, colorBorder);
}

void sensorReadings(Adafruit_GC9A01A *tft, float reading) {
  char buff[3];

  tft->setTextColor(SYSTEM_COLOR, GC9A01A_BLACK);

  snprintf(buff, sizeof(buff), "%2d", (int)reading);

  tft->setTextSize(7);
  tft->setCursor(66, 95);
  tft->print(buff);

  snprintf(buff, sizeof(buff), ".%1d", ((int)(reading * 10)) % 10);
  tft->setTextSize(4);
  tft->setCursor(145, 118);
  tft->print(buff);
}

void drawUnit(Adafruit_GC9A01A *tft, const char unit[], const uint8_t sizeText, const uint8_t offsetY){

  tft->fillRect(0, offsetY, tft->width(), tft->height() - offsetY, 0x18e3);

  tft->drawLine(0, offsetY, tft->width(), offsetY, SYSTEM_COLOR);

  tft->setTextSize(sizeText);
  tft->setTextColor(SYSTEM_COLOR);

  int16_t charWidth = 6 * sizeText;
  int16_t textWidth = strlen(unit) * charWidth;

  int16_t xPos = (tft->width() - textWidth) / 2;
  int16_t yPos = 12 + offsetY;

  tft->setCursor(xPos, yPos);
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
