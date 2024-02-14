#include <xc.h>
#include"config.h"
#define LCD_DATA_D7 PORTDbits.RD7
#define LCD_DATA_D6 PORTDbits.RD6
#define LCD_DATA_D5 PORTDbits.RD5
#define LCD_DATA_D4 PORTDbits.RD4
#define LCD_RS PORTEbits.RE2
#define LCD_E PORTEbits.RE0

void IcdWriteCtrlWord(char x);
void IcdWriteDspData(char x);
void IcdWriteNibble(char nibble);
void IcdCtrl_SetPos(unsigned char row, unsigned char col);

void IcdCtrl_FunctionSet(void);
void IcdCtrl_OnOffDisplay(char display_state, char cursor_state);
void IcdCtrl_SetEntryMode(void);
void IcdCtrl_ClearDisplay(void);

void initLCD()
{
    __delay_ms(15);
    IcdWriteCtrlWord(0b00000011);
    __delay_ms(15);
    IcdWriteCtrlWord(0b00000010);
    
    IcdCtrl_FunctionSet();
    IcdCtrl_OnOffDisplay(1,0);
    IcdCtrl_SetEntryMode();
    IcdCtrl_ClearDisplay();
}

void IcdWriteCtrlWord(char x)
{
    char upper_nibble, lower_nibble;
    upper_nibble= (x & 0b11110000)>>4;
    lower_nibble= x & 0b00001111;
    LCD_RS=0;
    IcdWriteNibble(upper_nibble);
    IcdWriteNibble(lower_nibble);
}

void IcdWriteDspData(char x)
{
    char upper_nibble, lower_nibble;
    upper_nibble= (x & 0b11110000)>>4;
    lower_nibble= x & 0b00001111;
    LCD_RS=1;
    IcdWriteNibble(upper_nibble);
    IcdWriteNibble(lower_nibble);
}

void IcdWriteNibble(char nibble)
{
    LCD_DATA_D7=(nibble & 0b00001000)>>3;
    LCD_DATA_D6=(nibble & 0b00000100)>>2;
    LCD_DATA_D5=(nibble & 0b00000010)>>1;
    LCD_DATA_D4=(nibble & 0b00000001);
    
    LCD_E=1;
    __delay_ms(1);
    LCD_E=0;
    __delay_ms(1);
}



void IcdCtrl_SetPos(unsigned char row, unsigned char col)
{
    unsigned char ramAddr;
    if (row==1)
    
        ramAddr= col-1;
    
    else
    
        ramAddr= 0x40 + col - 1;
    
    
    IcdWriteCtrlWord(0x80+ ramAddr);
}

void IcdCtrl_FunctionSet(void) {
    IcdWriteCtrlWord(0b00101000);
}

void IcdCtrl_OnOffDisplay(char display_state, char cursor_state) {
    char pattern= 0b00001000;
    if (display_state==1) 
        pattern |=0b00000100;
    
    if (cursor_state==1)
        pattern |=0b00000011;
    
    IcdWriteCtrlWord(pattern);
}

void IcdCtrl_SetEntryMode(void) {
    IcdWriteCtrlWord(0b000001100);
}

void IcdCtrl_ClearDisplay(void){
    IcdWriteCtrlWord(0b00000001);
}

