#include <REGX52.H>
#include "LCD1602.h"
#include "delay.h"
unsigned int i;
char x[]={'T','O','O','L',' ','B','O','X',' ','B','Y',' ','H','G','E'};
void main()
{
	LCD_Init();
//	LCD_ShowChar(1,1,'A');
//	LCD_ShowString(1,2,"HGE-NB");
//	LCD_ShowNum(2,1,666,3);
//	LCD_ShowSignedNum(2,1,666,3);
	while(1)
	{
			if(P3_1==0)
   {
      delay(20);
	  while(P3_1==0);
	    delay(20);
		 for(i=0;i<=14;i++)
		 {
			 LCD_ShowChar(1,2+i,x[i]);
			 delay(300);
		 }
		 
		 
	}

}	
	}
