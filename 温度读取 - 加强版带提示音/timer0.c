#include <REGX52.H>
void Timer0Init(void)		//1毫秒@12.000MHz
{
TMOD &= 0xF0;		//设置定时器模式
	TMOD |= 0x01;		//设置定时器模式	TL0 = 0x18;		//设置定时初值
		TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;//定时器0开始计时
  ET0=1;
	EA=1;
	PT0=0;	//定时器0开始计时
}
/*
void Timer0_Routine() interrupt 1
{ static unsigned int c0;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	c0++;
	if(c0>=1000)
	{ 
  c0=0;
	}
	
}
*/