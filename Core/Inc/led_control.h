// led_control.h

#ifndef LED_CONTROL_H
#define LED_CONTROL_H

#include "stm32f7xx_hal.h"  
#include "main.h"

// Macro definitions for LED pins
#define GREEN_LED_PIN   LD1_Pin
#define RED_LED_PIN     LD3_Pin
#define BLUE_LED_PIN    LD2_Pin

// Macro for the GPIO port
#define LED_GPIO_PORT   GPIOB

// Function declarations
void LED_Init(void);
void SwitchLEDs(void);
void LED_Toggle(uint16_t LED_PIN);

#endif // LED_CONTROL_H
