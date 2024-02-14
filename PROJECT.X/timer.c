/*
 * File:   timer.c
 * Author: GEESU
 *
 * Created on 7 August, 2023, 1:37 AM
 */


#include <xc.h>
#include "config.h"

void initsysTimer0(void){  //initializing timer
    INTCONbits.GIE=0;
    T0CON0=0b10010000;
    T0CON1=0b01001000;
    TMR0H=0x26;
    TMR0L=0xD6;
    PIR0bits.TMR0IF=0;
    PIE0bits.TMR0IE=1;
    INTCONbits.GIE=1;
} 