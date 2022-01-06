#include <REGX52.H>
sbit DS1302_SCLK=P3^6;
sbit DS1302_IO=P3^4;
sbit DS1302_CE=P3^5;
#define DS1302_SECOND 0X80     //写入数据的代号，读取要加1
#define DS1302_MINUTE   0X82
#define DS1302_HOUR   0X84
#define DS1302_DATE   0X86
#define DS1302_MONTH  0X88
#define DS1302_DAY    0X8A
#define DS1302_YEAR   0X8C
#define DS1302_WP     0X8E

unsigned char DS1302_Time[]={20,8,25,10,01,55,2};
void DS1302_WriteByte(unsigned char Command,Data)
{ unsigned int i;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
	DS1302_IO=Command&(0x01<<i);
	DS1302_SCLK=1;
	DS1302_SCLK=0;
	}
	for(i=0;i<8;i++)
	{
	DS1302_IO=Data&(0x01<<i);
	DS1302_SCLK=1;
	DS1302_SCLK=0;
	}
	DS1302_CE=0;	
}

void DS1302_Init()
{
	DS1302_CE=0;
	DS1302_SCLK=0;
	 DS1302_WriteByte(DS1302_WP,0x00);

}


unsigned char DS1302_ReadByte(unsigned char Command)
{ unsigned int i;
	unsigned char Data=0x00;
	DS1302_CE=1;
	for(i=0;i<8;i++)
	{
	DS1302_IO=Command&(0x01<<i);
	DS1302_SCLK=0;
	DS1302_SCLK=1;
	}
		
	for(i=0;i<8;i++)
	{
		DS1302_SCLK=1;
   DS1302_SCLK=0;
	if(DS1302_IO){Data|=(0x01<<i);}
  }
	DS1302_CE=0;
	DS1302_IO=0;
	return Data;
}

void DS1302_settime()
{
		DS1302_WriteByte(DS1302_WP,0x00);
	DS1302_WriteByte(DS1302_YEAR,DS1302_Time[0]/10*16+DS1302_Time[0]%10);
	DS1302_WriteByte(DS1302_MONTH,DS1302_Time[1]/10*16+DS1302_Time[1]%10);
	DS1302_WriteByte(DS1302_DATE,DS1302_Time[2]/10*16+DS1302_Time[2]%10);
	DS1302_WriteByte(DS1302_HOUR,DS1302_Time[3]/10*16+DS1302_Time[3]%10);
	DS1302_WriteByte(DS1302_MINUTE,DS1302_Time[4]/10*16+DS1302_Time[4]%10);
	DS1302_WriteByte(DS1302_SECOND,DS1302_Time[5]/10*16+DS1302_Time[5]%10);
	DS1302_WriteByte(DS1302_DAY,DS1302_Time[6]/10*16+DS1302_Time[6]%10);
	DS1302_WriteByte(DS1302_WP,0x80);

}
	void DS1302_readtime()
{
	unsigned char a;
  a=DS1302_ReadByte(DS1302_YEAR+1);
	DS1302_Time[0]=a/16*10+a%16;
	a=DS1302_ReadByte(DS1302_MONTH+1);
	DS1302_Time[1]=a/16*10+a%16;
	a=DS1302_ReadByte(DS1302_DATE+1);
	DS1302_Time[2]=a/16*10+a%16;
	a=DS1302_ReadByte(DS1302_HOUR+1);
	DS1302_Time[3]=a/16*10+a%16;
	a=DS1302_ReadByte(DS1302_MINUTE+1);
	DS1302_Time[4]=a/16*10+a%16;
	a=DS1302_ReadByte(DS1302_SECOND+1);
	DS1302_Time[5]=a/16*10+a%16;
	a=DS1302_ReadByte(DS1302_DAY+1);
	DS1302_Time[6]=a/16*10+a%16;
}

	 