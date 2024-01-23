#include "exti.h"  
#include "led.h" 
#include "bee.h"  
// 函数：按键IO口初始化
//
volatile unsigned  char LED_num = 0;
volatile unsigned   int flag=0;
 volatile unsigned   int key=1;
void exti_Init(void)
{		
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);  //使能外部中断，外部中断 EXTI 在APB2总线上
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);  //GPIO初始化
	
	GPIO_InitTypeDef GPIO_InitStructure; //结构体
	EXTI_InitTypeDef EXTI_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4; //选中引脚
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN; //输入模式
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;  //上拉输入
	GPIO_Init(GPIOD, &GPIO_InitStructure);
	
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource3); //PD3连接到中断线	,就是将管脚3接到中断线上
	/* 配置exit3线的中断 */	
	EXTI_InitStructure.EXTI_Line = EXTI_Line3;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//中断事件
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; // 下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOD, EXTI_PinSource4);
	/* 配置exit4线的中断 */		
	EXTI_InitStructure.EXTI_Line = EXTI_Line4;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;//中断事件
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Falling; // 下降沿触发
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel = EXTI3_IRQn;//外部中断3
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00; // 设置中断抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00; // 设置中断响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

	NVIC_InitStructure.NVIC_IRQChannel = EXTI4_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00; // 设置中断抢占优先级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00; // 设置中断响应优先级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);	
}




void EXTI4_IRQHandler(void) 
{
    if (EXTI_GetITStatus(EXTI_Line4) != RESET) 
		{
			key=2;
				
		 	}
			
      
        EXTI_ClearITPendingBit(EXTI_Line4);
    }
