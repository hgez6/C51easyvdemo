#include <REGX52.H>
#include "timer0.h"
#include "key.h"
#include <INTRINS.H>
unsigned char a;
unsigned int LEDm=0;
void main()
{    
	   P2=0XFE;
     Timer0Init();
      while(1)
     {
       a=key();
			 if(a)
			 {
				 if(a==1) 
				 {  
					  LEDm++;
					  if(LEDm>=2) LEDm=0;
				 }
			 }
      }
}
void Timer0_Routine() interrupt 1
{ static unsigned int c0;
	  TL0 = 0x18;		//设置定时初值
	  TH0 = 0xFC;		//设置定时初值
	c0++;
	if(c0>=500)
	{ c0=0;
	if(LEDm==0)
		P2=_crol_(P2,1);
	if(LEDm==1)
		P2=_cror_(P2,1);
	}	
}


