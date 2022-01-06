#include <REGX52.H>
#include "delay.h"
#include "LCD1602.h"
#include "16key.h"
unsigned char key;
unsigned int pass;
unsigned int count;
void main()
{ 
	LCD_Init();
	LCD_ShowString(1,1,"ELOO");
	while(1)
	{
		key=key16();
		if(key)
		{
			if(key<=10)
			{ if(count<4)
				{
				pass*=10;
				pass+=key%10;
				}
				count++;
			}
			LCD_ShowNum(2,1,pass,4);
			
	}
		if(key==11)
		{
			if(pass==2345)
			{
				LCD_ShowString(1,14,"OK ");
				pass=0;
				count=0;
				LCD_ShowNum(2,1,pass,4);

			}
			else
			{
				LCD_ShowString(1,14,"ERR");
				pass=0;
				count=0;
				LCD_ShowNum(2,1,pass,4);
			}
		}
		if(key==12)
		{
			pass=0;
			count=0;
			LCD_ShowNum(2,1,pass,4);
		}
}
	}

