/*
 * Timer1.h
 *
 *  Created on: Apr 7, 2019
 *      Author: Yasmeen
 */

#ifndef TIMER1_H_
#define TIMER1_H_
//---------------------------------------------
#define enable 1
#define disable 0
//----------------------------------------------
#define WGM10_bit 0
#define WGM11_bit 1
#define WGM12_bit 3
#define WGM13_bit 4
//-----------------------------------------------
typedef enum{
	oc1A_disconnected =0b00000000,

	oc1A_clr=0b10000000, //non inverting
	oc1A_set=0b11000000  // inverting

}compare_chA;
//-----------------------------------------------
typedef enum{
	oc1B_disconnected =0b00000000,

	oc1B_clr=0b00100000,  //non inverting
	oc1B_set=0b00110000

}compare_chB;

//-----------------------------------------------
typedef enum{
	no__clk=0b00000000,
	no__pre=0b00000001,
	clk__8=0b00000010,
	clk__64=0b00000011,
	clk__256=0b00000100,
	clk__1024=0b00000101,
	clk__extr_falling=0b00000110,
	clk__extr_rising=0b00000111

}prescaler;

//================================================
typedef struct {
	compare_chA compA;
	compare_chB compB;
	prescaler pre;

}timer1_cfg;
//==================================================
//==================================================
extern void TIMER1_vidInit(void);


#endif /* TIMER1_H_ */
