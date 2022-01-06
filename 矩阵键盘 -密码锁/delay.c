void delay(unsigned int x)		//@12.000MHz 1ms
{
	unsigned char i, j;
    while(x--)
	{
	i = 2;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
	}
}