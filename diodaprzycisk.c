/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */


#include "stm32f4xx.h"


int main(void)
{


	//port D
	//12 dioda led



	//przycisk
	//PA0
	// pord A | pin 0

	HAL_Init();

	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();


	//dioda
	GPIO_InitTypeDef gpio;
	gpio.Pin = GPIO_PIN_12;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD, &gpio);


	//przycisk
	gpio.Pin = GPIO_PIN_0;
	gpio.Mode = GPIO_MODE_INPUT;
	gpio.Pull = GPIO_PULLUP;
	HAL_GPIO_Init(GPIOA,  &gpio);



	while(1)
	{
		if (HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0) == GPIO_PIN_RESET) { // jesli przycisk jest przycisniety,
					HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET); // zapal diode
				} else {
					HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_RESET);
				}
			}
	}

