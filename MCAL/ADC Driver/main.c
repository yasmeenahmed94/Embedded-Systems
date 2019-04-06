/*
 * main.c
 *
 *  Created on:  Apr 6, 2019
 *      Author: Yasmeen
 */
#include<avr/delay.h>
#include"stdtypes.h"
#include"utilss.h"
#include"LCD.h"
#include"ADC.h"
/********************************************
Implement a system that display a voltage value on LCD in volt
unit. Use a potentiometer to change the input voltage on the system.

*********************************************/

int main(void){
u16 volt_out;
u8 volt_in;
LCD_vidInit();
ADC_vidInit();



while(1){
	LCD_vidSendCommand(0x01);
volt_out=ADC_u16Result_Polling(ADC0);
  //volt_out=ADC_u16Result_Interrupt();
  // Apply mul first then DIV
volt_in=(volt_out*5)/1024;

LCD_vidSetCursorPosition(1,0);
LCD_vidWriteString("analog:");
LCD_vidDisplayNum(volt_in);
LCD_vidSetCursorPosition(2,0);
LCD_vidWriteString("digital:");
LCD_vidDisplayNum(volt_out);
_delay_ms(150);

}
return 0;
}

