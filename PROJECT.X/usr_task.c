/*
 * File:   usr_task.c
 * Author: GEESU
 *
 * Created on 13 July, 2023, 12:07 AM
 */


#include <xc.h>
#include "config.h"

#define SW1 PORTBbits.RB2

void usrTask_CheckInput(void) //for push button 
{
    if (SW1 == 0) 
    { 
        __delay_ms(1000);
        if (SW1 == 1) 
        { 
            while (SW1 == 1); 
            PORTBbits.RB0=0;  //to turn off speaker when push button is pressed
        }
    }
   

    }  