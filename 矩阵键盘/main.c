#include <REGX52.H>
#include "delay.h"
#include "LCD1602.h"
#include "16key.h"
unsigned char key;
void main()
{ 
	LCD_Init();
	LCD_ShowString(1,1,"ELOO");
	while(1)
	{
		key=key16();
		if(key)
			LCD_ShowNum(2,1,key,2);
			
	}
}

