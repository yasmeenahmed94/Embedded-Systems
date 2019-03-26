/*
 * led.c
 *
 *  Created on: Mar 26, 2019
 *      Author: Yasmeen
 */
#include"stdtypes.h"
#include"utilss.h"
#include"registers.h"
#include"dio.h"
#include"led_m.h"
#include"led.h"
//-----------------------------------
extern void LED_vidInit(void){
	u8 i;
	for(i=0;i<Led_Num ;i++)
	{
	 DIO_vidSetPinDirection(Led_Port,Led_Pins[i],Output);
	}
}
//-----------------------------------------
extern void LED_vidTurnONLed(u8 Led_Index){
	DIO_vidSetPinValue(Led_Port,Led_Pins[Led_Index],High);
}
//-----------------------------------------
extern void LED_vidTurnOffLed(u8 Led_Index){
	DIO_vidSetPinValue(Led_Port,Led_Pins[Led_Index],Low);
}
//-----------------------------------------
extern void LED_vidToggleLed(u8 Led_Index){
	DIO_vidTogglePin(Led_Port,Led_Pins[Led_Index]);

}
