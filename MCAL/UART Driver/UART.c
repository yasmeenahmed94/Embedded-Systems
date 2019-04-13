/*
 * UART.c
 *
 *  Created on: Apr 13, 2019
 *      Author: Yasmeen
 */


#include"registers.h"
#include"utilss.h"
#include"stdtypes.h"
#include"UART.h"
#include"UART_cfg.h"
#include"dio.h"
//==============================================
//=================================================
//===================================================
extern void UART_vidInit(void){
	UCSRA=0b00100000;
#if U2X==1
	set_bit(UCSRA,1);
#endif
//------------------------------------------------
	UCSRB=0b11111000;
#if mode_9==1
	set_bit(UCSRB,1);
	assign_bit(UCSRB,0,TX8);

#endif

//--------------------------------------------
	set_bit(UCSRC,7);
	UCSRC=0b10000110;

#if two_bit_stop==1
	set_bit(UCSRC,3);
#endif

#if even_parity==1
//clr_bit(UCSRC,4);
set_bit(UCSRC,5);

#endif

#if odd_parity==1
set_bit(UCSRC,4);
set_bit(UCSRC,5);
#endif

//--------------------------------------------------
	clr_bit(UBRRH,7);
	UBRRL=UBRRL_value;
	UBRRH=UBRRH_value;
//----------------------------------------------
	// directions of pin RX TX
	DIO_vidSetPinDirection(D,PIN0,Input);
	DIO_vidSetPinDirection(D,PIN1,Output);
//-------------------------------------------------------

}
//===================================================
extern void  UART_vidSend(u8 CHAR){
	while(get_bit(UCSRA,5)==0){}
	UDR=CHAR;
}
//===================================================
extern u8 UART_u8Receive(void){
	while(get_bit(UCSRA,7)==0){}
	return UDR;
}
//====================================================
extern void UART_vidSendString(u8*str){
	u8 i=0;
	while(*(str+i)!=0){
		UART_vidSend(*(str+i));
		i++;
	}
}
//===================================================
extern void UART_vidSendNum(u32 NUM){

	if(NUM==0){
		UART_vidSend((48));
	}
	else{
	u8 arr[10]={0};
	s8 i=0;
	while(NUM!=0){
		arr[i]=NUM%10;
		NUM=NUM/10;
		i++;
	}
	i=i-1;
	 while(i>=0){
		UART_vidSend((arr[i]+48));
		i--;
	}
}}
//====================================================
extern u8 UART_vidReceiveNum(){
	while(get_bit(UCSRA,7)==0){}
	return UDR-48;
}




//=============================================
