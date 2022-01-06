#include <REGX52.H>
#include "LCD1602.h"
#include "OneWire.h"
#include "DS18B20.h"
#include "delay.h"

float t;
void main()
{  			 DS18B20_ConvertT();
delay(800);
	  LCD_Init();
	LCD_ShowString(1,1,"temperature:");
//	ackt=OneWire_Init();
//	LCD_ShowNum(2,1,ackt,3);
      while(1)
     { 
			 DS18B20_ConvertT();
			 t=DS18B20_ReadT();
       if(t<0)
				 {LCD_ShowChar(2,1,'-');	 t=-t;}
			
			 else {LCD_ShowChar(2,1,'+');}
			 LCD_ShowNum(2,2,t,3);
			 LCD_ShowChar(2,5,'.');
			 LCD_ShowNum(2,6,(unsigned long)(t*10000)%10000,4);
			 
			 }
}

