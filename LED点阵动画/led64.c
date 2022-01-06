#include <REGX52.H>
#include "delay.h"

sbit RCK=P3^5;
sbit SCK=P3^6;
sbit SER=P3^4;
void hc595write(unsigned char b)
{  unsigned char i;
	for(i=0;i<8;i++)
	{
		SER=b&(0x80>>i);
	  SCK=1;
	  SCK=0;
	}
	RCK=1;
	RCK=0;
}	
void led64xs(unsigned char column,row)
{   hc595write(row);
	  P0=~(0x80>>column);
	  delay(1);
	  P0=0xFF;	
}
void led64init()
{
  SCK=0;
	RCK=0;	
}