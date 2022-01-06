#include<reg52.h>
void UART_Init()
{
     SCON=0x50; //允许接收
	 PCON |= 0x80;
	 TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
    TL1 = 0xF3;		//设定定时初值
	TH1 = 0xF3;	//设置定时初值	
	ET1=0;
	TR1 = 1;
	EA=1;
	ES=1;		//启动定时器1
}
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
    while(TI==0);
	TI=0;
}