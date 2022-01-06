#include<reg52.h>
#include<intrins.h>
#define uint unsigned int
#define uchar unsigned char  
sbit LA=P2^2;
sbit LB=P2^3;
sbit LC=P2^4;
uint i,tt,b,t1;
uchar code xs[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
uchar t;
void main()
{	TMOD=0x01;
    TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
    EA=1;
	ET0=1;//定时器中断打开
    TR0=1;//启动定时器0
   LA=1;
   LB=1;
   LC=1; 
   t=0xfe;
   P2=t; 
   while(1)
   {   
   /*if(tt==40)
   {tt=0;
   i++;
   if(i==10)
   i=0;
   P0=xs[i];
   }*/	     	           
   	 if(t1==20)	 
   { 
   t=_crol_(P2,1);
   P2=t;
   t1==0;  
   }
   
}
   }   
void zd() interrupt 1
{  TH0=(65536-50000)/256;
	TL0=(65536-50000)%256;
	t1++;}