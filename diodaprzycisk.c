#include "stm32f1xx.h"
			
int main(void)
{
	HAL_Init();
 
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
 
	GPIO_InitTypeDef gpio;
	gpio.Pin = GPIO_PIN_5;
	gpio.Mode = GPIO_MODE_OUTPUT_PP;
	gpio.Pull = GPIO_NOPULL;
	gpio.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOA, &gpio);
 
	gpio.Pin = GPIO_PIN_13; 	// konfigurujemy pin 13
	gpio.Mode = GPIO_MODE_INPUT; 	// jako wejście
	gpio.Pull = GPIO_PULLUP;		// włączamy rezystor podciągający
	HAL_GPIO_Init(GPIOC, &gpio);	// port GPIOC
 
	while (1)
	{
		if (HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) { // jesli przycisk jest przycisniety,
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET); // zapal diode
		} else {
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
		}
	}
}
