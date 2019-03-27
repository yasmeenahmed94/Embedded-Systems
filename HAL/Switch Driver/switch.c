/*
 * switch.c
 *
 *  Created on: Mar 27, 2019
 *      Author: Yasmeen
 */
#include"stdtypes.h"
#include"dio.h"
#include"switch_cfg.h"
#include"switch.h"

//=================================================
extern void SWITCH_vidInit(void){
	u8 i;
	// set direction of switches as Input
	for(i=0;i<sw_num;i++){
	DIO_vidSetPinDirection(sw_port,sw_pins[i],Input);
	}
	// set switches pull up resistor to avoid noise
	for(i=0;i<sw_num;i++){
	DIO_vidSetPinValue(sw_port,sw_pins[i],High);
	}
}
//==================================================
extern u8 SWITCH_u8Read( u8 sw_index){
	return DIO_u8GetPinValue(sw_port,sw_pins[sw_index]);


}
//====================================================
