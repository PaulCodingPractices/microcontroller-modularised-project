// led_control.c

#include "led_control.h"

// Variable to keep track of the last LED that was on
static int last_led = 2; // Start with the last LED so the first LED (green) starts first

void LED_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    /*Configure GPIO pins : GREEN_LED_PIN RED_LED_PIN BLUE_LED_PIN */
    GPIO_InitStruct.Pin = GREEN_LED_PIN | RED_LED_PIN | BLUE_LED_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
    HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

    // Initially turn off all LEDs
    HAL_GPIO_WritePin(LED_GPIO_PORT, GREEN_LED_PIN | RED_LED_PIN | BLUE_LED_PIN, GPIO_PIN_RESET);
}

void LED_Toggle(uint16_t LED_PIN) {
    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);
}

void SwitchLEDs(void) {
    // Turn off all LEDs
    HAL_GPIO_WritePin(LED_GPIO_PORT, GREEN_LED_PIN | RED_LED_PIN | BLUE_LED_PIN, GPIO_PIN_RESET);

    // Move to the next LED
    last_led = (last_led + 1) % 3;

    // Turn on the next LED
    switch(last_led) {
        case 0:
            HAL_GPIO_WritePin(LED_GPIO_PORT, GREEN_LED_PIN, GPIO_PIN_SET);
            break;
        case 1:
            HAL_GPIO_WritePin(LED_GPIO_PORT, RED_LED_PIN, GPIO_PIN_SET);
            break;
        case 2:
            HAL_GPIO_WritePin(LED_GPIO_PORT, BLUE_LED_PIN, GPIO_PIN_SET);
            break;
    }
}
