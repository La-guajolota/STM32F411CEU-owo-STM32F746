/*
 * WS2812B.c
 *
 *  Created on: May 26, 2024
 *      Author: Adrian Siva Palafox
 */

/*
 * Includes
 */
#include "WS2812B.h"

/*
 * Varibles
 */
uint16_t pwmData[(24*MAX_LED)+50]; //Data completa a transmitir

extern TIM_HandleTypeDef htim1;
extern DMA_HandleTypeDef hdma_tim1_ch1;

/*
 * DEFINES
 */
#define pwm_timer &htim1
#define pwm_channel TIM_CHANNEL_1
#define dma_pwm &hdma_tim1_ch1

/*
 * Funciones
 */
void Set_LED(TIRA_t* regleta,uint8_t led_num,uint8_t R,uint8_t G,uint8_t B)
{
	regleta->LEDS[led_num].RGB[0] = R;
	regleta->LEDS[led_num].RGB[1] = G;
	regleta->LEDS[led_num].RGB[2] = B;
}

void Init_tira(TIRA_t* regleta)
{
	regleta->datasentflag = 0;
	for (int num=0;num<MAX_LED;num++) {
		Set_LED(regleta,num,0,0,0);
	}
}

void WS2812_Send (TIRA_t* regleta)
{
	uint32_t indx = 0;
	uint32_t color; //8bits_G 8bits_R 8bits_B

	//Iteramos N leds rgb de la tira
	for (int led_num=0; led_num<MAX_LED; led_num++)
	{
		color = ((regleta->LEDS[led_num].RGB[1]<<16) | (regleta->LEDS[led_num].RGB[0]<<8) | (regleta->LEDS[led_num].RGB[2]));

		for (int i=23; i>=0; i--)//Iteramos por la trama total
		{
			if (color&(1<<i))//Enmascaramos para sacar los bits
			{
				//Logico 1
				pwmData[indx] = 66;  // 2/3 de 99
			}
			else
			{
				//Logico 0
				pwmData[indx] = 33;  // 1/3 de 99
			}
			indx++;
		}
	}

	//Llenamos de ceros RESET
	for (int i=0; i<50; i++)
	{
		pwmData[indx] = 0;
		indx++;
	}

	//Mandamos data al DMA
	HAL_TIM_PWM_Start_DMA(pwm_timer, pwm_channel, (uint32_t *)pwmData, indx);
	while (!regleta->datasentflag){};
	regleta->datasentflag = 0;
}
