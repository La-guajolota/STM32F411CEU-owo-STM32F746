/*
 * DRV8825.c
 *
 *  Created on: May 29, 2024
 *      Author: Adrián Silva Palafox
 */

/*
 * Inlcudes
 */
#include "DRV8825.h"

/*
 * Variables
 */
extern TIM_HandleTypeDef htim2;

uint16_t PERIODO = 0;

#define timer &htim2
#define channel TIM_CHANNEL_1
#define half_duty (PERIODO/2)

/*
 * Pines de control
 * Repetir segun la cantidad de drivers
 */

/*
 * Definicion de los prototipados
 */
void init_driver(DRV8825_t* driver,uint32_t steps_max)
{
	//Inhabilitamos el driver
	HAL_GPIO_WritePin(ENABLE_GPIO_Port, ENABLE_Pin, OFF_DRIVER);

	//Active-low reset input initializes the indexer logic and
	//disables the nRESET 16 I Reset input H-bridge outputs
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, RESET_DISABLE);
	HAL_Delay(1);
	HAL_GPIO_WritePin(RESET_GPIO_Port, RESET_Pin, RESET_ENABLE);

	//Entramos a bajo consumo
	HAL_GPIO_WritePin(SLEEP_GPIO_Port, SLEEP_Pin, SLEEP_DISABLE_LOW_POWER);

	//Seteamos a un dutycycle de 50%
	__HAL_TIM_SET_COMPARE(timer,channel,half_duty);

	//defaults
	driver->dir = 0;
	driver->mode = FULL_STEP;
	driver->state = OFF_DRIVER;
	driver->step = 0;
	driver->steps_max = steps_max;
}

void stop(DRV8825_t* driver)
{
	//Deshabilitamos las salidas
	HAL_GPIO_WritePin(ENABLE_GPIO_Port, ENABLE_Pin, OFF_DRIVER);
	HAL_TIM_PWM_Stop_IT(timer,channel);

	//SALIMOS DEL SLEEP
	HAL_GPIO_WritePin(SLEEP_GPIO_Port, SLEEP_Pin, SLEEP_ENABLE_DIVICE);

}

void move(DRV8825_t* driver,uint8_t dir, uint8_t mode)
{
	//Deshabilitamos las salidas
	HAL_GPIO_WritePin(ENABLE_GPIO_Port, ENABLE_Pin, OFF_DRIVER);
	HAL_TIM_PWM_Stop_IT(timer,channel);
	//Direcion de giro
	HAL_GPIO_WritePin(DIR_GPIO_Port,DIR_Pin,dir);

	//Valores del driver en cunetion
	driver->mode = mode;
	driver->state = ON_DRIVER;
	driver->dir = dir;

	//Direcion de giro
	HAL_GPIO_WritePin(DIR_GPIO_Port,DIR_Pin,dir);

	//Modo de operacion
	HAL_GPIO_WritePin(MODE0_GPIO_Port, MODE0_Pin,mode&0b001);
	HAL_GPIO_WritePin(MODE1_GPIO_Port, MODE1_Pin,(mode&0b010)>>1);
	HAL_GPIO_WritePin(MODE2_GPIO_Port, MODE2_Pin,(mode&0b100)>>2);

	//HABILITAMOS EL DRIVER
	HAL_GPIO_WritePin(ENABLE_GPIO_Port, ENABLE_Pin, ON_DRIVER);

	//Mandamos los steps
	switch (mode) {
		case FULL_STEP:
			PERIODO = 1000;
			break;
		case HALF_STEP:
			PERIODO = 500;
			break;
		case QUARTER_STEP:
			PERIODO = 250;
			break;
		case EIGHT_MICRO_STEP:
			PERIODO = 125;
			break;
		case SIXTEEN_MICRO_STEP:
			PERIODO = 62;
			break;
		case THIRTYTWO_MICRO_STEP:
			PERIODO = 31;
			break;
		default:
			PERIODO = 0;
			break;
	}
	__HAL_TIM_SET_AUTORELOAD(timer,PERIODO);
	__HAL_TIM_SET_COMPARE(timer,channel,half_duty);
	HAL_TIM_PWM_Start_IT(timer,channel);

}

void move_steps(DRV8825_t* driver,uint8_t dir, uint8_t mode, uint32_t steps)
{

}
