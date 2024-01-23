#include "tim.h"
#include "led.h"
#include "bee.h"
unsigned char NOTE_SY[]={1,1,5,5,6,6,5 ,4,4,3,3,2,2,1,5,5,4,4,3,3,2,5,5,4,4,3,3,2,1,1,5,5,6,6,5,4,4,3,3,2,2,1};
unsigned char PSC_Init[]= {37,33,29,28,24,22,19};	


void TIM3_Init(u16 arr,u16 psc)
{
	TIM_TimeBaseInitTypeDef TIM_BaseInitStructure;
    NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	
	TIM_BaseInitStructure.TIM_Period = arr-1;
	TIM_BaseInitStructure.TIM_Prescaler = psc-1;
	TIM_BaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;//向上计数
	TIM_BaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3,&TIM_BaseInitStructure);
	
	//
	NVIC_InitStructure.NVIC_IRQChannel =  TIM3_IRQn ;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0x00;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);//定时器3的中断使能
	TIM_Cmd(TIM3, ENABLE);//打开中断
	
}
uint16_t Time_GetCounter(void)
{
	return TIM_GetCounter(TIM2);	//返回定时器TIM2的CNT
}
int s;
int h;
int m;
	//定时器3中断服务函数
void TIM3_IRQHandler(void)
{
	 
	if(TIM_GetITStatus(TIM3,TIM_IT_Update)==SET) //溢出中断
	{
		s++;
		
	}
	TIM_ClearITPendingBit(TIM3,TIM_IT_Update);  //清除中断标志位
}

