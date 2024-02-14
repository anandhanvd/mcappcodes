/*
 * File:   Ext_int.c
 * Author: GEESU
 *
 * Created on 13 July, 2023, 12:06 AM
 */

#include <xc.h>
#include "config.h"

void initSysExtInt(void) 
{
    INTCONbits.GIE = 0; 
    PIR0bits.INTF = 0; 
    INTPPS = 0x0A; 
    INTCONbits.INTEDG = 1; 
    PIE0bits.INTE=1;
    INTCONbits.GIE = 1; 
}   
 
