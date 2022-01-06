#include<reg52.h> 
#include <intrins.h> 
#define uint unsigned int 
#define uchar unsigned char 
uchar temp,num,num1,temp1; 
sbit beep=P1^5; 
void delay(uint); 
void main() 
{ 

temp=0xfe; 
temp1=0x7f; 
while(1) 
{	
for(num1=0;num1<3;num1++) 
{	
for(num=0;num<8;num++) 
{ 
P2=temp; 
beep=0; 
delay(2000); 
temp=_crol_(temp,1); 
P2=0xff; 
beep=1; 
delay(2000);	
} 
} 
for(num1=0;num1<3;num1++) 
{	
for(num=0;num<8;num++) 
{ 
P2=temp1; 
beep=0; 
delay(2000); 
temp1=_cror_(temp1,1); 
P2=0xff; 
beep=1; 
delay(2000);	
} 
} 
while(1); 
} 
} 
void delay(uint z) 
{ 
uint x,y; 
for(x=z;x>0;x--) 
{ 
for(y=110;y>0;y--) 
{ 
} 
} 
}