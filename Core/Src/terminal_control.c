#include "terminal_control.h"
#include <stdint.h>
#include <string.h>
#include "stm32f7xx_hal.h" // Adjust this include to match your specific STM32 series
#include "button_controll.h"
#include "led_control.h"

extern UART_HandleTypeDef huart3;

void Terminal_Init(void) {
    huart3.Instance = USART3; // Make sure USART3 is defined in your MCU's HAL
    huart3.Init.BaudRate = 9600;
    huart3.Init.WordLength = UART_WORDLENGTH_8B;
    huart3.Init.StopBits = UART_STOPBITS_1;
    huart3.Init.Parity = UART_PARITY_NONE;
    huart3.Init.Mode = UART_MODE_TX_RX;
    huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
    huart3.Init.OverSampling = UART_OVERSAMPLING_16;
    huart3.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
    huart3.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
    if (HAL_UART_Init(&huart3) != HAL_OK) // Make sure to use huartx here
    {
        Error_Handler(); // Ensure Error_Handler is defined somewhere in your project
    }
}

void Terminal_SendString(const char* str) {
    HAL_UART_Transmit(&huart3, (uint8_t*)str, strlen(str), HAL_MAX_DELAY); // Cast to (uint8_t*) is correct
}

// Ensure you have defined USER_Btn_Pin and GREEN_LED_PIN somewhere in your project
//void Terminal_EXTI_Callback(uint16_t GPIO_Pin) {
//    if (GPIO_Pin == USER_Btn_Pin) {
//        LED_Toggle(GREEN_LED_PIN); // Ensure LED_Toggle is defined and correctly implemented
//        Terminal_SendString("USER button pressed\r\n");
//    }
//}
