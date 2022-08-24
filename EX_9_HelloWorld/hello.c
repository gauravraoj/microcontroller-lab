#include<lpc21xx.h>
#include<stdio.h>

void uart_interrupt(void)__irq;

unsigned char temp , temp1 = 0x00 ;
unsigned char rx_flag = 0 , tx_flag = 0 ;

int main (void)
{
	PINSEL0 = 0x00000005 ;
	U0LCR = 0x000000083 ;
	U0DLM = 0x00 ;
	U0DLL = 0x13 ;
	U0LCR = 0x000000003 ;
	U0IER = 0x03 ;
	VICVectAddr0 = (unsigned long)uart_interrupt ;
	VICVectCntl0 = 0x20|6 ;
	VICIntEnable = 0x0000040 ;
	rx_flag = 0x00 ;
	tx_flag = 0x00 ;
	
	while(1)
	{
		while( rx_flag == 0x00 );
		rx_flag = 0x00 ;
		U0THR = temp1 ;
		while(tx_flag == 0x00 );
		tx_flag = 0x00 ;
	}
}

void uart_interrupt(void)__irq
{
	temp = U0IIR ;
	temp = temp & 0x06 ;
	if(temp == 0x02)
	{
		tx_flag = 0xff ;
		VICVectAddr = 0 ;
	}
	else if (temp == 0x04)
	{
		temp1 = U0RBR ;
		rx_flag = 0xff ;
		VICVectAddr = 0 ;
	}
}		