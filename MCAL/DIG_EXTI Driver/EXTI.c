/*
 * EXTI.c
 *
 *  Created on: Apr 3, 2019
 *      Author: Yasmeen
 */
#include"stdtypes.h"
#include"utilss.h"
#include"registers.h"
#include"dio.h"
#include"EXTI_cfg.h"
#include"EXTI.h"
//============================================================
#define __INTR_ATTRS  used,externally_visible
//==============================================================
void __vector_1 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_2 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_3 (void)  __attribute__((signal,__INTR_ATTRS));
//==============================================================
extern void EXTI_vidInit(void){
	// set global interrupt peripheral
	set_bit(SREG,PIN7);

#if INT0== Enable
 // configure tigger of interrupt
DIO_vidSetPinValue(D,PIN2,High);
assign_bit(MCUCR,ISC00_bit,ISC00);
assign_bit(MCUCR,ISC01_bit,ISC01);
// enable peripheral interrupt
set_bit(GICR,6);
#endif
//-------------------------------------------------------------
#if INT1== Enable
DIO_vidSetPinValue(D,PIN3,High);
assign_bit(MCUCR,ISC10_bit,ISC10);
assign_bit(MCUCR,ISC11_bit,ISC11);
set_bit(GICR,7);
#endif
//--------------------------------------------------------------
#if INT2== Enable
DIO_vidSetPinValue(B,PIN2,High);
assign_bit(MCUCSR,ISC2_bit,ISC2);
set_bit(GICR,5);
#endif

}
//==============================================================
void __vector_1(void){
DIO_vidTogglePin(A,PIN0);
}
//==============================================================
void __vector_2(void){
	DIO_vidTogglePin(A,PIN1);
}
//==============================================================
void __vector_3(void){
	DIO_vidTogglePin(A,PIN2);
}
//==============================================================
