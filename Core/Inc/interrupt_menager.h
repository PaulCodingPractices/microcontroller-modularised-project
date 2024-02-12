#ifndef INTERRUPT_MANAGER_H_
#define INTERRUPT_MANAGER_H_

#include "stm32f7xx_hal.h" // Adjust for your specific STM32 series

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*GPIO_CallbackFunction_t)(uint16_t GPIO_Pin);

void InterruptManager_Init(void);
void Register_GPIO_Callback(uint16_t GPIO_Pin, GPIO_CallbackFunction_t Callback);

#ifdef __cplusplus
}
#endif

#endif
