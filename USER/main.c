#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
#include "sys.h"
#include "led.h"
#include "tim.h"
#include "bee.h"
#include "oled.h"
#include "tim.h"

extern int s;
extern int h;
extern int m;
int main(void)
{
	delay_init(168);
	
	OLED_Init();
	TIM3_Init(8400,10000);
	
  while(1){
	  OLED_ShowSignedNum(1, 9,s , 2);
	if(h>=24){
		h = 0;
		}
	if(m>=60){
		m=0;
		h++;
			
	  OLED_ShowSignedNum(4, 1, h, 2);
	
		}
	if(s>=60){
		s = 0;
		m ++;
			
	  OLED_ShowSignedNum(3, 1,m , 2);
  
		}
		
        
		
}
  }

	
	
 
