#include "oled.h"
#include "ssd1306.h"   // use an existing SSD1306 library
#include "fonts.h"

static I2C_HandleTypeDef *oled_i2c;

void OLED_Init(I2C_HandleTypeDef *hi2c) {
    oled_i2c = hi2c;
    SSD1306_Init();
}

void OLED_Clear(void) {
    SSD1306_Fill(SSD1306_COLOR_BLACK);
    SSD1306_UpdateScreen();
}

//Draw text into the buffer only (no immediate update)
void OLED_Print(uint8_t x, uint8_t y, const char *str) {
	SSD1306_GotoXY(x, y);
	SSD1306_Puts((char*)str, &Font_7x10, SSD1306_COLOR_WHITE);
}

// New: update onece after all drawing
void OLED_Update(void){
	SSD1306_UpdateScreen();
}

// New: clear a small area (erase a line/field without clearing whole screen)
void OLED_ClearArea(uint8_t x, uint8_t y, uint8_t w, uint8_t h) {
    SSD1306_DrawFilledRectangle(x, y, w, h, SSD1306_COLOR_BLACK);
}

void OLED_Rectangle(uint8_t x, uint8_t y, uint8_t w, uint8_t h) {
    SSD1306_DrawFilledRectangle(x, y, w, h, SSD1306_COLOR_WHITE);
}

// Scroll display content to the right (hardware scroll)
void OLED_ScrollRight(uint8_t start_page, uint8_t end_page)
{
    SSD1306_ScrollRight(start_page, end_page);
}

// Scroll display content to the left (hardware scroll)
void OLED_ScrollLeft(uint8_t start_page, uint8_t end_page)
{
    SSD1306_ScrollLeft(start_page, end_page);
}

// Stop any scrolling
void OLED_StopScroll(void)
{
    SSD1306_Stopscroll();
}
