#include <REGX52.H>
#include <INTRINS.H>
sbit bz=P1^5;
void bz500us()		//@12.000MHz
{
	unsigned char i;

	_nop_();
	i = 247;
	while (--i);
}

void bztime(unsigned int ms)
{       unsigned int i;
					for(i=0;i<ms*2;i++)
				 {bz=!bz; bz500us();}

}

				 