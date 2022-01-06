#include<reg52.h>
#define uint unsigned int
#include<UART.h>
unsigned char  sec=0x00;
void delay(unsigned int a)
{
    unsigned int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<120;j++);
}

void main()
{	
   UART_Init();
  
   while(1)
   {
	     
   }
   }
   void UART_Routine() interrupt 4	//中断服务函数
   {
   if(RI==1)   //如果是接收中断
   { 
	  P2=~SBUF;
	  UART_SendByte(SBUF);
	  RI=0;
   }
   }