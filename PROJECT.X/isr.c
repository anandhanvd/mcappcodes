/*
 * File:   isr.c
 * Author: GEESU
 *
 * Created on 13 July, 2023, 12:12 AM
 */


#include <xc.h>
#include "config.h"

void __interrupt() isr(void) 
{
    if (PIR0bits.INTF == 1) 
    {
        PIR0bits.INTF = 0; 
        PORTBbits.RB0=0;
         
    }
    


    
else if (PIR0bits.TMR0IF==1)
    {
        PIR0bits.TMR0IF=0;
             PORTBbits.RB1=1; //turning on motor
            __delay_ms(2000);
            PORTBbits.RB1=0;  // turning of motor
            __delay_ms(3000);
            PORTBbits.RB1=1;  //again turning on motor after 3 seconds
            __delay_ms(2000);
            PORTBbits.RB1=0;  //turning of motor

        TMR0H= 0x26;
        TMR0L=0xD6;
    }
}
    
