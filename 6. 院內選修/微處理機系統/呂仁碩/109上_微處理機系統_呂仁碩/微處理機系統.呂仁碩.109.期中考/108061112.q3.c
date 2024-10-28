#include "8051.h"

int cnt = 0;

void timer_delay()			    /* Timer0 delay 1ms function */
{
	TH0 = (65536-950) / 256;	/* Load 8-bit in TH0 (here Timer0 used) */
	TL0 = (65536-950) % 256;   /* Load 8-bit in TL0 */
	TR0 = 1;                    /* Start timer0 */
	TF0 = 0;                    /* Clear timer0 flag */
	while(TF0 == 0);		    /* Wait until timer0 flag set */
	TR0 = 0;			        /* Stop timer0 */
}


void main()
{
	P3 =  0xff;
	TMOD = 0x01;			   /* Timer0 mode1 (16-bit timer mode) */
	while(1)
	{
		for(;!P3_3;){
		P3_7 = !P3_7;		     
			timer_delay();		   /* Call timer0 delay */
			}
	}
}
