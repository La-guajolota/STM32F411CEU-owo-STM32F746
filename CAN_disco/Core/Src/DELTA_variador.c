/*
 * DELTA_variador.c
 *
 *  Created on: Apr 10, 2024
 *      Author: Adrián Silva Palafox
 */
#include "DELTA_variador.h"

/*
*** Polling mode operation ***
==============================
[..]
(#) Reception:
	(++) Monitor reception of message using HAL_CAN_GetRxFifoFillLevel()
		 until at least one message is received.
	(++) Then get the message using HAL_CAN_GetRxMessage().

(#) Transmission:
	(++) Monitor the Tx mailboxes availability until at least one Tx
		 mailbox is free, using HAL_CAN_GetTxMailboxesFreeLevel().
	(++) Then request transmission of a message using
		 HAL_CAN_AddTxMessage().
 */

/*------------------------------------------------------------------*/
/* 1. Encabezado de la trama (11 bits) CANopen*/
/*-------------------------------------------------------------*/
/* |  Start of Frame |     Arbitration Field    |  Control Field  */
/* |     (1 bit)     |        (11 bits)        |    (6 bits)     */
/*-------------------------------------------------------------*/
/* 2. Campo de datos (0-8 bytes) */
/*-------------------------------------------------------------*/
/* |          Data Field           |   Data Length Code   |   CRC Field    */
/* |        (0-64 bits)            |        (4 bits)      |   (15 bits)    */
/*-------------------------------------------------------------*/
/* 3. Delimitador de trama (7 bits) */
/*-------------------------------------------------------------*/
/* |  ACK Slot  |  ACK Delimiter  |  End of Frame  | Inter-frame Space |
/* |  (1 bit)   |    (1 bit)      |     (1 bit)    |     (3 bits)      |
/*------------------------------------------------------------------*/

CAN_TxHeaderTypeDef TxHEADER; //Encabezado de la trama
uint8_t TxDATA[8];
uint32_t TxMailbox;

void CAN_init_header(uint8_t LEN_DATA){
	TxHEADER.IDE = CAN_ID_STD; //Usamos ID estandar
	TxHEADER.StdId = Transmitter_ID; //ID del transmitter
	TxHEADER.RTR = CAN_RTR_DATA; //Vamos a mandar un dataframe
	TxHEADER.DLC = LEN_DATA; //Longitud de bytes que vamos a mandar
}

void send_msg(CAN_HandleTypeDef *canHandler,CAN_TxHeaderTypeDef *TxHeader,uint8_t *TxData,uint32_t *TxMailbox){
	if (HAL_CAN_AddTxMessage(canHandler, TxHeader, TxData, TxMailbox) != HAL_OK) {
		Error_Handler();
	}
}

CAN_FilterTypeDef canfilterconfig;

CAN_filter(void){
	canfilterconfig.FilterActivation = CAN_FILTER_ENABLE;
	canfilterconfig.FilterBank = 18;  // which filter bank to use from the assigned ones
	canfilterconfig.FilterFIFOAssignment = CAN_FILTER_FIFO0;
	canfilterconfig.FilterIdHigh = 0x446<<5;
	canfilterconfig.FilterIdLow = 0;
	canfilterconfig.FilterMaskIdHigh = 0x446<<5;
	canfilterconfig.FilterMaskIdLow = 0x0000;
	canfilterconfig.FilterMode = CAN_FILTERMODE_IDMASK;
	canfilterconfig.FilterScale = CAN_FILTERSCALE_32BIT;
  	canfilterconfig.SlaveStartFilterBank = 20;  // how many filters to assign to the CAN1 (master can)

  	HAL_CAN_ConfigFilter(&hcan1, &canfilterconfig);
}
