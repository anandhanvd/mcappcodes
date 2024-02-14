/*
 * File:   adc.c
 * Author: GEESU
 *
 * Created on 12 July, 2023, 5:06 PM
 */


#include <xc.h>
#include "config.h"

    void initADC(void){
        ADREF=0b00000000;
        ADCLK=0b00000011;
        ADACQ=0b00000000;
        ADCON0=0b10000100;
    }  
    unsigned int adc_GetConversion(void){
        unsigned int result;
        ADPCH= 0b00100001;//input channel re1
        __delay_us(2);
        ADCON0bits.ADGO=1;
        while(ADCON0bits.ADGO==1)
            result=ADRESH*256+ADRESL;

        return(result);
    } 
    unsigned int adc_GetConversion2(void)
{
    unsigned int result;
    ADPCH= 0b00011000;
    __delay_us(2);
    ADCON0bits.ADGO=1;
    while (ADCON0bits.ADGO==1);
    result= ADRESH*256 + ADRESL ;
            
    return(result);
}