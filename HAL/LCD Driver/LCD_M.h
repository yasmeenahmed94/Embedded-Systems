/*
 * LCD_M.h
 *
 *  Created on: Mar 27, 2019
 *      Author: Yasmeen
 */

#ifndef LCD_M_H_
#define LCD_M_H_
//-----------------------------------------------
#define Disable 0
#define Enable 1
//---------------------------------------------------
// configure the mode of LCD
#define four_bit Enable
#define eight_bit Disable
//------------------------------------------------------
// configure ports and pins you will use
#if eight_bit== Enable
// configure data port // you will need eight pins
#define data_port A
// configure control port //you will need 3 pins
#define control_port D
// configure 3 pins of control port
#define RSpin PIN0
#define RWpin PIN1
#define ENpin PIN2
#endif
//------------------------------------------------------------
// configure pins and ports u need
//note u nee only six pins four pins for data and two for RS & EN RW usually zero
#if four_bit==Enable


#define D7 A,PIN7
#define D6 A,PIN6
#define D5 A,PIN5
#define D4 A,PIN4

#define RS D,PIN0

#define EN D,PIN2

#endif

//========================================
// commands of LCD
//==========================================

#if eight_bit == Enable
#define func_set 0b00111000 //0x38
#define display  0b00001110//0x0e
#define clear    0b00000001//0x01
#define entrymode 0b00000110//0x03
#endif
//------------------------------------------------



//------------------------------------------------


#endif /* LCD_M_H_ */

