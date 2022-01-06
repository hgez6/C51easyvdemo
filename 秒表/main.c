#include "key.h"
#include "timer0.h"
#include "AT24C02.h"
#include "delay.h"
#include "xs.h"
#include <REGX52.H>
unsigned char keyn,run;
unsigned char min,sec,minsec;
void main()
{ 
	  Timer0Init();
      while(1)
     {
      keyn=key();
			 if(keyn==1)
			 {run=!run;}
			  if(keyn==2)
			 {min=0;sec=0;minsec=0;}
			  if(keyn==3)
			 {AT24C02_WriteByte(0,min);
			 delay(5);
				 AT24C02_WriteByte(1,sec);
			 delay(5);
				 AT24C02_WriteByte(2,minsec);
			 delay(5);
			 }
			 if(keyn==4)
			 {min=AT24C02_ReadByte(0);
				 sec=AT24C02_ReadByte(1);
				 minsec=AT24C02_ReadByte(2);
			 }
				 set(1,min/10);
			   set(2,min%10);
        set(3,11);
			 set(4,sec/10);
			 set(5,sec%10);
			 set(6,11);
			 set(7,minsec/10);
				set(8,minsec%10);			 
			 }			 
      }

void sec_loop()
{ if(run)
	{
		minsec++;
	if(minsec>=100)
	{ minsec=0;
		sec++;
		if(sec>=60)
		{
			sec=0;
			min++;
			if(min>=60)
			{min=0;}
		}
	}
	}
	
}
void Timer0_Routine() interrupt 1
{ static unsigned int c0,c1,c2;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	c0++;
	if(c0>=20)
	{ 
  c0=0;
		key_loop();
	}	
	c1++;
	if(c1>=2)
	{
	c1=0;
		sx_loop();
	}
	c2++;
	if(c2>=10)
	{
	c2=0;
		sec_loop();
	}
		
}


