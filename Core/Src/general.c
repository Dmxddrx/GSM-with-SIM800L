#include "oled.h"
#include <stdio.h>
#include <math.h>
#include <sim800l.h>

extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart1; // GSM

void General_Run(void) {
    OLED_Init(&hi2c1);
    SIM800L_Init(&huart1);

    OLED_Clear();
    OLED_Rectangle(74, 0, 1, 12);
    OLED_Print(20, 0, "SMS:");
    OLED_Update();

    while (1)
    {
        // ========================
        // BUTTON 1  → PB13
        // ========================
        if (HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin) == GPIO_PIN_RESET)
        {
            HAL_Delay(50); // debounce
            if (HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin) == GPIO_PIN_RESET)
            {
                OLED_ClearArea(84, 16, 44, 10);
                OLED_Print(84, 16, "BTN1");
                OLED_Update();

                SIM800L_SendSMS("+94765370377",
                                "Alert: Button 1 Pressed\nSerial No = 001");

                HAL_Delay(3000);   // prevent multiple sending
            }
        }

        // ========================
        // BUTTON 2  → PB14
        // ========================
        if (HAL_GPIO_ReadPin(BTN2_GPIO_Port, BTN2_Pin) == GPIO_PIN_RESET)
        {
            HAL_Delay(50);
            if (HAL_GPIO_ReadPin(BTN2_GPIO_Port, BTN2_Pin) == GPIO_PIN_RESET)
            {
                OLED_ClearArea(84, 16, 44, 10);
                OLED_Print(84, 16, "BTN2");
                OLED_Update();

                SIM800L_SendSMS("+94765370377",
                                "Alert: Button 2 Pressed\nSerial No = 002");

                HAL_Delay(3000);
            }
        }

        // ========================
        // BUTTON 3  → PB15
        // ========================
        if (HAL_GPIO_ReadPin(BTN3_GPIO_Port, BTN3_Pin) == GPIO_PIN_RESET)
        {
            HAL_Delay(50);
            if (HAL_GPIO_ReadPin(BTN3_GPIO_Port, BTN3_Pin) == GPIO_PIN_RESET)
            {
                OLED_ClearArea(84, 16, 44, 10);
                OLED_Print(84, 16, "BTN3");
                OLED_Update();

                SIM800L_SendSMS("+94765370377",
                                "Alert: Button 3 Pressed\nSerial No = 003");

                HAL_Delay(3000);
            }
        }

        OLED_Update();
    }
}
