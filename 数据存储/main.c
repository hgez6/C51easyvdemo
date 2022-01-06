#include <REGX52.H>
#include "LCD1602.h"
#include "key.h"
#include "AT24C02.h"
#include "delay.h"
unsigned char keyn;
unsigned int a;
void main()
{ 
	    LCD_Init();
				LCD_ShowNum(1,1,a,5);
//	AT24C02_WriteByte(1,166);
//	delay(5);
//	a=AT24C02_ReadByte(1);
//	LCD_ShowNum(2,1,a,3);


      while(1)
     {
			 keyn=key();
      if(keyn==1)
			{
				a++;
				LCD_ShowNum(1,1,a,5);
			}
			  if(keyn==2)
			{
				a--;
				LCD_ShowNum(1,1,a,5);
			}
			  if(keyn==3)
			{
				
			AT24C02_WriteByte(0,a%256);
					delay(5);
		AT24C02_WriteByte(1,a/256);
delay(5);
				LCD_ShowString(2,1,"WRITE OK");
				delay(1000);
								LCD_ShowString(2,1,"        ");
			}
			 if(keyn==4)
			{
	a=AT24C02_ReadByte(0);
				a|=AT24C02_ReadByte(1)<<8;
								LCD_ShowNum(1,1,a,5);

								LCD_ShowString(2,1,"READ OK");
				delay(1000);
								LCD_ShowString(2,1,"        ");
			}
      }
}


