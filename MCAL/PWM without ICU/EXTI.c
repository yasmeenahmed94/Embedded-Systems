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
#include"TIMER1.h"
//============================================================
#define __INTR_ATTRS  used,externally_visible
u8 ICU_flag =0;
u16 TON= 0;
u16 TOFF=0;
//==============================================================
void __vector_1 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_2 (void)  __attribute__((signal,__INTR_ATTRS));
void __vector_3 (void)  __attribute__((signal,__INTR_ATTRS));
//==============================================================
extern void EXTI_vidInit(void){
	// set global interrupt peripheral
	set_bit(SREG,PIN7);

#if INT0== Enable

//DIO_vidSetPinValue(D,PIN2,High);// pullup for switch
assign_bit(MCUCR,ISC00_bit,ISC00);
assign_bit(MCUCR,ISC01_bit,ISC01);
// enable peripheral interrupt
set_bit(GICR,6);
#endif
//-------------------------------------------------------------
#if INT1== Enable
DIO_vidSetPinValue(D,PIN3,High);//pullup for switch
assign_bit(MCUCR,ISC10_bit,ISC10);
assign_bit(MCUCR,ISC11_bit,ISC11);
set_bit(GICR,7);
#endif
//--------------------------------------------------------------
#if INT2== Enable
DIO_vidSetPinValue(B,PIN2,High);//pullup for switch
assign_bit(MCUCSR,ISC2_bit,ISC2);
set_bit(GICR,5);
#endif

}
//==============================================================
void __vector_1(void){//INT0
if (ICU_flag==0){

	// change configuration of interrupt trigger from rising to falling
	//to enter ISR next time  at falling
	assign_bit(MCUCR,ISC00_bit,0);
	assign_bit(MCUCR,ISC01_bit,1);
	ICU_flag++;
	//start timer1 to count after rising edge till falling edge
		TIMER1_vidInit();
}
else if(ICU_flag==1){
	// store timer value in TON
	   TON=TCNT1L;

	// change configuration of interrupt trigger from falling to rising
	//to enter ISR next time at rising
		assign_bit(MCUCR,ISC00_bit,1);
		assign_bit(MCUCR,ISC01_bit,1);
		ICU_flag++;
		//reset timer to start in zero
		TCNT1L=0;
		//TCNT1H=0;


}
else if(ICU_flag==2){
	TOFF=TCNT1L;
	// change configuration of interrupt trigger from rising to falling
		//to enter ISR next time  at falling
		assign_bit(MCUCR,ISC00_bit,0);
		assign_bit(MCUCR,ISC01_bit,1);
		ICU_flag=0;


		TCNT1L=0;
	//	TCNT1H=0;


}



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
