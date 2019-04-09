/*
 * Timer0.h
 *
 *  Created on: Apr 7, 2019
 *      Author: Yasmeen
 */

#ifndef TIMER0_H_
#define TIMER0_H_



typedef enum{

	no_clk=0b00000000,
	no_pre=0b00000001,
	clk_8=0b00000010,
	clk_64=0b00000011,
	clk_256=0b00000100,
	clk_1024=0b00000101,
	clk_extr_falling=0b00000110,
	clk_extr_rising=0b00000111

}prescal;
//=========================================
typedef enum {
	normal=0b00000000,
	ctc=0b00001000,
	fast_pwm=0b01001000,
	phase_correct=0b01000000

}mode_timer;
//==========================================
typedef enum{
	oc0_disconnect=0b00000000,
	non_inverting=0b00100000,     //clear oc0 at ouput compare match
	inverting=0b00110000
}compare;

//=========================================
typedef struct{
	prescal pre ;
	mode_timer mode;
	compare comp;
}timer_cfg;
//==========================================
//==========================================
//==========================================
extern void TIMER0_vidInit(void);
#endif /* TIMER0_H_ */
