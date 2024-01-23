#include "led.h"
void LED_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;//等于int a,即定义
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOD,ENABLE);  //开启时钟
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_15|GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType =GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd =GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_High_Speed ;//定义结构体 6~10
	
	GPIO_Init(GPIOC,&GPIO_InitStructure); 
	GPIO_Init(GPIOD,&GPIO_InitStructure); 
}