/*
 * encoder.c
 *
 *  Created on: Apr 22, 2025
 *      Author: BIGBEE
 */


#include "encoder.h"

static uint8_t Encoder_Nullptr_Flag = 0;

void Encoder_Init(struct Encoder* encoder, TIM_HandleTypeDef* htim) {
	if(encoder != NULL) {
		HAL_TIM_Encoder_Start(htim, TIM_CHANNEL_ALL);
		encoder->counter = 0;
		encoder->zero = 0;
		encoder->htim = htim;
		Encoder_Nullptr_Flag = 0;
	}
	else {
		Encoder_Nullptr_Flag = 1;
	}
}

int16_t Encoder_Read(struct Encoder* encoder) {
	if(encoder != NULL) {
		encoder->counter = (int16_t)__HAL_TIM_GET_COUNTER(encoder->htim);
		Encoder_Nullptr_Flag = 0;
		return encoder->counter - encoder->zero;
	}
	else {
		Encoder_Nullptr_Flag = 1;
		return 0;
	}
}

void Encoder_Zero(struct Encoder* encoder) {
	if(encoder != NULL) {
		Encoder_Read(encoder);
		encoder->zero = encoder->counter;
		Encoder_Nullptr_Flag = 0;
	}
	else {
		Encoder_Nullptr_Flag = 1;
	}
}
