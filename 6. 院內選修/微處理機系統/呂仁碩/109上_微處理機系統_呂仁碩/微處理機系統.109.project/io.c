/* io.c */
/* 2021-01-22T14:06:32+00:00 */
/* 108061112 */

#ifndef IO_C
#define IO_C

/* type 'double' not supported assuming 'float' */
#define double float

#include "stdutils.h"
#include "delay.h"
#include "i2c.h"
#include "MLX90614.h"
#include "Lab4_MPU6050.h"

#include "input.c"
#include "output.c"

void print_char(const uint8_t character) /* similar to putchar() */
{
        buffer[cursor_position] = character;
        
        if ((uint8_t) '\b' == character)
        {
                cursor_position--;
        }
        else /* '\b' != character */
        {
                OLED_DisplayChar(character);
                cursor_position++;
        }
        
        buffer[cursor_position] = NULL;
        
        return;
}

uint8_t print_string(const uint8_t * string) /* similar to puts() */
{
        uint8_t index = 0u;
        
        for (;;)
        {
                if (NULL == string[index])
                {
                        return index;
                }
                
                print_char(string[index]);
                index++;
        }
}

uint8_t read_char(void) /* similar to getchar() */
{
        uint8_t hundreds = NULL;
        uint8_t tens = NULL;
        uint8_t ones = NULL;
        
        hundreds = posedge_input() * 100u;
        tens = posedge_input() * 10u;
        ones = posedge_input();
        
        return (hundreds + tens + ones);
}

void read_line(void) /* similar to gets() */
{
        for (;;)
        {
                uint8_t character = NULL;
                
                show_cursor();
                character = read_char();
                hide_cursor();
                
                if ((uint8_t) '\n' == character)
                {
                        return;
                }
                else
                {
                        print_char(character);
                }
        }
}

#endif /* IO_C */