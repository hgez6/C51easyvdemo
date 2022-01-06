#include<reg52.h>
sbit p2_1=P2^0;
unsigned int a;
void main()
{
while(1)
{
a=52000;
p2_1=0;
while(a--);
a=52000;
p2_1=1;
while(a--);
}
}