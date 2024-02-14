/*
 * File:   LED.c
 * Author: GEESU
 *
 * Created on 8 August, 2023, 1:22 AM
 */


#include <xc.h>
#include"config.h"

void initSysPins(void);
void initADC(void);
unsigned int adc_GetConversion2(void);
void LEDPins(void);
void initLCD(void);
void IcdWriteDspData(char x);
void IcdCtrl_SetPos(unsigned char row, unsigned char col);
//void dspTask_OnLCD(void);

void dspLED(void) {
    unsigned int k;
    LEDPins();
    initADC();
    
    while (1)
    {
        k= adc_GetConversion2();
        if (k<20)
        {
            PORTA= 0b00100000;
            char message1 []="Temperature is";
        char message2 []="too low.";
        unsigned int i;
        IcdCtrl_SetPos(1,1);
        for(i =0; message1[i]!=0; i++)
    {
        IcdWriteDspData(message1[i]);
    }
        IcdCtrl_SetPos(2,1);
        for (i =0; message2[i]!=0; i++)
    {
        IcdWriteDspData(message2[i]);
    }

            
            
        }
         
        else if(k<35)
        {    PORTA = 0b00010000;
            char message1[]="Temperature is";
        char message2[]="just fine.";
        unsigned int i;
        IcdCtrl_SetPos(1,1);
        for(i =0; message1[i]!=0; i++)
    {
        IcdWriteDspData(message1[i]);
    }
        IcdCtrl_SetPos(2,1);
        for (i =0; message2[i]!=0; i++)
            {
        IcdWriteDspData(message2[i]);
    }


           
            
        }
        else
        {   PORTA= 0b00001000;
            char message1[]="Temperature is";
        char message2[]="too high.";
        unsigned int i;
        IcdCtrl_SetPos(1,1);
        for(i =0; message1[i]!=0; i++)
    {
        IcdWriteDspData(message1[i]);
    }
         IcdCtrl_SetPos(2,1);
        for (i =0; message2[i]!=0; i++)
    {
        IcdWriteDspData(message2[i]);
    }
    }

            
        }
    }        
    
    void LEDPins(void)
    {
        ANSELA= 0b00000000;
        TRISA= 0b11000000;
    }