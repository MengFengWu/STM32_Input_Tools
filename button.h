/*
 * button.h
 *
 *  Created on: Apr 22, 2025
 *      Author: BIGBEE
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

// **Please change the according hal library (say, <stm32f7xx_hal.h>)**
#include <stm32l4xx_hal.h>
#include <stdint.h>

typedef void (*callback_function)(void* args);

struct Button {
	uint16_t GPIO_Pin;
	callback_function func;
};

// Initialize the given button instance
void Button_Init(struct Button* button, uint16_t GPIO_Pin, callback_function func);

// Set the GPIO_Pin for the button
void Button_Set_Pin(struct Button* button, uint16_t GPIO_Pin);

// Set the callback function for the button
void Button_Set_Callback(struct Button* button, callback_function func);

// Implement the callback function
void Button_Do_Callback(struct Button* button, uint16_t GPIO_Pin, void* args);

#endif /* INC_BUTTON_H_ */
