// delay.h 
//**************************************
// 8051 delay function (ms)
//**************************************

void delay_ms(unsigned int input_ms)
{
	unsigned int cnt1 = 0;
	unsigned char cnt2 = 0;
	
	for(cnt1 = 0; cnt1 < input_ms; cnt1 ++) {	
		while(cnt2 < 90) {
            cnt2 ++;
        }
	}
}