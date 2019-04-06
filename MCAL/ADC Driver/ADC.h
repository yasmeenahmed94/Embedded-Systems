/*
 * ADC.h
 *
 *  Created on: Apr 5, 2019
 *      Author: Yasmeen
 */

#ifndef ADC_H_
#define ADC_H_
//----------------------------------------------------------
typedef enum{
	AREF=0x00,
	AVCC=0b01000000,
	Internal=0b11000000,



}voltage_ref;
//-----------------------------------------------------------------
typedef enum{
	left=0b00100000,
	right=0b00000000,
}adjustment;
//-----------------------------------------------------------------
typedef enum{
	ADC0=0b00000000,
	ADC1=0b00000001,
	ADC2=0b00000010,
	ADC3=0b00000011,
	ADC4=0b00000100,
	ADC5=0b00000101,
	ADC6=0b00000110,
	ADC7=0b00000111,

}channel_num;
//-----------------------------------------------------------------
typedef enum{
	enable=0b00001000,
	disable=0b00000000,
}Interrupt_state;
//------------------------------------------------------------------
typedef enum {
    DF_2=0b00000000,
	//DF_2=0b00000001,
	DF_4=0b00000010,
	DF_8=0b00000011,
	DF_16=0b00000100,
	DF_32=0b00000101,
	DF_64=0b00000110,
	DF_128=0b00000111,

}prescaler;
//------------------------------------------------------------------
typedef struct{
	voltage_ref voltref;
	adjustment adjust;
	channel_num ch_num;
	Interrupt_state int_state;
	prescaler pre;

}adc_config;

//=========================================================================
extern void ADC_vidInit(void);
extern u16 ADC_u16Result_Interrupt(void);
extern u16 ADC_u16Result_Polling(channel_num index);

//=========================================================================

#endif /* ADC_H_ */
