#include <REGX52.H>
#include "LCD1602.h"
#include "OneWire.h"
#include "DS18B20.h"
#include "delay.h"
#include "key.h"
#include "timer0.h"
#include "bz.h"
#include "16key.h"
sbit motor=P1^0;

unsigned char keyn,keyb,bj=0,compare=0,m=1;

float t,ts;
char TL,TH;
void main()
{  		
	    Timer0Init();
			 DS18B20_ConvertT();
	delay(1000);
//TH=AT24C02_ReadByte(0);
//bj=AT24C02_ReadByte(1);
//	 Timer0Init();
	if(TH>125 || TL<-55 || TH<=TL)
	{TH=30;TL=20;}


	 LCD_Init();
	LCD_ShowString(1,1,"T:");
	LCD_ShowString(2,1,"TH:");
		LCD_ShowString(2,9,"TL:");
	LCD_ShowString(1,11,"O");
	LCD_ShowSignedNum(2,4,TH,3);
	LCD_ShowSignedNum(2,12,TL,3);

//	ackt=OneWire_Init();   
//	LCD_ShowNum(2,1,ackt,3);   
      while(1)
     { 
			keyb=key16();
			 keyn=key();
			 DS18B20_ConvertT();
			 t=DS18B20_ReadT();
			 LCD_ShowNum(1,4,ts,3);
			 LCD_ShowChar(1,7,'.');
			 LCD_ShowNum(1,8,(unsigned long)(ts*100)%100,2);

       if(t<0 && m==1)
				 {
				 LCD_ShowChar(1,3,'-');	 ts=-t;}
			
			 else {LCD_ShowChar(1,3,'+');ts=t;}
			 if(keyb)
			 {     
				 		 if(keyb==1)
			 {
			 TH++;
				 if(TH>125) TH=125; 
			 }
			  if(keyb==2)
			 {
			 TH--;
				if(TH<=TL){TH++;}			 
			 }
			  if(keyb==3)
			 {
			 TL++;
				 if(TL>=TH){TL--;}			 
			 }
			  if(keyb==4)
			 {
			 TL--;
					 if(TL<-55) TL=-55; 

			 }
			  
				
	  LCD_ShowSignedNum(2,4,TH,3);
		LCD_ShowSignedNum(2,12,TL,3);
			 if(keyb==5)
				{
					LCD_ShowString(2,1,"                    ");

				}
				 if(keyb==6)
				{
						LCD_ShowString(2,1,"TH:");
		        LCD_ShowString(2,9,"TL:");            				
	  LCD_ShowSignedNum(2,4,TH,3);
		LCD_ShowSignedNum(2,12,TL,3);
				}
				if(keyb==7)
				{
					
					m=0;
						LCD_ShowString(1,12,"M");

				}
				
			
//		AT24C02_WriteByte(0,TH);
//delay(5);
//AT24C02_WriteByte(1,bj);
//delay(5);
			 }
			   if(keyn)
			 {	 
				 if(keyn==1)  {bj=0;	LCD_ShowString(1,11,"O");bztime(50);}
				 if(keyn==2)  {bj=1;	LCD_ShowString(1,11,"S");bztime(50);}
         if(keyn==4)  {m=1; compare=0;LCD_ShowString(1,12," ");
}

			 }
			 if(t>TH && bj==0 && m==0) {	LCD_ShowString(1,13,"OV:H");bztime(300);compare=60;}
			 else if(t>TH && bj==0 && m==1) {	LCD_ShowString(1,13,"OV:H");bztime(300);compare=0;}
				else if(t<TL && bj==0) {	LCD_ShowString(1,13,"OV:L");bztime(500);compare=0;}
else {LCD_ShowString(1,13,"       ");compare=0;}
 }
		 }


void Timer0_Routine() interrupt 1
{ static unsigned int c0;
	TL0=0x9C;		
	TH0=0xFF;		//设置定时初值
	c0++;
	c0%=100;
	if(c0<compare)
	{motor=1;}
	else
		{motor=0;}
	
}

