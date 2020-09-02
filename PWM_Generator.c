#include "c8051f020.h"
#include <keyboard.h>

sbit PWM = P1^0;

void PWM_Init()
{	

	ET2 = 1;
	CKCON |= 0x00; 	//12·ÖÆµ
	T2CON = 0x00;
	TR2 = 1;


}

void PWM_set(unsigned int fre)
{	
	unsigned int t = 500000 / fre;	
	TH2 = (65536 - t) / 256;		//0.1ms --> 10KHz
	TL2 = (65536 - t) % 256;
	RCAP2H=(65536 - t) / 256;
	RCAP2L=(65536 - t) % 256;	
}

void PWM_generator() interrupt 5
{
	TF2 = 0;
	PWM = ~PWM;
}

