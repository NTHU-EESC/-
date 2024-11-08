/* output.c */
/* 2021-01-19T09:36:27+00:00 */
/* 108061112 */

#ifndef OUTPUT_C
#define OUTPUT_C

#include "Lab3_OLED.h"

#define OLED_TOTAL_PAGE 8u
#define OLED_ROW_PER_PAGE 8u
#define OLED_COLUMN_PER_PAGE 128u
#define OLED_COLUMN_PER_CHAR 6u
#define OLED_CHAR_PER_PAGE 21u

uint8_t buffer[OLED_CHAR_PER_PAGE] = {NULL};
uint8_t prompt[OLED_CHAR_PER_PAGE] = "> ";

uint8_t page_offset = 0u;
uint8_t cursor_position = 0u;
   
void force_cursor_position(void)
{
        OLED_SetCursor(page_offset, OLED_COLUMN_PER_CHAR * cursor_position);
        return;
}

void show_cursor(void)
{
        force_cursor_position();
        OLED_DisplayChar('_');
        force_cursor_position();
        return;
}

void hide_cursor(void)
{
        force_cursor_position();
        OLED_DisplayChar(' ');
        force_cursor_position();
        return;
}

void newline(void) /* create a new blank line */
{
        hide_cursor();
        
        page_offset++;
        page_offset %= OLED_TOTAL_PAGE;
        
        cursor_position = OLED_CHAR_PER_PAGE;
        force_cursor_position();
        while (cursor_position --> (uint8_t) 0u)
        {
                buffer[cursor_position] = NULL;
                OLED_DisplayChar(' ');
        }
        cursor_position = 0u;
        force_cursor_position();
        
        oledSendCommand(SSD1306_SET_DISPLAY_OFFSET);
        oledSendCommand(OLED_ROW_PER_PAGE + OLED_ROW_PER_PAGE * page_offset);
        return;
}

#endif /* OUTPUT_C */