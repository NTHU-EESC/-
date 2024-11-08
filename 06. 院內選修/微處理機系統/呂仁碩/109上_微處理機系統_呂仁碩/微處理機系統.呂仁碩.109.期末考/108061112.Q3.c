#include <8051.h>
#include "Lab3_OLED.h"
#include "delay.h"
#include "i2c.h"
#include "MLX90614.h"

int data_buf1, data_buf2;

int main() {		 
    SDA = 1;
    SCL = 1;
    OLED_Init();		  // Check oled_i2c.c file for SCL,SDA pin connection
    OLED_SetCursor(0,0);  // S
    OLED_DisplayString("Distance:X.XXX[V]");
    OLED_SetCursor(1,0);  // S
    OLED_DisplayString("Temp:    [C]");

    while(1) {
      data_buf1 = readAmbientTemp();
      data_buf2 = readObjectTemp();

      //show data of Object Temperature(C) 
      OLED_SetCursor(1, 30);
      OLED_DisplayChar(data_buf2 % 1000 / 100 + '0');
      OLED_DisplayChar(data_buf2 % 100 / 10 + '0');
      OLED_DisplayChar('.');
      OLED_DisplayChar(data_buf2 % 10 / 1 + '0');
      delay_ms(1000);
    }
}
