/*
 * main.c
 *
 *  Created on: Mar 26, 2019
 *      Author: Yasmeen
 */
#include"stdtypes.h"
#include"utilss.h"
#include"dio.h"
#include"led.h"
#include"avr/delay.h"



void main(void){

	LED_vidInit();
		while(1)
		{
	      LED_vidTurnONLed(0);
	      LED_vidTurnOffLed(1);
	      LED_vidTurnOffLed(2);
	      _delay_ms(2000);
	      LED_vidTurnONLed(1);
	      LED_vidTurnOffLed(0);
	      LED_vidTurnOffLed(2);
	      _delay_ms(2000);
	      LED_vidTurnONLed(2);
	      LED_vidTurnOffLed(0);
	      LED_vidTurnOffLed(1);
	      _delay_ms(2000);

		}





}
