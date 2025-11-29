#include "oled.h"
#include <stdio.h>
#include <math.h>
#include <sim800l.h>

extern I2C_HandleTypeDef hi2c1;
extern UART_HandleTypeDef huart1; // GSM


void General_Run(void) {
    OLED_Init(&hi2c1);
    SIM800L_Init(&huart1);


    char line[32];
    char fstr[16];

    char lat_str[20];
    char lon_str[20];


    OLED_Clear();   // clear only once at start
    OLED_Rectangle(74, 0, 1, 12);
    OLED_Print(0, 27, "AnV:");
    OLED_Update();

    while (1) {


        if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15) == GPIO_PIN_RESET)  // button pressed
        {
            // --- OLED Feedback ---
            OLED_ClearArea(84, 16, 44, 10);
            OLED_Print(84, 16, "CANCEL");
            OLED_Update();

            // --- Send Cancel SMS ---
            SIM900_SendSMS("+94765370377",
                           "Emergency Cancelled by Rider\nSerial No = 221");

            // Prevent SMS spamming
            HAL_Delay(3000);
        }

        OLED_Update();   // refresh once per loop

    }
}
