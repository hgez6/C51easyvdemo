#include <REGX52.H>
#include "delay.h"
#include "timer0.h"
sbit bz=P1^5;
#define P 0
#define L1 1
#define L1_ 2
#define L2 3
#define L2_ 4
#define L3 5
#define L4 6
#define L4_ 7
#define L5 8
#define L5_ 9
#define L6 10
#define L6_ 11
#define L7 12
#define M1 13
#define M1_ 14
#define M2 15
#define M2_ 16
#define M3  17
#define M4 18
#define M4_ 19
#define M5 20
#define M5_ 21
#define M6 22
#define M6_ 23
#define M7 24
#define H1 25
#define H1_ 26
#define H2 27
#define H2_ 28
#define H3 29
#define H4 30
#define H4_ 31
#define H5 32
#define H5_ 33
#define H6 34
#define H6_ 35
#define H7  36

unsigned int freq[]={0,63628,63731,63835,53928,64021,64103,64185,64260,64331,64400,64463,64528
,64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030
,65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283 };
unsigned char freqs,pages; 
unsigned char code page[]={P,4,P,4,P,4,M6,2,M7,2,
H1,6,M7,2,H1,4,H3,4,
M7,12,M3,2,M3,2,
90};
void main()
{    Timer0Init();
      while(1)
     {
			 if(page[pages]!=90)
			 {
			  freqs=page[pages]; 
			 pages++;
			 delay(125*pages);
			 pages++;
			 TR0=0;
			 delay(5);
			  TR0=1;			 
			 }
			 else 
			 {
			 			 TR0=0; delay(500); pages=0;
//      while(1);
			 }

     
      }
}

void Timer0_Routine() interrupt 1
{ if(freq[freqs])
	{
	TL0 = freq[freqs]%256;		//设置定时初值
	TH0 = freq[freqs]/256;		//设置定时初值
	bz=!bz;
	}
}


