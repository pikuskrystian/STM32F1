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
//#include "stm32f1xx.h"
void delay(int time){
	int i;
	for(i=0;i<time*570;i++){}
}
//port D
//pin 11-15
int main(void)
{

	HAL_Init();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef gpio;
	gpio.Pin = GPIO_PIN_11;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;

	HAL_GPIO_Init(GPIOD, &gpio);



	while(1)
	{
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_SET); // zapalenie diody
		delay(100);
		HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, GPIO_PIN_RESET); // zgaszenie diody
		delay(400);
	}
}
