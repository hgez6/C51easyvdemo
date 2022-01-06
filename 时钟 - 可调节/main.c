#include <REGX52.H>
#include "LCD1602.h"
#include "DS1302.h"
#include "key.h"
#include "timer0.h"
unsigned char keyn,mode,ts,flash;
void timeshow()
{
	 DS1302_readtime();
	    LCD_ShowNum(1,1,DS1302_Time[0],2);
			 LCD_ShowNum(1,4,DS1302_Time[1],2);
      	LCD_ShowNum(1,7,DS1302_Time[2],2);
			 LCD_ShowNum(2,1,DS1302_Time[3],2);
			 LCD_ShowNum(2,4,DS1302_Time[4],2);
      	LCD_ShowNum(2,7,DS1302_Time[5],2);
}
void timeset()
{
	if(keyn==2)
	{
		ts++;
		ts%=6;
	}
		if(keyn==3)
	{
		DS1302_Time[ts]++;
		if(DS1302_Time[0]>99)  DS1302_Time[0]=0;
		if(DS1302_Time[1]>12)  DS1302_Time[1]=1;
		if(DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 || DS1302_Time[1]==8 ||
    DS1302_Time[1]==10 || DS1302_Time[1]==12) 
		{
    if(DS1302_Time[2]>31 ) {DS1302_Time[2]=1;}
		}
		else if ( DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 
			|| DS1302_Time[1]==11)
		{  
			if(DS1302_Time[2]>30)  {DS1302_Time[2]=1;}
		}
		
			else if (DS1302_Time[1]==2)
			{
				if(DS1302_Time[0]%4==0)
         {if(DS1302_Time[2]>29) DS1302_Time[2]=1;}
				 else {if(DS1302_Time[2]>28) DS1302_Time[2]=1; }
			}

		if(DS1302_Time[3]>23)  DS1302_Time[3]=0;
		if(DS1302_Time[4]>59)  DS1302_Time[4]=0;
		if(DS1302_Time[5]>59)  DS1302_Time[5]=0;		
	}
	if(keyn==4)
	{
		DS1302_Time[ts]--;
		if(DS1302_Time[0]<0)  DS1302_Time[0]=99;
		if(DS1302_Time[1]<1)  DS1302_Time[1]=12;
		if(DS1302_Time[1]==1 || DS1302_Time[1]==3 || DS1302_Time[1]==5 || DS1302_Time[1]==7 || DS1302_Time[1]==8 ||
    DS1302_Time[1]==10 || DS1302_Time[1]==12) 
		{
    if(DS1302_Time[2]<1 ) {DS1302_Time[2]=31;}
		    if(DS1302_Time[2]>31 ) {DS1302_Time[2]=1;}

		}
		else if ( DS1302_Time[1]==4 || DS1302_Time[1]==6 || DS1302_Time[1]==9 
			|| DS1302_Time[1]==11)
		{  
			if(DS1302_Time[2]<1)  {DS1302_Time[2]=30;}
			if(DS1302_Time[2]>30)  {DS1302_Time[2]=1;}
		}
		
			else if (DS1302_Time[1]==2)
			{
				if(DS1302_Time[0]%4==0)
         {if(DS1302_Time[2]<1) DS1302_Time[2]=29; if(DS1302_Time[2]>29) DS1302_Time[2]=1;}
				 else {if(DS1302_Time[2]<1) DS1302_Time[2]=28; if(DS1302_Time[2]>28) DS1302_Time[2]=1;}
			}
		if(DS1302_Time[3]<0)  DS1302_Time[3]=23;
		if(DS1302_Time[4]<0)  DS1302_Time[4]=59;
		if(DS1302_Time[5]<0)  DS1302_Time[5]=59;			
	}
	if(ts==0 && flash==1) {LCD_ShowString(1,1,"  ");}
	else {LCD_ShowNum(1,1,DS1302_Time[0],2);}
	if(ts==1 && flash==1) {LCD_ShowString(1,4,"  ");}
	else {LCD_ShowNum(1,4,DS1302_Time[1],2);}
	if(ts==2 && flash==1) {LCD_ShowString(1,7,"  ");}
	else {  LCD_ShowNum(1,7,DS1302_Time[2],2);}
	if(ts==3 && flash==1) {LCD_ShowString(2,1,"  ");}
	else {	LCD_ShowNum(2,1,DS1302_Time[3],2);}
	if(ts==4 && flash==1) {LCD_ShowString(2,4,"  ");}
	else {	LCD_ShowNum(2,4,DS1302_Time[4],2);}
	if(ts==5 && flash==1) {LCD_ShowString(2,7,"  ");}
	else {  LCD_ShowNum(2,7,DS1302_Time[5],2);}
//	LCD_ShowNum(2,10,ts,2);
//	LCD_ShowNum(2,13,flash,2);
}



void main()
{   	
	DS1302_Init();  
	LCD_Init();
	Timer0Init();
	LCD_ShowString(1,1,"  -  -  ");
	LCD_ShowString(2,1,"  :  :  ");
  DS1302_settime();
      while(1)
     {   
			 keyn=key();
      if(keyn==1)  //按键1才是进入时间设置的按键
			 {
				 if(mode==0) mode=1;
				 else if(mode==1){mode=0; DS1302_settime();}			 
			 }
			switch(mode)
			{
				case 0:timeshow();break;
				case 1:timeset();break;
			}		
		 }
	 }

	 void Timer0_Routine() interrupt 1
{ 
	static unsigned int c0;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	c0++;
	if(c0>=500)
	{ 
  c0=0;
		flash=!flash;
	}
	
}



