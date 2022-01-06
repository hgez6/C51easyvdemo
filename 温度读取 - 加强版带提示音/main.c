#include <REGX52.H>
#include "LCD1602.h"
#include "OneWire.h"
#include "DS18B20.h"
#include "delay.h"
#include "key.h"
#include "AT24C02.h"
#include "timer0.h"
#include "bz.h"

unsigned char keyn;
float t,ts;
char TL,TH;
void main()
{  		
			 DS18B20_ConvertT();
	delay(1000);
TH=AT24C02_ReadByte(0);
TL=AT24C02_ReadByte(1);
	 Timer0Init();
	if(TH>125 || TL<-55 || TH<=TL)
	{TH=20;TL=15;}


	 LCD_Init();
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(2,1,"TH:");
	LCD_ShowString(2,9,"TL:");
	LCD_ShowSignedNum(2,4,TH,3);
	LCD_ShowSignedNum(2,12,TL,3);

//	ackt=OneWire_Init();
//	LCD_ShowNum(2,1,ackt,3);
      while(1)
     { 
			 keyn=key();
			 DS18B20_ConvertT();
			 t=DS18B20_ReadT();
			 LCD_ShowNum(1,4,ts,3);
			 LCD_ShowChar(1,7,'.');
			 LCD_ShowNum(1,8,(unsigned long)(ts*100)%100,2);

       if(t<0)
				 {
				 LCD_ShowChar(1,3,'-');	 ts=-t;}
			
			 else {LCD_ShowChar(1,3,'+');ts=t;}
			 if(keyn)
			 {     
				 		 if(keyn==1)
			 {
			 TH++;
				 if(TH>125) TH=125; 
			 }
			  if(keyn==2)
			 {
			 TH--;
				if(TH<=TL){TH++;}			 
			 }
			  if(keyn==4)
			 {
			 TL++;
				 if(TL>=TH){TL--;}			 
			 }
			  if(keyn==3)
			 {
			 TL--;
					 if(TL<-55) TL=-55; 

			 }
	  LCD_ShowSignedNum(2,4,TH,3);
		LCD_ShowSignedNum(2,12,TL,3);
		AT24C02_WriteByte(0,TH);
delay(5);
AT24C02_WriteByte(1,TL);
delay(5);
			 }
			 if(t>TH) {	LCD_ShowString(1,13,"OV:H");bztime(300);}
				else if(t<TL) {	LCD_ShowString(1,13,"OV:L");bztime(500);}
else LCD_ShowString(1,13,"       ");
 }
		 }
//			 void Timer0_Routine() interrupt 1
//{ static unsigned int c0;
//	TL0 = 0x18;		//设置定时初值
//	TH0 = 0xFC;		//设置定时初值
//	c0++;
//	if(c0>=20)
//	{ 
//  c0=0;
//		key_loop();
//	}
//	
}


