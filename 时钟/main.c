#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"


void main()
{   	DS1302_Init();  
	LCD_Init();
		LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :  ");

 DS1302_settime();
      while(1)
     {   
			 		DS1302_readtime();
 

	    LCD_ShowNum(1,1,DS1302_Time[0],2);
			 LCD_ShowNum(1,4,DS1302_Time[1],2);
      	LCD_ShowNum(1,7,DS1302_Time[2],2);
			 LCD_ShowNum(2,1,DS1302_Time[3],2);
			 LCD_ShowNum(2,4,DS1302_Time[4],2);
      	LCD_ShowNum(2,7,DS1302_Time[5],2);
//      	LCD_ShowNum(2,10,DS1302_Time[6],2);

		 }
}


	
