#include<lpc214x.h>
void clock_wise(void);
void anti_clock_wise(void);
unsigned int j=0;
int main()
{
	PINSEL2=0xFFFFFFF0;
	IO1DIR=0x00030000;
	IO1CLR=0x00010000;
	while(1)
	{
		clock_wise();
		for(j=0;j<50000;j++);
		anti_clock_wise();
		for(j=0;j<50000;j++);
	}
}
void clock_wise(void)
{
	IO0CLR=0x00300000;
	for(j=0;j<500000;j++);
	IO1SET=0x00030000;
}
void anti_clock_wise(void)
{
	IO0CLR=0x00300000;
	for(j=0;j<500000;j++);
	IO1SET=0x00010000;
}