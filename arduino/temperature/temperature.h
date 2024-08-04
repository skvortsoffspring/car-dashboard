#define ROWS 8
#define COLS 64

uint8_t logo[ROWS][COLS] = {
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0xC0,0xE0,0xE0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE3,0xE3,0xE3,0xE3,0xE3,0xE3,0xE3,0xE3,0xE3,0xC1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x79,0x30,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x06,0x0F,0x1F,0x3E,0x3C,0x78,0xF0,0xE0,0xF0,0xF8,0x7C,0x3E,0x1F,0x0F,0x1F,0x3E,0x7C,0xF8,0xF0,0x60,0x00,0x00,0x00,0x00,0x78,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0xFC,0x78,0x00,0x00,0x00,0x60,0xF0,0xF8,0x7C,0x3E,0x1F,0x0F,0x1F,0x3E,0x7C,0xF8,0xF0,0xE0,0xF0,0x78,0x3C,0x3E,0x1F,0x0F,0x06,0x00,0x00},
	{0x00,0x00,0x00,0x30,0x78,0xF8,0xF0,0xE0,0xC0,0x80,0x80,0xC0,0xE0,0xF0,0x78,0x78,0xF8,0xF0,0xE0,0xC0,0x80,0x80,0xC0,0xE0,0xF0,0x78,0x78,0xF8,0xF1,0xE3,0xC7,0x87,0x87,0x87,0xC7,0xE3,0xF1,0xF8,0x78,0x78,0xF0,0xE0,0xC0,0x80,0x80,0xC0,0xE0,0xF0,0xF8,0x78,0x78,0xF0,0xE0,0xC0,0x80,0x80,0xC0,0xE0,0xF0,0xF8,0x78,0x30,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x07,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x07,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x01,0x01,0x03,0x07,0x07,0x07,0x03,0x01,0x01,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x07,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x01,0x03,0x07,0x07,0x07,0x03,0x01,0x00,0x00,0x00,0x00,0x00}
};