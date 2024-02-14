/*
 * File:   main.c
 * Author: GEESU
 *
 * Created on 12 July, 2023, 4:39 PM
 */


#include <xc.h>
#include "config.h"



void initsyspins(void);
void initADC(void);
unsigned int adc_GetConversion(void);
void initSysExtInt(void);
void usrTask_CheckInput(void);

void call_speaker(void);
void initsysTimer0(void);   //to initialize the timer
void initsyspins(void);     //to initialize the pins
void dspLED(void);
void LEDPins(void);


//void mainLCD(void);
//void initSysExtInt(void);
void initLCD(void);
void IcdWriteDspData(char x);
void IcdCtrl_SetPos(unsigned char row, unsigned char col);
//void dspTask_OnLCD(void);

 
void main(void) {
    unsigned int result;
    initsyspins();
     char message1 []="";
    char message2 []="";
    unsigned int i;

  
    //initSysExtInt();
    initLCD();
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
    initADC();
    initSysExtInt();
     initsyspins();   //calling functions
    initsysTimer0();
    
    while(1){
        
         
         result =adc_GetConversion() ; //extracting the converted adc value
         usrTask_CheckInput();
         
        if(result<=30){
            call_speaker();   //calling speaker function to turn on speaker when oxygen is low
            PORTAbits.RA0=1;  //indication of oxygen through LEDs
            PORTAbits.RA1=0;
            PORTAbits.RA2=0;
            PORTAbits.RA3=0;
            PORTAbits.RA4=0; 
            PORTAbits.RA5=0;
            
}
        else if(result>100&&result<500){
            PORTAbits.RA0=0;
            PORTAbits.RA1=1;
            PORTAbits.RA2=0;
            PORTAbits.RA3=0;
            PORTAbits.RA4=0;
            PORTAbits.RA5=0;
            
}
        else if(result>=500&&result<=800){
            PORTAbits.RA0=0;
            PORTAbits.RA1=0;
            PORTAbits.RA2=1;
            PORTAbits.RA3=0;
            PORTAbits.RA4=0;
            PORTAbits.RA5=0;
            
 }
    
        else if(result>800)
        {
              dspLED();
  
        }
         else
              return;
       
}  

}
void initsyspins(void){
    ANSELA =0b00000000;
    TRISA  =0b11000000;
    ANSELE=0b00000010;
    TRISE=0b11111010;
    ANSELB=0b00000000;
    TRISB=0b11111100;
    ANSELD = 0b00000000;
    TRISD = 0b00001111;

} 
void call_speaker(void){ //function definition speaker
     
          PORTBbits.RB0=1;
        __delay_ms(500);
        PORTBbits.RB0=0;
        __delay_ms(500);
         
     } 
 
    



 
