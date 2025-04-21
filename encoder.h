/*
 * encoder.h
 *
 *  Created on: Apr 22, 2025
 *      Author: BIGBEE
 */

#ifndef INC_ENCODER_H_
#define INC_ENCODER_H_

// **Please change the according hal library (say, <stm32f7xx_hal.h>)**
#include <stm32l4xx_hal.h>
#include <stdint.h>

struct Encoder {
	TIM_HandleTypeDef* htim;
	int16_t counter;
	int16_t zero;
};

// Initialize the given encoder instance using the given timer
void Encoder_Init(struct Encoder* encoder, TIM_HandleTypeDef* htim);

// Read the value of the encoder
int16_t Encoder_Read(struct Encoder* encoder);

// Reset the value of the encoder to zero
void Encoder_Zero(struct Encoder* encoder);

#endif /* INC_ENCODER_H_ */
