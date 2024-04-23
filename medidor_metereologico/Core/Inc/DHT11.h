/*
 * DHT11.h
 *
 *  Created on: Apr 19, 2024
 *      Author: adria
 */

#ifndef INC_DHT11_H_
#define INC_DHT11_H_

#include "stm32f1xx.h"
#include "main.h"

/*
 * FUNCIONES
 */
void DHT11_init(void);
uint8_t DHT11_Check_Response (void);
uint8_t DHT11_Read (void);

void DHT22_init(void);
uint8_t DHT22_Check_Response (void);
uint8_t DHT22_Read (void);

#endif /* INC_DHT11_H_ */
