#ifndef INC_TERMINAL_CONTROL_H_
#define INC_TERMINAL_CONTROL_H_

#include "stm32f7xx_hal.h"
#include "main.h"// Include the main HAL header relevant to your STM32 series

// Function prototypes
void Terminal_Init(void);
void Terminal_SendString(const char* str);

#endif
