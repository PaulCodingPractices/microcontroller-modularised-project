#ifndef USER_BUTTON_H
#define USER_BUTTON_H

#include "stm32f7xx_hal.h"
#include "main.h"

// Function declarations
void Button_Init(void);
void Button_EnableInterrupt(void);
int Button_Pressed(void);
//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);// Returns non-zero if a rising edge is detected

#endif // USER_BUTTON_H
