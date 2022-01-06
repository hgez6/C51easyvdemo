#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char  


void delay(uint);
void main()
{

 uint i=0,a;
 P2=0x00;
   delay(100);
   P2=0xfe;
   delay(100);
   for(a=1;a<=7;a++)
   {
	P2=_crol_(P2,1);
   delay(100);
   
   }
while(1)
{
   
   if(i%2==0)
   {	   
   P2=0xfe;
   delay(100);
	}
	else
	{
	P2=0xfd;
   delay(100);
   }  
   for(a=1;a<=3;a++)
   {
   P2=_crol_(P2,2);
   delay(100);
   }
   i++;
}
}
void delay(uint z)
{
uint  x,y;
for(x=600;x!=0;x--)
for(y=z;y!=0;y--);
}
	