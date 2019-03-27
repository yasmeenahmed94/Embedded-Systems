/*
 * main.c
 *
 *  Created on: Mar 26, 2019
 *      Author: Yasmeen
 */
#include"stdtypes.h"
#include"utilss.h"
#include"dio.h"
#include"switch.h"
#include"led.h"
#include"LCD.h"
#include"avr/delay.h"
/********************************************
Write your name moving in sinusoidal wave on the LCD

*********************************************/

int main(void){
LCD_vidInit();


while(1){

	LCD_vidSetCursorPosition(1,0);
	LCD_vidWriteString("Lara");
	_delay_ms(500);
	LCD_vidSendCommand(0x01);
	LCD_vidSetCursorPosition(2,4);
	LCD_vidWriteString("Lara");
	_delay_ms(500);
	LCD_vidSendCommand(0x01);
	LCD_vidSetCursorPosition(1,8);
	LCD_vidWriteString("Lara");
	_delay_ms(500);
		LCD_vidSendCommand(0x01);
	LCD_vidSetCursorPosition(2,12);
	LCD_vidWriteString("Lara");
	_delay_ms(500);
	LCD_vidSendCommand(0x01);


}



return 0;
}
