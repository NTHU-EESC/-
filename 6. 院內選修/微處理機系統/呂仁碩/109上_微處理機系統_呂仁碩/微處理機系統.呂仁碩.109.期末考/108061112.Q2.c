#include "8051.h"
#include "delay.h"
#define DIN P2_2
#define LOAD P2_1
#define CLK  P2_0

//define reigister
#define DECODE_MODE  0x09
#define INTENSITY    0x0A
#define SCAN_LIMIT   0x0B
#define SHUT_DOWN    0x0C
#define DISPLAY_TEST 0x0F
#define matrixnum       2      //number of dot matrix

//function declaration
void Write7219(unsigned char address,unsigned char dat);
void Writesingle7219(unsigned char chosen,unsigned char address,unsigned char dat);
void sendbyte(unsigned char address,unsigned char dat);
void Initial(void) ;
void draw(unsigned char *picture);
void singledraw(unsigned char chosen,unsigned char *picture);
void shiftdraw(unsigned char *picture);


//store address and data
void sendbyte(unsigned char address,unsigned char dat){
 unsigned char i;
    for (i=0;i<8;i++)        //get last 8 bits(address)
    {

       CLK=0;
       DIN=(address&0x80);   //get msb and shift left
       address<<=1;
       CLK=1;
    }

    for (i=0;i<8;i++)      //get first 8 bits(data)
    {
       CLK=0;
       DIN=(dat&0x80);    //get msb and shit left
       dat<<=1;
       CLK=1;
    }
 }

void Write7219(unsigned char address,unsigned char dat)
{
    LOAD=0;
        sendbyte(address,dat);
    LOAD=1;
}

//MAX7219inintialize and setup inside register
void Initial(void)
{   unsigned char i;

    Write7219(SHUT_DOWN,0x01);         //normal mode¡]0xX1¡^
    Write7219(DISPLAY_TEST,0x00);
    Write7219(DECODE_MODE,0xFF);       //select non-decode mode
    Write7219(SCAN_LIMIT,0x07);        //use all 8 LED
    Write7219(INTENSITY,0x00);         //set up intensity

    for(i=1;i<=8;i++){
    	Write7219(i,0x00);   //turn off all LED
    }

}

void main(void)
{
int count = 0;
int time = 0;
Initial();
Write7219(SCAN_LIMIT,0);
Write7219(1,0);
for (time=500;--time;) {
	P3 = ~P3;
	delay_ms(1);
}
	for(;1;){
		Write7219(SCAN_LIMIT,0);
		if (count/10) Write7219(SCAN_LIMIT,1);
		if (count/100) Write7219(SCAN_LIMIT,2);
		if (count/1000) Write7219(SCAN_LIMIT,3);
		Write7219(4,count/1000%10);
		Write7219(3,count/100%10);
		Write7219(2,count/10%10);
		Write7219(1,count%10);
		if (count!=0&&count%2==0) {
			if (count%8!=0) {
				for (time=500;--time;) {
					P3 = ~P3;
					delay_ms(1);
				}
			} else {
				for (time=1500;--time;) {
					P3 = ~P3;
					delay_ms(1);
				}
			}
		}
		for(;!P2_4;);
		count++;
		for(;P2_4;);
	}
}
