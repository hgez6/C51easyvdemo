#include<reg52.h>
#define uint unsigned int
#define uchar unsigned char
sbit LA=P2^2;
sbit LB=P2^3;
sbit LC=P2^4;
uchar hds[8];
uchar key;  
uint i=0;
uint c=0;
uchar code xs[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
void delay(uint b)
{ 
while(b--);
}
void keyd()
{	 
  char a=0;
  P1=0x0f;
  if(P1!=0x0f)
  { delay(1000);
    c++;
    if(P1!=0x0f)
	{switch(P1)
	{
	  case(0x07):key=0;break;
	  case(0x0b):key=1;break;
	  case(0x0d):key=2;break;
	  case(0x0e):key=3;break;
	  }
	  P1=0xf0;
	  switch(P1)
	{
	  case(0x70):key=key;break;
	  case(0xb0):key=key+4;break;
	  case(0xe0):key=key+8;break;
	  case(0xd0):key=key+12;break;
	}
	while((a<50) && (P1!=0xf0))
	{
	delay(1000);
	a++;
	}
	  }
	  }
	  }
	


void hd()
{	 
for(i=0;i<c;i++)
   {
     switch(c)
	 {
	 case (8):
	 LA=0;LB=0;LC=0;break;
	 case (7):
	 LA=1;LB=0;LC=0;break;
	 case (6):
	  LA=0;LB=1;LC=0;break;
	  case (5):
	  LA=1;LB=1;LC=0;break;
	  case (4):
	  LA=0;LB=0;LC=1;break;
	  case (3):
	  LA=1;LB=0;LC=1;break;
	  case (2):
	  LA=0;LB=1;LC=1;break;
	  case (1):
	  LA=1;LB=1;LC=1;break;
	  }
	  P0=hds[i];
	  delay(100); //间隔一段时间扫描	
	  P0=0x00;//消隐
	  }
	  }
	  



	 
	 

void main()
{
   while(1)
   {
   hds[1]=0x00;
   hds[2]=0x00;
   hds[3]=0x00;
   hds[4]=0x00;
   keyd();
   hds[1]=xs[key];
   hds[2]=xs[key];
   hds[3]=xs[key];
   hds[4]=xs[key];
   
   
   }
}
