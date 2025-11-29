#ifndef SIM900_H
#define SIM900_H

#include "main.h"

void SIM800L_Init(UART_HandleTypeDef *huart);
void SIM800L_SendSMS(const char *number, const char *message);

#endif
