/*
 * ACS712.h
 *
 *  Created on: Apr 7, 2024
 *      Author: adria
 */

#ifndef INC_ACS712_H_
#define INC_ACS712_H_

#include "stm32f7xx.h"
#include "main.h"
#include "math.h"

/*
 * Defines
 */

typedef struct{
	float RMS;//RMS current
	float FRE;//fRECUENCIA
	uint8_t channel; //Canal del adc
}ACS712;

/*
 * Funciones
 */
void ACS712_sense(ACS712* modulo);

#endif /* INC_ACS712_H_ */
