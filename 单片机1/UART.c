#include<reg52.h>
void UART_Init()
{
     SCON=0x40;
	 PCON |= 0x80;
	 TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
    TL1 = 0xF3;		//�趨��ʱ��ֵ
	TH1 = 0xF3;	//���ö�ʱ��ֵ	
	ET1=0;
	TR1 = 1;		//������ʱ��1
}
void UART_SendByte(unsigned char Byte)
{
	SBUF=Byte;
    while(TI==0);
	TI=0;
}