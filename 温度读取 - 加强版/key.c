#include <REGX52.H>
#include "delay.h"
unsigned char keycache;
unsigned char key()
{ 
	unsigned char a;
	a=keycache;
	keycache=0;
	return a;
} 
unsigned char key_getstate()
{
	unsigned char key=0;
	if(P3_1==0){key=1;}
	if(P3_0==0){key=2;}
	if(P3_2==0){key=3;}
	if(P3_3==0){key=4;}
	return key;
}	
void key_loop()
{
	static unsigned char nowstate,laststate;
	laststate=nowstate;
	nowstate=key_getstate();
	if(laststate==1 && nowstate==0)
	{
	keycache=1;
	}
			if(laststate==2 && nowstate==0)
	{
	keycache=2;
	}
		if(laststate==3 && nowstate==0)
	{
	keycache=3;
	}
		if(laststate==4 && nowstate==0)
	{
	keycache=4;
	}
}