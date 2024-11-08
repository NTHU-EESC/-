#ifndef   __MLX90614_H
#define   __MLX90614_H

#define   MLX90614_ADDRESS    0x5a
#define   MLX90614_ADDR_WRITE   0x00	
#define   MLX90614_ADDR_READ    0x01
#define   MLX90614_RAM    0x00
#define   AMBIENT_TEMP    0x06
#define   OBJECT_TEMP     0x07

double readObjectTemp(void);
double readAmbientTemp(void);
float   readTemp(uint8_t reg);

/***************************************/
uint8_t  _addr = MLX90614_ADDRESS << 1;    // 0x5a --> 0xb4

double readObjectTemp(void) {
  return readTemp(OBJECT_TEMP);
}

double readAmbientTemp(void) {
  return readTemp(AMBIENT_TEMP);
}

float readTemp(uint8_t reg) {
  float  temp;
  uint16_t  tempData;
  uint8_t   pec;

  I2C_Start();
  I2C_SendByte(_addr);            // 0xb4
  I2C_SendByte(reg);
  SDA = 1;                        // pull up 2 wires to restart
  SCL = 1;                        
  I2C_Start();                    // restart
  I2C_SendByte(_addr|0x01);       // 0xb4 --> 0xb5
  tempData = I2C_RecvByte();      // LSByte
  I2C_SendACK(0);
  tempData |= I2C_RecvByte() << 8;  // { MSByte , LSByte } 
  I2C_SendACK(0);
  pec = I2C_RecvByte();           // 8-bit pec 
  I2C_SendACK(1);
  I2C_Stop();
  temp = tempData;               // raw 16-bit tempData 
  temp *= 0.02;                  // calculate temperature in Celsius 
  temp -= 273.15;
  temp = temp * 10 ;             // in order to show 1 decimal bit
  
  return temp;
}

/***************************************/

#endif 