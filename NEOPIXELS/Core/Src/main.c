/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/*
 * Nativas
 */
#include <math.h>
#include <stdbool.h>

/*
 * Del usuario
 */
#include "WS2812B.h"
#include "NRF24L01.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
TIRA_t regleta_leds;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define PI 3.1416
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim1;
DMA_HandleTypeDef hdma_tim1_ch1;

/* USER CODE BEGIN PV */
uint8_t rx_data[NRF24L01P_PAYLOAD_LENGTH] = {0,0,0};
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_TIM1_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */

/*
 * Onoff
 */
void ONOFF(void);

/*
 * Efectos RGB
 */
void EFECTO1(void);
void EFECTO2(void);
void EFECTO3(void);
void EFECTO4(void);
void EFECTO5(void);

/*
 * Efectos de luz blanca
 */
void LUZ_BLANCA(uint8_t dim);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM1_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */

  /*
   * Configuramos el transciver
   * CANAL 2500Mhz
   * Baudrate en 1Mbps
   */
  nrf24l01p_rx_init(2500, _1Mbps);

  //inicializamos la bandera de la tira
  Init_tira(&regleta_leds);
  WS2812_Send(&regleta_leds);

  //Inicializamos el transciver de RF

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

	  /*
	   * Maquina de estados para
	   * efectos de RGB
	   */

	if(rx_data[0])
	{
		switch (rx_data[1])
		{//EFECTOS DE RGB
			case 0:
				EFECTO1();
				break;
			case 1:
				EFECTO2();
				break;
			case 2:
				EFECTO3();
				break;
			case 3:
				EFECTO4();
				break;
			case 4:
				EFECTO5();
				break;
			case 5:
				ONOFF();
				break;
			default:
				break;
		}
	}else
	{//EFECTOS DE LUZ BLANCA
		LUZ_BLANCA(rx_data[2]);
	}


  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 20;
  RCC_OscInitStruct.PLL.PLLN = 160;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};
  TIM_BreakDeadTimeConfigTypeDef sBreakDeadTimeConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 0;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 100-1;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCNPolarity = TIM_OCNPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  sConfigOC.OCIdleState = TIM_OCIDLESTATE_RESET;
  sConfigOC.OCNIdleState = TIM_OCNIDLESTATE_RESET;
  if (HAL_TIM_PWM_ConfigChannel(&htim1, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  sBreakDeadTimeConfig.OffStateRunMode = TIM_OSSR_DISABLE;
  sBreakDeadTimeConfig.OffStateIDLEMode = TIM_OSSI_DISABLE;
  sBreakDeadTimeConfig.LockLevel = TIM_LOCKLEVEL_OFF;
  sBreakDeadTimeConfig.DeadTime = 0;
  sBreakDeadTimeConfig.BreakState = TIM_BREAK_DISABLE;
  sBreakDeadTimeConfig.BreakPolarity = TIM_BREAKPOLARITY_HIGH;
  sBreakDeadTimeConfig.AutomaticOutput = TIM_AUTOMATICOUTPUT_DISABLE;
  if (HAL_TIMEx_ConfigBreakDeadTime(&htim1, &sBreakDeadTimeConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */
  HAL_TIM_MspPostInit(&htim1);

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA2_Stream1_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream1_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : IRQ_Pin */
  GPIO_InitStruct.Pin = IRQ_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(IRQ_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : CS_Pin */
  GPIO_InitStruct.Pin = CS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  HAL_GPIO_Init(CS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : EN_Pin */
  GPIO_InitStruct.Pin = EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(EN_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI3_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI3_IRQn);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
	HAL_TIM_PWM_Stop_DMA(&htim1, TIM_CHANNEL_1);
	regleta_leds.datasentflag = 1;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == NRF24L01P_IRQ_PIN_NUMBER)
		nrf24l01p_rx_receive(rx_data); // read data when data ready flag is set
}
/*
 * ONOFF
 */
void ONOFF(void)
{
	//Actualizamos los valores
	for (int num=0;num<MAX_LED;num++) {
		Set_LED(&regleta_leds,num,0,0,0);
	}

	//Mandamos los valores
	WS2812_Send(&regleta_leds);

	HAL_Delay(25);
}

/*
 * EFECTOS RGB
 */
uint8_t colores[3] = {0};
float N = 0; //timepo en iteracion
void EFECTO1(void)
{
	//Calculamos los colores para dar efecto
	colores[0] = (uint8_t)(254.0*((sin(N           )+1.0)/2.0));
	colores[1] = (uint8_t)(254.0*((sin(N + (2.0*PI)/3)+1.0)/2.0));
	colores[2] = (uint8_t)(254.0*((sin(N - (2.0*PI)/3)+1.0)/2.0));

	//Actualizamos los valores
	for (int num=0;num<MAX_LED;num++) {
		Set_LED(&regleta_leds,num,colores[0],colores[1],colores[2]);
	}

	//Mandamos los valores
	WS2812_Send(&regleta_leds);

	if( N <= (2.0*PI)) //Mayor a 360grados
	{
		N += PI/100; // +0.9GRADOS
	}
	else
	{
		N = 0;
	}

	HAL_Delay(15);
}
void EFECTO2(void)
{
	//Calculamos los colores para dar efecto
	switch ((uint8_t)N) {
		case 0:
			colores[0] = (uint8_t)(255);
			colores[1] = (uint8_t)(0);
			colores[2] = (uint8_t)(0);
			break;
		case 1:
			colores[0] = (uint8_t)(0);
			colores[1] = (uint8_t)(255);
			colores[2] = (uint8_t)(0);
			break;
		case 2:
			colores[0] = (uint8_t)(0);
			colores[1] = (uint8_t)(0);
			colores[2] = (uint8_t)(255);
			break;
		default:
			break;
	}

	//Actualizamos los valores
	for (int num=0;num<MAX_LED;num++) {
		Set_LED(&regleta_leds,num,colores[0],colores[1],colores[2]);
	}

	//Mandamos los valores
	WS2812_Send(&regleta_leds);

	if( N < 2)
	{
		N += 1;
	}
	else
	{
		N = 0;
	}

	HAL_Delay(750);
}
void EFECTO3(void)
{
	//Calculamos los colores para dar efecto
	switch ((uint8_t)N) {
		case 0:
			colores[0] = (uint8_t)(255);
			colores[1] = (uint8_t)(255);
			colores[2] = (uint8_t)(0);
			break;
		case 1:
			colores[0] = (uint8_t)(255);
			colores[1] = (uint8_t)(0);
			colores[2] = (uint8_t)(255);
			break;
		case 2:
			colores[0] = (uint8_t)(0);
			colores[1] = (uint8_t)(255);
			colores[2] = (uint8_t)(255);
			break;
		default:
			break;
	}

	//Actualizamos los valores
	for (int num=0;num<MAX_LED;num++) {
		Set_LED(&regleta_leds,num,colores[0],colores[1],colores[2]);
	}

	//Mandamos los valores
	WS2812_Send(&regleta_leds);

	if( N < 2)
	{
		N++;
	}
	else
	{
		N = 0;
	}

	HAL_Delay(750);
}
void EFECTO4(void)
{
	//Calculamos los colores para dar efecto
	colores[0] = (uint8_t)(254.0*((sin(N           )+1.0)/2.0));
	colores[1] = (uint8_t)(254.0*((sin(N + (2.0*PI)/3)+1.0)/4.0));
	colores[2] = (uint8_t)(254.0*((sin(N - (2.0*PI)/3)+1.0)/16.0));

	//Actualizamos los valores
	for (int num=0;num<MAX_LED;num++) {
		Set_LED(&regleta_leds,num,colores[0],colores[1],colores[2]);
	}

	//Mandamos los valores
	WS2812_Send(&regleta_leds);

	if( N <= (2.0*PI)) //Mayor a 360grados
	{
		N += PI/100; // +0.9GRADOS
	}
	else
	{
		N = 0;
	}

	HAL_Delay(15);
}
void EFECTO5(void)
{
	//Calculamos los colores para dar efecto
	colores[0] = (uint8_t)(254.0*((sin(N + PI/2)+1.0)/2.0));
	colores[1] = (uint8_t)(254.0*((sin(N)       +1.0)/2.0));
	colores[2] = (uint8_t)(254.0*((sin(N - PI/2)+1.0)/2.0));

	//Actualizamos los valores
	for (int num=0;num<MAX_LED;num++) {
		Set_LED(&regleta_leds,num,colores[0],colores[1],colores[2]);
	}

	//Mandamos los valores
	WS2812_Send(&regleta_leds);

	if( N <= (2.0*PI)) //Mayor a 360grados
	{
		N += PI/100; // +0.9GRADOS
	}
	else
	{
		N = 0;
	}

	HAL_Delay(15);
}

/*
 * EFECTO DE LUZ BLANCA
 */
void LUZ_BLANCA(uint8_t dim)
{
	/*
	 * En que punto estamos?
	 * Cuantos nos vamos a mover
	 *
	 * hot                 cold
	 * 254 <-------------> 0
	 *
	 */
	//Calculamos los colores para dar efecto
	colores[0] = dim;//R
	colores[2] = 254-dim; //G

	//Actualizamos los valores
	for (int num=0;num<MAX_LED;num++)
	{
		Set_LED(&regleta_leds,num,colores[0],110,colores[2]);
	}

	//Mandamos los valores
	WS2812_Send(&regleta_leds);

}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
