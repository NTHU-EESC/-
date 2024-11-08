#include "stdutils.h"

#ifndef _OLED_I2C_H_
#define _OLED_I2C_H_

/******************************************************************************
                      SSD1306 ID and Command List
******************************************************************************/

#define OLED_SlaveAddress 0x78
#define SSD1306_ADDRESS	  0x3C

#define SSD1306_COMMAND	  0x00
#define SSD1306_DATA	  0xC0
#define SSD1306_DATA_CONTINUE	  0x40

#define SSD1306_SET_CONTRAST_CONTROL	0x81
#define SSD1306_DISPLAY_ALL_ON_RESUME	0xA4
#define SSD1306_DISPLAY_ALL_ON			0xA5
#define SSD1306_NORMAL_DISPLAY			0xA6
#define SSD1306_INVERT_DISPLAY			0xA7
#define SSD1306_DISPLAY_OFF				0xAE
#define SSD1306_DISPLAY_ON			    0xAF
#define SSD1306_NOP						0xE3

#define SSD1306_HORIZONTAL_SCROLL_RIGHT		    0x26
#define SSD1306_HORIZONTAL_SCROLL_LEFT			0x27
#define SSD1306_HORIZONTAL_SCROLL_VERTICAL_AND_RIGHT	0x29
#define SSD1306_HORIZONTAL_SCROLL_VERTICAL_AND_LEFT		0x2A
#define SSD1306_DEACTIVATE_SCROLL				0x2E
#define SSD1306_ACTIVATE_SCROLL					0x2F
#define SSD1306_SET_VERTICAL_SCROLL_AREA		0xA3

#define SSD1306_SET_LOWER_COLUMN		0x00
#define SSD1306_SET_HIGHER_COLUMN		0x10
#define SSD1306_MEMORY_ADDR_MODE		0x20
#define SSD1306_SET_COLUMN_ADDR			0x21
#define SSD1306_SET_PAGE_ADDR			0x22

#define SSD1306_SET_START_LINE			0x40
#define SSD1306_SET_SEGMENT_REMAP		0xA0
#define SSD1306_SET_MULTIPLEX_RATIO		0xA8
#define SSD1306_COM_SCAN_DIR_INC		0xC0
#define SSD1306_COM_SCAN_DIR_DEC		0xC8
#define SSD1306_SET_DISPLAY_OFFSET		0xD3
#define SSD1306_SET_COM_PINS			0xDA
#define SSD1306_CHARGE_PUMP				0x8D

#define SSD1306_SET_DISPLAY_CLOCK_DIV_RATIO	    0xD5
#define SSD1306_SET_PRECHARGE_PERIOD			0xD9
#define SSD1306_SET_VCOM_DESELECT				0xDB
/****************************************************************************/



/***************************************************************************************************
                             Commonly used LCD macros/Constants
***************************************************************************************************/
#define C_DefaultDigits       10

#define C_OledFirstLine_U8    0x00u
#define C_OledLastLine_U8     0x07u

#define C_FirstLineAddress_U8 0xB8
#define C_LastLineAddress_U8  0xBF

#define C_DisplayDefaultDigits_U8            0xffu // Will display the exact digits in the number
#define C_MaxDigitsToDisplay_U8              10u   // Max decimal/hexadecimal digits to be displayed
#define C_NumOfBinDigitsToDisplay_U8         16u   // Max bits of a binary number to be displayed
#define C_MaxDigitsToDisplayUsingPrintf_U8   C_DisplayDefaultDigits_U8 /* Max dec/hexadecimal digits to be displayed using printf */

#define C_MaxBarGraphs_U8     4
/**************************************************************************************************/



/***************************************************************************************************
                 PreCompile configurations to enable/disable the functions
****************************************************************************************************
PreCompile configuration to enable or disable the API's.
 1.Required interfaces can be enabled/disabled by configuring its respective macros to 1/0.
 2. By default all the API's are disabled.
 3. Displaying of floating number takes huge controller resources and need to be enabled only
    if required. This implies for other interfaces as well.
****************************************************************************************************/
  /*       
#define    Enable_OLED_ScrollMessage          0
#define    Enable_OLED_DisplayNumber          0
#define    Enable_OLED_DisplayFloatNumber     0
#define    Enable_OLED_Printf                 0
#define    Enable_OLED_DisplayLogo            1
#define    Enable_OLED_EnableInversion        0
#define    Enable_OLED_DisableInversion       0
#define    ENABLE_OLED_VerticalGraph          0
#define    ENABLE_OLED_HorizontalGraph        0
#define    Enable_OLED_SetBrightness          0
#define    Enable_OLED_GoToLine               0
*/
/**************************************************************************************************/


/***************************************************************************************************
                                Logo bit map declaration
 ***************************************************************************************************/
extern __code const unsigned char LogoBitMap[];
/**************************************************************************************************/



/***************************************************************************************************
                             Function Prototypes
 ***************************************************************************************************/
void OLED_Init(void);
void OLED_DisplayString(char *ptr);
void OLED_DisplayChar(char ch);
void OLED_ScrollMessage(uint8_t lineNum, char *strptr);
void OLED_DisplayNumber(uint8_t v_numericSystem_u8, uint32_t v_number_u32, uint8_t v_numOfDigitsToDisplay_u8);
void OLED_Printf(const char *argList, ...);
void OLED_Clear(void);
void OLED_GoToPage(uint8_t );
void OLED_GoToLine(uint8_t );
void OLED_GoToNextLine(void);
void OLED_SetCursor(uint8_t lineNumber,uint8_t CursorPosition);
void OLED_EnableInversion(void);
void OLED_DisableInversion(void);
void OLED_VerticalGraph(uint8_t var_barGraphNumber_u8, uint8_t var_percentageValue_u8);
void OLED_HorizontalGraph(uint8_t var_barGraphNumber_u8, uint8_t var_percentageValue_u8);
/**************************************************************************************************/   


uint8_t OledLineNum,OledCursorPos;


/***************************************************************************************************
                                  Local Function Declaration
 ***************************************************************************************************/
void oledSendCommand(uint8_t cmd);
void oledSendStart(uint8_t address);
void oledSendStop(void);
void oledWaitForAck(void);
void oledSendByte(uint8_t ch);
void oledSendData(uint8_t cmd);

void I2C_Start();
void I2C_Stop();
void I2C_SendACK(__bit ack);
__sbit I2C_RecvACK();
void I2C_SendByte(uint8_t dat);
uint8_t I2C_RecvByte();
void Single_WriteI2C(uint8_t SlaveAddress, uint8_t REG_Address,uint8_t REG_data);
uint8_t Single_ReadI2C(uint8_t SlaveAddress, uint8_t REG_Address);
void delay_ms(unsigned int input_ms);
/**************************************************************************************************/

#define FONT_SIZE 5

__code const OledFontTable[]=
{
        0x00, 0x00, 0x00, 0x00, 0x00,   // space
        0x00, 0x00, 0x2f, 0x00, 0x00,   // !
        0x00, 0x07, 0x00, 0x07, 0x00,   // "
        0x14, 0x7f, 0x14, 0x7f, 0x14,   // #
        0x24, 0x2a, 0x7f, 0x2a, 0x12,   // $
        0x23, 0x13, 0x08, 0x64, 0x62,   // %
        0x36, 0x49, 0x55, 0x22, 0x50,   // &
        0x00, 0x05, 0x03, 0x00, 0x00,   // '
        0x00, 0x1c, 0x22, 0x41, 0x00,   // (
        0x00, 0x41, 0x22, 0x1c, 0x00,   // )
        0x14, 0x08, 0x3E, 0x08, 0x14,   // *
        0x08, 0x08, 0x3E, 0x08, 0x08,   // +
        0x00, 0x00, 0xA0, 0x60, 0x00,   // ,
        0x08, 0x08, 0x08, 0x08, 0x08,   // -
        0x00, 0x60, 0x60, 0x00, 0x00,   // .
        0x20, 0x10, 0x08, 0x04, 0x02,   // /

        0x3E, 0x51, 0x49, 0x45, 0x3E,   // 0
        0x00, 0x42, 0x7F, 0x40, 0x00,   // 1
        0x42, 0x61, 0x51, 0x49, 0x46,   // 2
        0x21, 0x41, 0x45, 0x4B, 0x31,   // 3
        0x18, 0x14, 0x12, 0x7F, 0x10,   // 4
        0x27, 0x45, 0x45, 0x45, 0x39,   // 5
        0x3C, 0x4A, 0x49, 0x49, 0x30,   // 6
        0x01, 0x71, 0x09, 0x05, 0x03,   // 7
        0x36, 0x49, 0x49, 0x49, 0x36,   // 8
        0x06, 0x49, 0x49, 0x29, 0x1E,   // 9

        0x00, 0x36, 0x36, 0x00, 0x00,   // :
        0x00, 0x56, 0x36, 0x00, 0x00,   // ;
        0x08, 0x14, 0x22, 0x41, 0x00,   // <
        0x14, 0x14, 0x14, 0x14, 0x14,   // =
        0x00, 0x41, 0x22, 0x14, 0x08,   // >
        0x02, 0x01, 0x51, 0x09, 0x06,   // ?
        0x32, 0x49, 0x59, 0x51, 0x3E,   // @

        0x7C, 0x12, 0x11, 0x12, 0x7C,   // A
        0x7F, 0x49, 0x49, 0x49, 0x36,   // B
        0x3E, 0x41, 0x41, 0x41, 0x22,   // C
        0x7F, 0x41, 0x41, 0x22, 0x1C,   // D
        0x7F, 0x49, 0x49, 0x49, 0x41,   // E
        0x7F, 0x09, 0x09, 0x09, 0x01,   // F
        0x3E, 0x41, 0x49, 0x49, 0x7A,   // G
        0x7F, 0x08, 0x08, 0x08, 0x7F,   // H
        0x00, 0x41, 0x7F, 0x41, 0x00,   // I
        0x20, 0x40, 0x41, 0x3F, 0x01,   // J
        0x7F, 0x08, 0x14, 0x22, 0x41,   // K
        0x7F, 0x40, 0x40, 0x40, 0x40,   // L
        0x7F, 0x02, 0x0C, 0x02, 0x7F,   // M
        0x7F, 0x04, 0x08, 0x10, 0x7F,   // N
        0x3E, 0x41, 0x41, 0x41, 0x3E,   // O
        0x7F, 0x09, 0x09, 0x09, 0x06,   // P
        0x3E, 0x41, 0x51, 0x21, 0x5E,   // Q
        0x7F, 0x09, 0x19, 0x29, 0x46,   // R
        0x46, 0x49, 0x49, 0x49, 0x31,   // S
        0x01, 0x01, 0x7F, 0x01, 0x01,   // T
        0x3F, 0x40, 0x40, 0x40, 0x3F,   // U
        0x1F, 0x20, 0x40, 0x20, 0x1F,   // V
        0x3F, 0x40, 0x38, 0x40, 0x3F,   // W
        0x63, 0x14, 0x08, 0x14, 0x63,   // X
        0x07, 0x08, 0x70, 0x08, 0x07,   // Y
        0x61, 0x51, 0x49, 0x45, 0x43,   // Z

        0x00, 0x7F, 0x41, 0x41, 0x00,   // [
        0x55, 0xAA, 0x55, 0xAA, 0x55,   // Backslash (Checker pattern)
        0x00, 0x41, 0x41, 0x7F, 0x00,   // ]
        0x04, 0x02, 0x01, 0x02, 0x04,   // ^
        0x40, 0x40, 0x40, 0x40, 0x40,   // _
        0x00, 0x03, 0x05, 0x00, 0x00,   // `

        0x20, 0x54, 0x54, 0x54, 0x78,   // a
        0x7F, 0x48, 0x44, 0x44, 0x38,   // b
        0x38, 0x44, 0x44, 0x44, 0x20,   // c
        0x38, 0x44, 0x44, 0x48, 0x7F,   // d
        0x38, 0x54, 0x54, 0x54, 0x18,   // e
        0x08, 0x7E, 0x09, 0x01, 0x02,   // f
        0x18, 0xA4, 0xA4, 0xA4, 0x7C,   // g
        0x7F, 0x08, 0x04, 0x04, 0x78,   // h
        0x00, 0x44, 0x7D, 0x40, 0x00,   // i
        0x40, 0x80, 0x84, 0x7D, 0x00,   // j
        0x7F, 0x10, 0x28, 0x44, 0x00,   // k
        0x00, 0x41, 0x7F, 0x40, 0x00,   // l
        0x7C, 0x04, 0x18, 0x04, 0x78,   // m
        0x7C, 0x08, 0x04, 0x04, 0x78,   // n
        0x38, 0x44, 0x44, 0x44, 0x38,   // o
        0xFC, 0x24, 0x24, 0x24, 0x18,   // p
        0x18, 0x24, 0x24, 0x18, 0xFC,   // q
        0x7C, 0x08, 0x04, 0x04, 0x08,   // r
        0x48, 0x54, 0x54, 0x54, 0x20,   // s
        0x04, 0x3F, 0x44, 0x40, 0x20,   // t
        0x3C, 0x40, 0x40, 0x20, 0x7C,   // u
        0x1C, 0x20, 0x40, 0x20, 0x1C,   // v
        0x3C, 0x40, 0x30, 0x40, 0x3C,   // w
        0x44, 0x28, 0x10, 0x28, 0x44,   // x
        0x1C, 0xA0, 0xA0, 0xA0, 0x7C,   // y
        0x44, 0x64, 0x54, 0x4C, 0x44,   // z

        0x00, 0x10, 0x7C, 0x82, 0x00,   // {
        0x00, 0x00, 0xFF, 0x00, 0x00,   // |
        0x00, 0x82, 0x7C, 0x10, 0x00,   // }
        0x00, 0x06, 0x09, 0x09, 0x06    // ~ (Degrees)
};



/**************************************************************************************************
                                void OLED_Init()
 ***************************************************************************************************
 * I/P Arguments:  none
 * Return value : none

 * description  :This function is used to initialize the OLED in the normal mode.
                After initializing the OLED, It clears the OLED and sets the cursor to first line first position. .

 **************************************************************************************************/
void OLED_Init(void)
{ 
    oledSendCommand(0xa8);  //Set MUX Ratio
    oledSendCommand(0x3f);  
    oledSendCommand(0xd3);  //Set Display Offset
    oledSendCommand(0x00);  
    oledSendCommand(0x40);  //Set Display Start Line
	oledSendCommand(0xa1);  //Set Segment re-map A0h/A1h
	oledSendCommand(0xc8);  //Set COM OUTput
	oledSendCommand(0xda); 
	oledSendCommand(0x12);
	oledSendCommand(0x81);
	oledSendCommand(0x7f);
	oledSendCommand(0xa4);
	oledSendCommand(0xa6);
	oledSendCommand(0xd5);
	oledSendCommand(0x80);
	oledSendCommand(0x8d);
	oledSendCommand(0x14);
	oledSendCommand(0xaf);

    OLED_Clear();  /* Clear the complete LCD during init */
}





/***************************************************************************************************
                       void OLED_DisplayChar( char ch)
 ****************************************************************************************************
 * I/P Arguments: ASCII value of the char to be displayed.
 * Return value    : none

 * description  : This function sends a character to be displayed on LCD.
                  Any valid ascii value can be passed to display respective character

 ****************************************************************************************************/
void OLED_DisplayChar(char ch)
{
    uint8_t i=0;
    int index;

    if(ch != '\n') {  /* TODO */ 
        index = (ch - 0x20);
        index = index * 5; // As the lookup table starts from Space(0x20)

        for(i = 0; i < 5; i ++)
            oledSendData(OledFontTable[index + i]); /* Get the data to be displayed for LookUptable*/

        oledSendData(0x00); /* Display the data and keep track of cursor */
    }
}






/***************************************************************************************************
                       void OLED_DisplayString(char *ptr_stringPointer_u8)
 ****************************************************************************************************
 * I/P Arguments: String(Address of the string) to be displayed.
 * Return value    : none

 * description  :
               This function is used to display the ASCII string on the lcd.
                 1.The ptr_stringPointer_u8 points to the first char of the string
                    and traverses till the end(NULL CHAR)and displays a char each time.

 ****************************************************************************************************/

void OLED_DisplayString(char *ptr)
{  
    while(*ptr) {
        OLED_DisplayChar(*ptr);
        ptr ++;
    }
}





/***************************************************************************************************
                         void OLED_Clear()
 ****************************************************************************************************
 * I/P Arguments: none.
 * Return value    : none

 * description  :This function clears the LCD and moves the cursor to beginning of first line
 ****************************************************************************************************/
void OLED_Clear()
{	
    uint8_t oled_clean_col , oled_clean_page;
	for(oled_clean_page = 0 ; oled_clean_page < 8 ; oled_clean_page ++) {
        OLED_SetCursor(oled_clean_page,0);
		for(oled_clean_col= 0 ; oled_clean_col < 128 ; oled_clean_col ++) {
            oledSendData(0);
		}
	}
}
/***************************************************************************************************
                void OLED_SetCursor(char v_lineNumber_u8,char v_charNumber_u8)
 ****************************************************************************************************
 * I/P Arguments: char row,char col
                 row -> line number(line1=1, line2=2),
                        For 2line LCD the I/P argument should be either 1 or 2.
                 col -> char number.
                        For 16-char LCD the I/P argument should be between 0-15.
 * Return value    : none

 * description  :This function moves the Cursor to specified position

                   Note:If the Input(Line/Char number) are out of range
                        then no action will be taken
 ****************************************************************************************************/
void OLED_SetCursor(uint8_t lineNumber,uint8_t cursorPosition)
{
    cursorPosition = cursorPosition + 2;
    oledSendCommand(0x0f&cursorPosition);
	oledSendCommand(0x10|(cursorPosition>>4));
	oledSendCommand(0xb0|lineNumber);
}

/********************************************************************************
                Local FUnctions for sending the command/data
 ********************************************************************************/
void oledSendCommand(uint8_t cmd)
{
    Single_WriteI2C(OLED_SlaveAddress, SSD1306_COMMAND, cmd);
}

void oledSendData(uint8_t cmd)
{
    Single_WriteI2C(OLED_SlaveAddress, SSD1306_DATA_CONTINUE, cmd);
}

/*****************************************************************************************************/


#endif
