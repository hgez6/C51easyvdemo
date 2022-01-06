#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char  
sbit beep=P1^5;
void delay(uint b)
{
while(b--);
}

void sound(uint c)
{
 if(c==0)
 beep=1;
 else
 {
 while(1)
 {
 beep=~beep;
 delay(c);
 }
 }
}

void main()
{  
 uint i=0,ks=1,a;
 P2=0x00;
   delay(10000);
   P2=0xfe;
   delay(10000);
   for(a=1;a<=7;a++)
   {
	P2=_crol_(P2,1);
   delay(10000);
   
   }
while(1)
{
 
   if(i%2==0)
   {	   
   P2=0xfe;
   delay(1000);
	}
	else
	{
	P2=0xfd;
   delay(10000);
   }  
   for(a=1;a<=3;a++)
   {
   P2=_crol_(P2,2);
   delay(1000); 
	}
	i++;
}
}
