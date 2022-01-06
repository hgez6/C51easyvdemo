#include <REGX52.H>
#include "delay.h"
unsigned char cache[9]={0,10,10,10,10,10,10,10,10};
unsigned char xx[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x00,0x40};
void set(unsigned loca,num)
{ cache[loca]=num;}
	

void sx(unsigned char x,y)
{   P0=0x00;
   	 switch(x)
	 {
	   case 1:P2_4=1;P2_3=1;P2_2=1; break;
     case 2:P2_4=1;P2_3=1;P2_2=0; break;
     case 3:P2_4=1;P2_3=0;P2_2=1; break;
case 4:P2_4=1;P2_3=0;P2_2=0; break;
case 5:P2_4=0;P2_3=1;P2_2=1; break;
case 6:P2_4=0;P2_3=1;P2_2=0; break;
case 7: P2_4=0;P2_3=0;P2_2=1; break;
case 8:P2_4=0;P2_3=0;P2_2=0; break;
				}
	P0=xx[y];
//	delay(1);
//	P0=0x00;
	}
//void main()
//{  
//while(1)
//{
//  sx(1,1);
//  delay(2);
//  sx(2,2);
//   delay(2);
//  sx(3,3);
//   delay(2);
//}
//}
void sx_loop()
{
	static unsigned char i;
	sx(i,cache[i]);
	i++;
	if(i>=9)
		i=1;
}	
   