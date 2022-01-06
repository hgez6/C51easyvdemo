 #include<regx52.h>
void delayms(unsigned int ams)		//@12.000MHz
{
	unsigned char i, j;
   while(ams)
   {
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		ams--;
	}
}

 
 void main()
{	   unsigned char a=0;
  P2=~0x01;
//P2_0=1;
while(1)
{     
   if(P3_1==0)
   {
      delayms(20);
	  while(P3_1==0);
	  delayms(20);
      a++;
	  if(a>=8)
	  a=0;
	  P2=~(0x01<<a);
   }
    if(P3_0==0)
   {
      delayms(20);
	  while(P3_0==0);
	  delayms(20);
     if(a==0)
	 a=7;
	 else
	 a--;
	P2=~(0x01<<a);
   }
  
 }
   
}
  