/*
 * File:   sevseg.c
 * Author: GEESU
 *
 * Created on 7 August, 2023, 2:39 AM
 */


#include <xc.h>
#include "config.h"
const unsigned char segtable[11]= {
    0b11000000,
    0b11111001,
    0b10100100,
    0b10110000,
    0b10011001,
    0b10010010,
    0b10000010,
    0b11111000,
    0b10000000,
    0b10011000,
    0b11111111,
};

void seg_dispall(unsigned int result)
{
    int dig1, dig0;
    
    dig0= result%10;
    dig1= result/10;
    
    PORTDbits.RD1=0;
    PORTDbits.RD0=1;
    PORTC= segtable[dig0];
    __delay_ms(5);
    PORTC= segtable[10];
    
    PORTDbits.RD1=1;
    PORTDbits.RD0=0;
    PORTC= segtable[dig1];
    __delay_ms(5);
    PORTC= segtable[10];
    
}