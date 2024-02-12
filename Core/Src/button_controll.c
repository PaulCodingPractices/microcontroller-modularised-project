#include "button_controll.h"
#include "led_control.h"
static GPIO_PinState lastButtonState = GPIO_PIN_RESET;

void Button_EnableInterrupt(void) {
    // Enable the interrupt for the button pin
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void Button_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /*Configure GPIO pin : USER_Btn_Pin */
    GPIO_InitStruct.Pin = USER_Btn_Pin;
    GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING; // Interrupt Mode
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    HAL_GPIO_Init(USER_Btn_GPIO_Port, &GPIO_InitStruct);

    // Initialize the lastButtonState variable based on the initial state of the button
    lastButtonState = HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin);
}

int Button_Pressed(void) {
    GPIO_PinState currentButtonState = HAL_GPIO_ReadPin(USER_Btn_GPIO_Port, USER_Btn_Pin);
    int pressed = (currentButtonState == GPIO_PIN_SET) && (lastButtonState == GPIO_PIN_RESET);
    lastButtonState = currentButtonState;
    return pressed;
}

//void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
//    if (GPIO_Pin == USER_Btn_Pin) {
//        // Toggle LED or handle button press event
//        LED_Toggle(GREEN_LED_PIN);
//    }
//}
