#include <sim800l.h>
#include <string.h>
#include <stdio.h>

static UART_HandleTypeDef *gsm_uart;

void SIM800L_Init(UART_HandleTypeDef *huart) {
    gsm_uart = huart;
}

static void send_cmd(const char *cmd, uint32_t delay) {
    HAL_UART_Transmit(gsm_uart, (uint8_t*)cmd, strlen(cmd), HAL_MAX_DELAY);
    HAL_Delay(delay);
}

void SIM800L_SendSMS(const char *number, const char *message) {
    char buf[128];
    send_cmd("AT\r\n", 500);
    send_cmd("AT+CMGF=1\r\n", 500); // text mode
    snprintf(buf, sizeof(buf), "AT+CMGS=\"%s\"\r\n", number);
    send_cmd(buf, 500);
    send_cmd(message, 500);
    uint8_t ctrlZ = 26; // end of SMS
    HAL_UART_Transmit(gsm_uart, &ctrlZ, 1, HAL_MAX_DELAY);
}
