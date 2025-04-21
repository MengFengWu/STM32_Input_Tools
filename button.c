/*
 * button.c
 *
 *  Created on: Apr 22, 2025
 *      Author: BIGBEE
 */

#include "button.h"

static uint8_t Button_Nullptr_Flag = 0;
static uint8_t Button_Callback_Nullptr_Flag = 0;

void Button_Init(struct Button* button, uint16_t GPIO_Pin, callback_function func) {
	if(button != NULL) {
		button->GPIO_Pin = GPIO_Pin;
		button->func = func;
		Button_Nullptr_Flag = 0;
	}
	else {
		Button_Nullptr_Flag = 1;
	}
}

void Button_Set_Pin(struct Button* button, uint16_t GPIO_Pin) {
	if(button != NULL) {
		button->GPIO_Pin = GPIO_Pin;
		Button_Nullptr_Flag = 0;
	}
	else {
		Button_Nullptr_Flag = 1;
	}
}

void Button_Set_Callback(struct Button* button, callback_function func) {
	if(button != NULL) {
		button->func = func;
		Button_Nullptr_Flag = 0;
	}
	else {
		Button_Nullptr_Flag = 1;
	}
}

void Button_Do_Callback(struct Button* button, uint16_t GPIO_Pin, void* args) {
	if(button != NULL) {
		if(button->GPIO_Pin == GPIO_Pin) {
			if(button->func != NULL) {
				(button->func)(args);
				Button_Callback_Nullptr_Flag = 0;
			}
			else {
				Button_Callback_Nullptr_Flag = 1;
			}
		}
		Button_Nullptr_Flag = 0;
	}
	else {
		Button_Nullptr_Flag = 1;
	}
}
