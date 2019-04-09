/*
 * main.c
 *
 *  Created on:  Apr 6, 2019
 *      Author: Yasmeen
 */
#include<avr/delay.h>
#include"stdtypes.h"
#include"utilss.h"
#include"registers.h"
#include"dio.h"
#include"timer1.h"
#include"timer0.h"
#include"ADC.h"
#include"LCD.h"
#include"EXTI.h"
//===============================================
extern u16 TON;
extern u16 TOFF;
//===============================================
/********************************************

Implement a system that takes an input PWM and display its frequency and duty cycle on
a character LCD. Use timer 1 and EXTI 0 of your atmega32 microcontroller to implement
the ICU and use timer 0 to generate the PWM desired
*********************************************/

int main(void){
LCD_vidInit();
// configure oc0 as output
DIO_vidSetPinDirection(B,PIN3,Output);
// generate PWM by timer0
	TIMER0_vidInit();
EXTI_vidInit();




u16 Duty=0;
while(1){

LCD_vidSetCursorPosition(1,0);
LCD_vidDisplayNum(TON);
LCD_vidSetCursorPosition(2,0);
LCD_vidDisplayNum(TOFF);

Duty=((TON*100)/(TOFF+TON));
LCD_vidSetCursorPosition(2,5);
LCD_vidDisplayNum(Duty);


}
return 0;
}

