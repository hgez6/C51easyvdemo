#include <REGX52.H>
#include "timer0.h"
sbit OneWire_DQ=P3^7;
unsigned char OneWire_Init()
{ 
	unsigned char i,ack;
	EA=0;
	OneWire_DQ=1;
	OneWire_DQ=0;
  i = 247;
	while (--i);
	OneWire_DQ=1;
	i = 32;
	while (--i);
 ack=OneWire_DQ;
	  i = 247;
	while (--i);
		EA=1;
	return ack;

}
void OneWire_SendBit(unsigned char b)
{
	unsigned char i;
  OneWire_DQ=0;
		  i=4;
	 EA=0;
	while (--i);
	  OneWire_DQ=b;
	i = 24;
	while (--i);
		  OneWire_DQ=1;
	EA=1;
}
unsigned char OneWire_ReceiveBit()
{
 unsigned char i,b;
	  OneWire_DQ=0;
	i = 2;
	EA=0;
	while (--i);
		  OneWire_DQ=1;
 	i = 2;
	while (--i);
		  b=OneWire_DQ;
		i = 24;
	while (--i);
	EA=1;
return b;

}
void OneWire_SendByte(unsigned char Byte)
{ 
	unsigned char i;
	for(i=0;i<8;i++)
	{
	OneWire_SendBit(Byte&(0x01<<i));
	}
	
}
unsigned char OneWire_ReceiveByte()
{
unsigned char i;
unsigned char Byte=0x00;
for(i=0;i<8;i++)
{
if(OneWire_ReceiveBit()) {Byte|=(0x01<<i);}
}
return Byte;

}







