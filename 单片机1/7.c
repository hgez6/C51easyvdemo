#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char  
sbit k1=P3^1;
sbit k2=P3^0;
uint start=2;
void delay(uint b)
{
while(b--);
}

void keypros()
{
	if(k1==0)			 //¿ªÊ¼
	{
		delay(1000);
		if(k1==0)
		{
			start=1;		
		}
		while(!k1);
	}
	if(k2==0)			  //Í£Ö¹
	{
		delay(1000);
		if(k2==0)
		{
			start=0;		
		}
		while(!k2);
	}
}



void main()
{ uint i=0,a;
P2=0x00; 
 keypros();
 if(start==1)
 {
 while(1){
 
 
   delay(10000);
   P2=0xfe;
   delay(10000);
   for(a=1;a<=7;a++)
   {
	P2=_crol_(P2,1);
   delay(10000);
   
   } }
   }
  if(start==0){
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
}
