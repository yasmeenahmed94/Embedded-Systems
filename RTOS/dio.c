/*
 * dio.c
 *
 *  Created on: Mar 26, 2019
 *      Author: Yasmeen
 */
#include "stdtypes.h"
#include"utilss.h"
#include"registers.h"
#include"dio.h"

//---------------------------------------

extern void DIO_vidSetPinDirection(u8 portnum,u8 pinnum,u8 dir){
	switch (portnum){
	case 0:
		assign_bit(DDRA,pinnum,dir);
	break;

	case 1:
		assign_bit(DDRB,pinnum,dir);
	break;

	case 2:
		assign_bit(DDRC,pinnum,dir);
	break;

	case 3:
		assign_bit(DDRD,pinnum,dir);
	break;


	}
}
//--------------------------------------------------
extern void DIO_vidSetPinValue(u8 portnum,u8 pinnum, u8 value){
	switch(portnum){
	case 0:
			assign_bit(PORTA,pinnum,value);
		break;

		case 1:
			assign_bit(PORTB,pinnum,value);
		break;

		case 2:
			assign_bit(PORTC,pinnum,value);
		break;

		case 3:
			assign_bit(PORTD,pinnum,value);
		break;

	}

}
//---------------------------------------------------
extern void DIO_vidTogglePin(u8 portnum,u8 pinnum){
	switch(portnum){
	case 0:
		 toggle_bit(PORTA,pinnum);
		break;

		case 1:
			toggle_bit(PORTB,pinnum);
		break;

		case 2:
			toggle_bit(PORTC,pinnum);
		break;

		case 3:
			toggle_bit(PORTD,pinnum);
		break;

	}

}
//-------------------------------------------------
extern u8 DIO_u8GetPinValue(u8 portnum,u8 pinnum){
	switch(portnum){
		case 0:
		return	get_bit(PINA,pinnum);
		break;

		case 1:
		return	get_bit(PINB,pinnum);
		break;

		case 2:
		return	get_bit(PINC,pinnum);
		break;

		case 3:
		return	get_bit(PIND,pinnum);
		break;


	}


}
//----------------------------------------
extern void DIO_vidSetPortDirection(u8 portnum,u8 dir){
	switch (portnum){
	case 0:
		DDRA=dir;
	break;

	case 1:
		DDRB=dir;
	break;

	case 2:
		DDRC=dir;
	break;

	case 3:
		DDRD=dir;
	break;


	}
}
//-----------------------------------------------
extern void DIO_vidSetPortValue(u8 portnum,u8 value){
	switch (portnum){
	case 0:
		PORTA=value;
	break;

	case 1:
		PORTB=value;
	break;

	case 2:
		PORTC=value;
	break;

	case 3:
		PORTD=value;
	break;


	}
}
//---------------------------------------------------
extern u8 DIO_u8GetPortValue(u8 portnum){
	switch (portnum){
	case 0:
		return PINA;
	break;

	case 1:
		return PINB;
	break;

	case 2:
		return PINC;
	break;

	case 3:
		return PIND;
	break;


	}
}
////=======================================================
