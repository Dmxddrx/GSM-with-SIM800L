#ifndef OLED_H
#define OLED_H

#include "main.h"

void OLED_Init(I2C_HandleTypeDef *hi2c);
void OLED_Clear(void);
void OLED_Print(uint8_t x, uint8_t y, const char *str);
void OLED_Update(void);
void OLED_ClearArea(uint8_t x, uint8_t y, uint8_t w, uint8_t h);
void OLED_Rectangle(uint8_t x, uint8_t y, uint8_t w, uint8_t h);
void OLED_ScrollRight(uint8_t start_page, uint8_t end_page);
void OLED_ScrollLeft(uint8_t start_page, uint8_t end_page);
void OLED_StopScroll(void);

#endif
