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
	   UART_SendByte(sec);
	   sec++;
	   delay(1000);	   
   }
   }