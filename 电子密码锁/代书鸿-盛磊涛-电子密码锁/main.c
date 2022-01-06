#include <REGX52.H>
#include "delay.h"
#include "LCD1602.h"
#include "16key.h"
unsigned char key;
unsigned int pass;
unsigned int pass_1=3434;
unsigned int count;
int j=5;
sbit bz=P1^5;

void bz500us()    //@12.000MHz
{
   unsigned char i;

  
   i = 500;
   while (--i);
}

void bztime(unsigned int ms)
{       unsigned int i;
               for(i=0;i<ms*2;i++)
             {bz=!bz; bz500us();}

}

void main()
{ 
	LCD_Init();
	LCD_ShowString(1,1,"LOCK");
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
				if(j<=4)
				{
				 LCD_ShowString(1,10,"  INPUT");
				pass_1=pass;
				j++;
				}
			}
			LCD_ShowNum(2,1,pass,4);
			
	}
		if(key==13)
		{
			j=1;
			LCD_ShowString(1,10,"  REDDY");
			
			pass=0;
			count=0;
			LCD_ShowNum(2,1,0000,4);
		}
		if(key==11)
		{
			if((pass==1234)||(pass==pass_1))
			{
				LCD_ShowString(1,10,"SUCCESS");
				pass=0;
				count=0;
				LCD_ShowNum(2,1,pass,4);
				bztime(1400);

			}
			else
			{
				LCD_ShowString(1,10,"  ERROR");
				
				pass=0;
				count=0;
				LCD_ShowNum(2,1,pass,4);
			}
		}
		if(key==12)
		{
			LCD_ShowString(1,10,"LOCKING");
			pass=0;
			count=0;
			LCD_ShowNum(2,1,pass,4);
		}
	
}
	}

