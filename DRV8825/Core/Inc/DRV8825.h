/*
 * DRV8825.h
 *
 *  Created on: May 29, 2024
 *      Author: Adrián Silva Palafox
 */

#ifndef INC_DRV8825_H_
#define INC_DRV8825_H_

/*
 * Includes nativos del STM32
 */
#include "main.h"
#include "stm32f1xx.h"

/*
 * Includes del usuario
 */

/*
 * Inlcudes de C nativo
 */

/*
 * Defines
 */
//Para el pin de ENEABLE
#define OFF_DRIVER 0x01
#define ON_DRIVER 0X00

//define para el RESET
//ACTIVE-LOW
#define RESET_DISABLE 0x00
#define RESET_ENABLE 0x01

//defines para el SLEEP
#define SLEEP_DISABLE_LOW_POWER  0x00
#define SLEEP_ENABLE_DIVICE 0x01

//Modos de operacion del chip
#define FULL_STEP 0b000
#define HALF_STEP 0b001
#define QUARTER_STEP 0b010
#define EIGHT_MICRO_STEP 0b011
#define SIXTEEN_MICRO_STEP 0b100
#define THIRTYTWO_MICRO_STEP 0b101

/*
 * Structs
 */
typedef struct
{
	uint8_t state; //Habilitado o no
	uint8_t mode; //Modo de operacion del IC
	uint8_t dir;//Sentido de giro
	uint32_t step;//Cardinalidad del paso
	uint32_t steps_max;//Cantidad maxima de pasos
}DRV8825_t;

/*
 * Funciones
 */
void init_driver(DRV8825_t* driver,uint32_t steps_max);
void move_steps(DRV8825_t* driver,uint8_t dir, uint8_t mode, uint32_t steps);
void move(DRV8825_t* driver,uint8_t dir, uint8_t mode);
void stop(DRV8825_t* driver);


#endif /* INC_DRV8825_H_ */