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

void drawBorder(Adafruit_GC9A01A *tft);
void init(Adafruit_GC9A01A *tft);
void warning(Adafruit_GC9A01A *tft, unsigned short colorFill, unsigned short colorBorder);
void sensorReadings(Adafruit_GC9A01A *tft, short reading, const unsigned char sizeText, const char unit[], const uint8_t sizeTextUnit);
void drawSymbol(Adafruit_GC9A01A *tft, unsigned char logo[][COLS]);