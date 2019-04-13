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
#include"LCD.h"
#include"UART.h"
//===============================================

//===============================================
/********************************************
Control the LEDs on your kit by your computer !
Sending a number by the computer shall toggle the corresponding LED.
i.e sending ‘1’ toggles LED 1 , sending 2 toggles LED 2 and so on …

*********************************************/

int main(void){


UART_vidInit();
DIO_vidSetPinDirection(B,PIN0,Output);
DIO_vidSetPinDirection(B,PIN1,Output);
DIO_vidSetPinDirection(B,PIN2,Output);

while(1){
u8 k=UART_vidReceiveNum();
if (k==1){
	DIO_vidTogglePin(B,PIN0);
}
else if (k==2){
	DIO_vidTogglePin(B,PIN1);
}
else if (k==3){
	DIO_vidTogglePin(B,PIN2);
}
}
return 0;

}

