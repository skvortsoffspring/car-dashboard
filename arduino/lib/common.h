#pragma once
#include <Adafruit_GC9A01A.h>
#include <Adafruit_GFX.h>

#define TFT_CS 10
#define TFT_DC 9
#define TFT_BL 8
#define SYSTEM_COLOR 0xF4A5
#define BORDER_SIZE 5
#define ROWS 8
#define COLS 64
#define OFFSET_Y 20

#define WARNING_X 40
#define WARNING_Y 140

void drawBorder(Adafruit_GC9A01A *tft);
void init(Adafruit_GC9A01A *tft);
void warning(Adafruit_GC9A01A *tft, unsigned short colorFill, unsigned short colorBorder);
void sensorReadings(Adafruit_GC9A01A *tft, float reading);
void drawUnit(Adafruit_GC9A01A *tft, const char unit[], const uint8_t sizeTextUnit, const uint8_t offsetY);
void drawSymbol(Adafruit_GC9A01A *tft, unsigned char logo[][COLS]);