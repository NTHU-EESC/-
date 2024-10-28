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
    unsigned char cnt;
    LOAD=0;
  	for(cnt=1;cnt<=matrixnum;cnt++)      //send address and data according to the nuber of your matrix
 	{
        sendbyte(address,dat);
    }
    LOAD=1;
}

void Writesingle7219(unsigned char chosen,unsigned char address,unsigned char dat)
{
    unsigned char cnt;
    LOAD=0;
 	 for(cnt=matrixnum;cnt>chosen;cnt--)   //write data into the selected matrix
 	 {
   		sendbyte(0x00,0x00); //write 0 to no-op
   	 }
   		sendbyte(address, dat); //sent data to chosen led-matrix

   	for (cnt=chosen-1;cnt>=1; cnt--)
   	{
   		sendbyte(0x00,0x00); //write 0 to no-op
        }

   LOAD=1;
}



//MAX7219inintialize and setup inside register
void Initial(void)
{   unsigned char i;

    Write7219(SHUT_DOWN,0x01);         //normal mode¡]0xX1¡^
    Write7219(DISPLAY_TEST,0x00);
    Write7219(DECODE_MODE,0x00);       //select non-decode mode
    Write7219(SCAN_LIMIT,0x07);        //use all 8 LED
    Write7219(INTENSITY,0x00);         //set up intensity

    for(i=1;i<=8;i++){
    	Write7219(i,0x00);   //turn off all LED
    }

}

void draw(unsigned char *picture){
  unsigned char i;
  for(i=1;i<=8;i++){
      Write7219(i,picture[i-1]);
  }
}

void singledraw(unsigned char chosen,unsigned char *picture){
  unsigned char i;
  for(i=1;i<=8;i++){
      Writesingle7219(chosen,i,picture[i-1]);
  }
}

void shiftdraw(unsigned char *picture){     //shift left
    unsigned char i;
    static char shift=0;

     for(i=1;i<=8;i++){
        Writesingle7219(1,i,picture[(shift+i-1)%16]);
        Writesingle7219(2,i,picture[(shift+i+8-1)%16]);
     }
   shift+=1;
   if(shift>16){
   shift=0;
   }

   delay_ms(1000);

}



void main(void)
{
  unsigned char seg[]={
  0b01111110,  // 0
  0b00110000,  // 1
  0b01101101,  // 2
  0b01111001,  // 3
  0b00110011,  // 4
  0b01011011,  // 5
  0b01011111,  // 6
  0b01110000,  // 7
  0b01111111,  // 8
  0b01111011,  // 9
  0b01110111,  // A
  0b00011111,  // b
  0b01001110,  // C
  0b00111101,  // d
  0b01001111,  // E
  0b01000111   // F
  };

  unsigned char i = 1;//
  Initial();               //MAX7219 initialize
    while(1)
    {

	Write7219(9,0xff);

	Write7219(8,2);
	Write7219(7,0);
	Write7219(6,2);
	Write7219(5,0);
	Write7219(4,1);
	Write7219(3,1);
	Write7219(2,1);
	Write7219(1,7);
	delay_ms(3000);

	Write7219(0x0b,2);
	Write7219(3,1);
	Write7219(2,0);
	Write7219(1,8);
	delay_ms(3000);

	Write7219(0x0b,3);
	Write7219(4,1);
	Write7219(3,0);
	Write7219(2,8);
	Write7219(1,0);
	delay_ms(1000);

	Write7219(0x0b,4);
	Write7219(5,1);
	Write7219(4,0);
	Write7219(3,8);
	Write7219(2,0);
	Write7219(1,6);
	delay_ms(1000);

	Write7219(0x0b,5);
	Write7219(6,1);
	Write7219(5,0);
	Write7219(4,8);
	Write7219(3,0);
	Write7219(2,6);
	Write7219(1,1);
	delay_ms(1000);

	Write7219(0x0b,6);
	Write7219(7,1);
	Write7219(6,0);
	Write7219(5,8);
	Write7219(4,0);
	Write7219(3,6);
	Write7219(2,1);
	Write7219(1,1);
	delay_ms(1000);

	Write7219(0x0b,7);
	Write7219(8,1);
	Write7219(7,0);
	Write7219(6,8);
	Write7219(5,0);
	Write7219(4,6);
	Write7219(3,1);
	Write7219(2,1);
	Write7219(1,1);
	delay_ms(1000);

	Write7219(0x0b,7);
	Write7219(8,0);
	Write7219(7,8);
	Write7219(6,0);
	Write7219(5,6);
	Write7219(4,1);
	Write7219(3,1);
	Write7219(2,1);
	Write7219(1,2);
	delay_ms(1000);
	
	Write7219(SHUT_DOWN,0);
	delay_ms(500);
	Write7219(SHUT_DOWN,1);
	delay_ms(500);
	Write7219(SHUT_DOWN,0);
	delay_ms(500);
	Write7219(SHUT_DOWN,1);
	delay_ms(500);
	Write7219(SHUT_DOWN,0);
	delay_ms(500);
	Write7219(SHUT_DOWN,1);
	delay_ms(500);

    }
}
