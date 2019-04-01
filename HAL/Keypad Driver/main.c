/*
 * main.c
 *
 *  Created on: Mar 26, 2019
 *      Author: Yasmeen
 */
#include"stdtypes.h"
#include"utilss.h"
#include"dio.h"
#include"seven_seg.h"
#include"keypad.h"
#include"LCD.h"
#include"avr/delay.h"
/********************************************
Write a code that uses 3x3 keypad and 1 7-Segment Display to display the
number of the pressed button on the 7-segement (1 To 9) and LCD

*********************************************/

int main(void){
SEG_vidInit();
KEYPAD_vidInit();
LCD_vidInit();
u8 key=0;


//LCD_vidDisplayNum(5);

while(1){
	key=KEYPAD_u8GetSwitch();
	_delay_ms(500);
	LCD_vidDisplayNum(key);
	SEG_vidDisplayNum(key);

}



return 0;
}
