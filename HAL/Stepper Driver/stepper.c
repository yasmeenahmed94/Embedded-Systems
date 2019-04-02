/*
 * stepper.c
 *
 *  Created on: Apr 2, 2019
 *      Author: Yasmeen
 */

#include"stdtypes.h"
#include"utilss.h"
#include"registers.h"
#include"dio.h"
#include"stepper_cfg.h"
#include"stepper.h"
#include"avr/delay.h"
//===================================================================
extern void STEPPER_vidInit(void){
	DIO_vidSetPinDirection(yellow,Output);
	DIO_vidSetPinDirection(pink,Output);
	DIO_vidSetPinDirection(blue,Output);
	DIO_vidSetPinDirection(orange,Output);

}
//===================================================================
extern void STEPPER_vidCW(void){
#if full_step ==enable
			DIO_vidSetPinValue(blue,High);
			DIO_vidSetPinValue(pink,Low);
			DIO_vidSetPinValue(yellow,Low);
			DIO_vidSetPinValue(orange,Low);
			_delay_ms(3);
			DIO_vidSetPinValue(blue,Low);
			DIO_vidSetPinValue(pink,High);
			DIO_vidSetPinValue(yellow,Low);
			DIO_vidSetPinValue(orange,Low);
			_delay_ms(3);
			DIO_vidSetPinValue(blue,Low);
			DIO_vidSetPinValue(pink,Low);
			DIO_vidSetPinValue(yellow,High);
			DIO_vidSetPinValue(orange,Low);
			_delay_ms(3);
			DIO_vidSetPinValue(blue,Low);
			DIO_vidSetPinValue(pink,Low);
			DIO_vidSetPinValue(yellow,Low);
			DIO_vidSetPinValue(orange,High);
			_delay_ms(3);
#endif
#if half_step==enable
DIO_vidSetPinValue(blue,High);
DIO_vidSetPinValue(pink,Low);
DIO_vidSetPinValue(yellow,Low);
DIO_vidSetPinValue(orange,Low);
_delay_ms(3);
DIO_vidSetPinValue(blue,High);
DIO_vidSetPinValue(pink,High);
DIO_vidSetPinValue(yellow,Low);
DIO_vidSetPinValue(orange,Low);
_delay_ms(3);
DIO_vidSetPinValue(blue,Low);
DIO_vidSetPinValue(pink,High);
DIO_vidSetPinValue(yellow,Low);
DIO_vidSetPinValue(orange,Low);
_delay_ms(3);
DIO_vidSetPinValue(blue,Low);
DIO_vidSetPinValue(pink,High);
DIO_vidSetPinValue(yellow,High);
DIO_vidSetPinValue(orange,Low);
_delay_ms(3);
DIO_vidSetPinValue(blue,Low);
DIO_vidSetPinValue(pink,Low);
DIO_vidSetPinValue(yellow,High);
DIO_vidSetPinValue(orange,Low);
_delay_ms(3);
DIO_vidSetPinValue(blue,Low);
DIO_vidSetPinValue(pink,Low);
DIO_vidSetPinValue(yellow,High);
DIO_vidSetPinValue(orange,High);
_delay_ms(3);
DIO_vidSetPinValue(blue,Low);
DIO_vidSetPinValue(pink,Low);
DIO_vidSetPinValue(yellow,Low);
DIO_vidSetPinValue(orange,High);
_delay_ms(3);
DIO_vidSetPinValue(blue,High);
DIO_vidSetPinValue(pink,Low);
DIO_vidSetPinValue(yellow,Low);
DIO_vidSetPinValue(orange,High);
_delay_ms(3);

#endif

}
//===================================================================
extern void STEPPER_vidCCW(void){
#if full_step==enable
			DIO_vidSetPinValue(orange,High);
			DIO_vidSetPinValue(yellow,Low);
			DIO_vidSetPinValue(pink,Low);
			DIO_vidSetPinValue(blue,Low);
			_delay_ms(3);
			DIO_vidSetPinValue(orange,Low);
			DIO_vidSetPinValue(yellow,High);
			DIO_vidSetPinValue(pink,Low);
			DIO_vidSetPinValue(blue,Low);
			_delay_ms(3);
			DIO_vidSetPinValue(orange,Low);
			DIO_vidSetPinValue(yellow,Low);
			DIO_vidSetPinValue(pink,High);
			DIO_vidSetPinValue(blue,Low);
			_delay_ms(3);
			DIO_vidSetPinValue(orange,Low);
			DIO_vidSetPinValue(yellow,Low);
			DIO_vidSetPinValue(pink,Low);
			DIO_vidSetPinValue(blue,High);
			_delay_ms(3);
#endif
#if half_step ==enable
DIO_vidSetPinValue(orange,High);
DIO_vidSetPinValue(yellow,Low);
DIO_vidSetPinValue(pink,Low);
DIO_vidSetPinValue(blue,Low);
_delay_ms(3);
DIO_vidSetPinValue(orange,High);
DIO_vidSetPinValue(yellow,High);
DIO_vidSetPinValue(pink,Low);
DIO_vidSetPinValue(blue,Low);
_delay_ms(3);
DIO_vidSetPinValue(orange,Low);
DIO_vidSetPinValue(yellow,High);
DIO_vidSetPinValue(pink,Low);
DIO_vidSetPinValue(blue,Low);
_delay_ms(3);
DIO_vidSetPinValue(orange,Low);
DIO_vidSetPinValue(yellow,High);
DIO_vidSetPinValue(pink,High);
DIO_vidSetPinValue(blue,Low);
_delay_ms(3);
DIO_vidSetPinValue(orange,Low);
DIO_vidSetPinValue(yellow,Low);
DIO_vidSetPinValue(pink,High);
DIO_vidSetPinValue(blue,Low);
_delay_ms(3);
DIO_vidSetPinValue(orange,Low);
DIO_vidSetPinValue(yellow,Low);
DIO_vidSetPinValue(pink,High);
DIO_vidSetPinValue(blue,High);
_delay_ms(3);
DIO_vidSetPinValue(orange,Low);
DIO_vidSetPinValue(yellow,Low);
DIO_vidSetPinValue(pink,Low);
DIO_vidSetPinValue(blue,High);
_delay_ms(3);
DIO_vidSetPinValue(orange,High);
DIO_vidSetPinValue(yellow,Low);
DIO_vidSetPinValue(pink,Low);
DIO_vidSetPinValue(blue,High);
_delay_ms(3);


#endif
}
//===================================================================

//===================================================================
