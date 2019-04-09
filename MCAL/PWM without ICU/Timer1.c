/*
 * Timer1.c
 *
 *  Created on: Apr 7, 2019
 *      Author: Yasmeen
 */
#include"registers.h"
#include"stdtypes.h"
#include"utilss.h"
#include"Timer1.h"
#include"Timer1_cfg.h"
u16 count=0;
//=============================================================
#define __INTR_ATTRS used,externally_visible
void __vector_9(void) __attribute__ ((signal,__INTR_ATTRS));// overflow
void __vector_8(void) __attribute__ ((signal,__INTR_ATTRS));//comp_B
void __vector_7(void) __attribute__ ((signal,__INTR_ATTRS));//comp_A

//=============================================================
extern void TIMER1_vidInit(void){
	timer1_cfg * ptr=&configre;
	// configure TCCR1A
	TCCR1A=ptr->compA|ptr->compB|(WGM10<<WGM10_bit)|(WGM11<<WGM11_bit);
	// configure TCCR1B
	TCCR1B=(WGM12<<WGM12_bit)|(WGM13<<WGM13_bit)|(ptr->pre);
	//
    TCNT1L=TCNT1L_value;
	//TCNT1H=TCNT1H_value;
	//ICR1L=ICR1_value;



#if (comp_A==enable)
	//enable global interrupt
		set_bit(SREG,7);
	set_bit(TIMSK,4);
	OCR1AL=OCR1AL_value;
	OCR1AH=OCR1AH_value;
#endif
#if (comp_B==enable)
	//enable global interrupt
		set_bit(SREG,7);
	set_bit(TIMSK,3);
	OCR1BL=OCR1BL_value;
	OCR1BH=OCR1BH_value;
#endif
#if (overflow==enable)
	//enable global interrupt
		//set_bit(SREG,7);
	set_bit(TIMSK,2);
#endif


}
//=============================================================
void __vector_9(void){//over flow

	/*count++;
	if(count==122){
		 toggle_bit(PORTB,0);
		 count=0;

}*/
}
//=============================================================
void __vector_8(void){//comp_B
	count++;
		if(count==122){
		toggle_bit(PORTB,0);
		OCR1BL=OCR1BL_value;
		OCR1BH=OCR1BH_value;
		count=0;
	}

}
//=============================================================
void __vector_7(void){//comp_A
	count++;
	if(count==122){
	toggle_bit(PORTB,0);
	OCR1AL=OCR1AL_value;
	OCR1AH=OCR1AH_value;
	count=0;
}
}
//=============================================================
//=============================================================
//=============================================================
//=============================================================
//=============================================================

