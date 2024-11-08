/* input.c */
/* 2021-01-19T07:03:32+00:00 */
/* 108061112 */

#ifndef INPUT_C
#define INPUT_C

#define KEYPAD_DIMENSION 4u
#define KEYPAD_GPIO P2
#define KEYPAD_NO_KEY_PRESSED C_UINT8_MAX

uint8_t raw_input(void)
{
        __code static uint8_t log_2[] =
                {KEYPAD_DIMENSION, 0u, 1u, NULL, 2u, NULL, NULL, NULL, 3u};
        /*      {               0,  1,  2,    3,  4,    5,    6,    7,  8} */
        
        __code static uint8_t key[KEYPAD_DIMENSION][KEYPAD_DIMENSION] =
                {{7u, 8u, 9u, -1},
                 {4u, 5u, 6u, -1},
                 {1u, 2u, 3u, -1},
                 {-1, 0u, -1, -1}};
        
        uint8_t row = NULL;
        uint8_t col = NULL;
        
        KEYPAD_GPIO = 0x0fu;
        row = log_2[util_ExtractNibble0to4(~KEYPAD_GPIO)];
        KEYPAD_GPIO = 0xf0u;
        col = log_2[util_ExtractNibble4to8(~KEYPAD_GPIO)];
        
        if ((KEYPAD_DIMENSION > row) && (KEYPAD_DIMENSION > col))
        {
                return key[row][col]; /* one of the key is pressed */
        }
        else
        {
                return KEYPAD_NO_KEY_PRESSED;
        }
}

uint8_t debounce_input(void)
{
        uint8_t old_input = NULL;
        uint8_t new_input = NULL;
        uint8_t timer = 0u;
        
        for (;;) {
                
                if (C_UINT8_MAX == timer)
                {
                        return new_input;
                }
                
                old_input = new_input;
                new_input = raw_input();
                
                if (old_input == new_input)
                {
                        timer++;
                }
                else
                {
                        timer = 0u;
                }
        }
}

uint8_t posedge_input(void)
{
        while (KEYPAD_NO_KEY_PRESSED != debounce_input())
        {
                /* wait for key to be released */
        }
        
        while (KEYPAD_NO_KEY_PRESSED == debounce_input())
        {
                /* wait for key to be pressed */
        }
        
        return debounce_input();
}

#endif /* INPUT_C */
