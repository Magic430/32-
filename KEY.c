#include "stm32f10x.h"                  // Device header
#include "Delay.h"

void Key_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_4) == 0);
		Delay_ms(20);
		KeyNum = 1;
	}
	if (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5) == 0)
	{
		Delay_ms(20);
		while (GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_5) == 0);
		Delay_ms(20);
		KeyNum = 2;
	}
	
	return KeyNum;
}
