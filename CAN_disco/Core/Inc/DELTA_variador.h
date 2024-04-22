/*
 * DELTA_variador.h
 *
 *  Created on: Apr 10, 2024
 *      Author: Adrián Silva Palafox
 */

#ifndef INC_DELTA_VARIADOR_H_
#define INC_DELTA_VARIADOR_H_

#include "stm32f7xx.h"

/*
 * DEFINES
 */

#define Transmitter_ID 0x001 //id DEL TRANFMITTER 11bit

/*
 * STRUCTURES
 */
typedef struct{
	float frecuencia;
	float Irms[3];
}variador;

/*
 * FUNCTIONS
 */
void CAN_init_header(uint8_t LEN_DATA);
void send_msg(CAN_HandleTypeDef *canHandler,
		CAN_TxHeaderTypeDef *TxHeader,
		uint8_t *TxData,uint32_t *TxMailbox);
void CAN_filter(void);

#endif /* INC_DELTA_VARIADOR_H_ */
