#include <c8051f020.h>
#include <zlg7289.h>
#include <keyboard.h>

bit setf = 0;
unsigned char key;
unsigned char value[4] = {0,0,0,0};
unsigned int freq;
unsigned char pos = 0;
void keyboard_init()
{
	EIE2 |= 0x20;
	EIP2 |= 0x20;	
}


void key_det() interrupt 19
{
	key = ZLG7289_Key();
	P3IF = 0;
	if(key == 11)
		setf = 1;
	if(key >= 0 && key <= 9)
	{
		value[pos] = key;
		pos++;
		if(pos > 3)
			pos = 0;
	}
	freq = value[0] * 1000 + value[1] * 100 + value[2] * 10 + value[3];
}
