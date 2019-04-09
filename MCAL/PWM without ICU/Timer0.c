/*
 * Timer0.c
 *
 *  Created on: Apr 7, 2019
 *      Author: Yasmeen
 */



#include"stdtypes.h"
#include"utilss.h"
#include"registers.h"
#include "Timer0.h"
#include "Timer0_cfg.h"
//===============================================================
#define __INTR_ATTRS used,externally_visible
void __vector_11 (void)  __attribute__ ((signal,__INTR_ATTRS));//overflow
void __vector_10 (void) __attribute__ ((signal,__INTR_ATTRS));//compare match
 u16 counter_OV =0;

//===============================================================
extern void TIMER0_vidInit(void){


	timer_cfg * ptr=&config;

// configure TCCR0
	TCCR0|=ptr->comp|ptr->mode|ptr->pre;
	TCNT0=TCNT0_value;
	OCR0=OCR0_value;

	if (ptr->mode==normal){
		// enable global interrupt
		set_bit(SREG,7);
	 // enable overflow interrupt
	 set_bit(TIMSK,0);
	}
	else if ((ptr->mode==ctc)){
		// enable global interrupt
		set_bit(SREG,7);
	 // enable compare interrupt
		set_bit(TIMSK,1);
     }
}

//===============================================================
void __vector_11(void){ //overflow ISR
 counter_OV++;
 if(counter_OV==31250){

	 counter_OV=0;
	 TCNT0=TCNT0_value;
	 toggle_bit(PORTB,0);

 }
}
//===============================================================
void __vector_10(void){// compare match ISR


		 toggle_bit(PORTB,0);

}
//===============================================================
//===============================================================
//===============================================================
