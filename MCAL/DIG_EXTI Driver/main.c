/*
 * main.c
 *
 *  Created on:  Apr 3, 2019
 *      Author: Yasmeen
 */
#include"stdtypes.h"
#include"utilss.h"
#include"dio.h"
#include"keypad.h"
#include"LCD.h"
#include"EXTI.h"

/********************************************
Write a C code that uses 3 buttons on 3 External Interrupt pins.
The interrupt triggering source shall be configured as falling edge.
Each button has its own ISR that toggles different LED.

*********************************************/

int main(void){

DIO_vidSetPinDirection(A,PIN0,Output);
DIO_vidSetPinDirection(A,PIN1,Output);
DIO_vidSetPinDirection(A,PIN2,Output);


EXTI_vidInit();


while(1){
}
return 0;
}

