/*
 * keypad.c
 *
 *  Created on: Apr 1, 2019
 *      Author: Yasmeen
 */
#include"stdtypes.h"
#include"utilss.h"
#include"registers.h"
#include"dio.h"
#include"keypad_cfg.h"
#include"keypad.h"
//==========================================================
extern void KEYPAD_vidInit(void){
  // initialize the columns as output and high in the first time
	for(u8 i=first_col;i<=last_col;i++){
		DIO_vidSetPinDirection(keypad_port,i,Output);
		DIO_vidSetPinValue(keypad_port,i,High);

	}
 // initialize the rows as input and pulled up toavoid noise
	for(u8 i=first_row;i<=last_row;i++){
		DIO_vidSetPinDirection(keypad_port,i,Input);
		DIO_vidSetPinValue(keypad_port,i,High);
	}
}
//==========================================================
// algorithm of keypad to return Switch that is pressed
extern u8 KEYPAD_u8GetSwitch(void){

	u8 i_row,i_col;
	while(1){
	// make columns zero (low)one after one and other one(high)
	for(i_col=first_col;i_col<=last_col;i_col++){
		DIO_vidSetPinValue(keypad_port,i_col,Low);
		for(i_row=first_row;i_row<=last_row;i_row++){

			if(DIO_u8GetPinValue(keypad_port,i_row)==0){
               return keypad_arr[i_row-3][i_col];

			}
		}

		// donot forget to return this column high and check another one
		DIO_vidSetPinValue(keypad_port,i_col,High);
	}

	}
}
//==========================================================
//==========================================================
