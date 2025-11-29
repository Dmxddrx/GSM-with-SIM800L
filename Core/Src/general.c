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
    OLED_Rectangle(0, 13, 128, 1);
    OLED_Print(39, 0, "SIM800L");
    OLED_Print(0, 16, "BTN1:");
    OLED_Print(0, 27, "BTN2:");
    OLED_Print(0, 38, "BTN3:");
    OLED_Update();

    while (1)
    {
        // ========================
        // BUTTON 1  → PB13
        // ========================
    	if (HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin) == GPIO_PIN_RESET)
    	{
    	    // Turn on LED (PB12)
    	    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);

    	    OLED_ClearArea(40, 16, 88, 10);
    	    OLED_Print(40, 16, "Pressed");
    	    OLED_Update();

    	    SIM800L_SendSMS("+94765370377",
    	                    "Alert: Button 1 Pressed\nSerial No = 001");

    	    HAL_Delay(3000);   // prevent multiple sending

    	    // Turn off LED after action
    	    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
    	}


        // ========================
        // BUTTON 2  → PB14
        // ========================
        if (HAL_GPIO_ReadPin(BTN2_GPIO_Port, BTN2_Pin) == GPIO_PIN_RESET)
        {

        	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);
			OLED_ClearArea(40, 27, 88, 10);
			OLED_Print(40, 27, "Pressed");
			OLED_Update();

			SIM800L_SendSMS("+94765370377",
							"Alert: Button 2 Pressed\nSerial No = 002");

			HAL_Delay(3000);
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

        }

        // ========================
        // BUTTON 3  → PB15
        // ========================
        if (HAL_GPIO_ReadPin(BTN3_GPIO_Port, BTN3_Pin) == GPIO_PIN_RESET)
        {
        	HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_SET);

			OLED_ClearArea(40, 38, 88, 10);
			OLED_Print(40, 38, "Pressed");
			OLED_Update();

			SIM800L_SendSMS("+94765370377",
							"Alert: Button 3 Pressed\nSerial No = 003");

			HAL_Delay(3000);
			HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);

        }

        OLED_Update();
    }
}
