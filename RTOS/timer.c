/*
 * timer.c
 *
 *  Created on: Jul 17, 2019
 *      Author: Yasmeen
 */
///


#include"registers.h"
#include"stdtypes.h"
#include"utilss.h"
#include"timer.h"

u16 counter=0;
u32 count_tick=0;
//*************************************************************
#define __INTR_ATTRS used,externally_visible
void __vector_11 (void)  __attribute__ ((signal,__INTR_ATTRS)); //overflow
//****************************************************************
void Timer_Init(void){
	// enable globale interrupt
	set_bit(SREG,7);
	// control timer 0//prescaler is 8 timer tictime is 1 micro
	TCCR0=0b00000010;
	//enable timer overflow interrupt
	TIMSK=0x01;
	// load TCNT0 with 0.25 tick
	TCNT0=192;



}
//*******************************************************************
void(*scheduler_callback)(void);
void set_scheduler_callback(void(*fptr)(void)){
	scheduler_callback=fptr;
}
//******************************************************************
void __vector_11 (void) {//enter here every 256 micro
counter++;
 if(counter==3907){//ticktime of scheduler must be greater than sum of all execution time of tasks
	              // let ticktime =1000ms // num of counts=3906.25
	//toggle_bit(PORTA,0);

        count_tick++;
        scheduler_callback();
        counter=0;

}
}

//********************************************************************
