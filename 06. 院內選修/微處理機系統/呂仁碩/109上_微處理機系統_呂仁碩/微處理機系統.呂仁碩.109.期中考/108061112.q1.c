#include "8051.h"

#define led P1
#define but1 P2_0
#define but2 P2_1



void delay_ms(unsigned int input_ms);//delay func

void main()
{ 
 P2_0=1;                 //initialize
 P2_1=1;
 P3_2=1;
 P3_3=1;
 P1=0x7f;
 for(;1;) {
	delay_ms(50);
	for (;P3_2 & P3_3 & P2_0 & P2_1;);
	if (!P3_3) {
		for(;!P3_3;);
		P1 = P1 << 1 | P1 >> 7;
	}
	if (!P3_2) {
		for(;!P3_2;);
		P1 = P1 >> 1 | P1 << 7;
	}
	for (;!P2_1;) {
		P1 = P1 << 1 | P1 >> 7;
		delay_ms(500);
	}
	for (;!P2_0;) {
		P1 = P1 >> 1 | P1 << 7;
		delay_ms(500);
	}
	for(;!(P3_2 & P3_3 & P2_0 & P2_1););
}
}



void delay_ms(unsigned int input_ms)
{
	unsigned int cnt1 = 0;
	unsigned int cnt2 = 0;
	
	for(cnt1 = 0; cnt1 < input_ms; cnt1 ++)
	{	
		for(cnt2 = 0; cnt2 < 140;cnt2 ++);
	}
}

