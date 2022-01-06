#include <REGX52.H>
#include "delay.h"
#include "LCD1602.h"
#include "timer0.h"
unsigned char sec,min,hour;
void main()
{     LCD_Init();
	Timer0Init();
	LCD_ShowString(1,1,"Clock:");
      while(1)
     {
			 if(sec==60)
	{ 
		min++;
	  sec=0;
	}
	if(min==60)
	{ 
		hour++;
	  min=0;
	}
      LCD_ShowNum(2,1,hour,2);
	LCD_ShowString(2,3,":");
	LCD_ShowNum(2,4,min,2);
	LCD_ShowString(2,6,":");
	LCD_ShowNum(2,7,sec,2);

	
	
	
	    
      }
}
void Timer0_Routine() interrupt 1
{ static unsigned int c0;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	c0++;
	if(c0>=1000)
	{ 
  c0=0;
	sec++;
	
		
	}
	
}


