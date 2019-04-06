/*
 * ADC.c
 *
 *  Created on: Apr 5, 2019
 *      Author: Yasmeen
 */

#include"registers.h"
#include"utilss.h"
#include"stdtypes.h"
#include"ADC.h" //first
#include"ADC_cfg.h"
//============================================================
#define __INTR_ATTRS  used,externally_visible
void __vector_16(void) __attribute__(( signal,__INTR_ATTRS));
u16 Result;
//============================================================
extern void ADC_vidInit(void){
	// pointer to stucture of ADC_config has address of member configuration
	adc_config * ptr=&configuration;
	// configure ADCMUX register
	ADMUX|=ptr->adjust|ptr->ch_num|ptr->voltref;

	// configure ADCSRA register
	// enable ADC
	 set_bit(ADCSRA,7);
	if(ptr->int_state==enable)
	{
		// enable global interrupt
		set_bit(SREG,7);
		//enable ADC interrupt
		set_bit(ADCSRA,3);

		// start conversion
			set_bit(ADCSRA,6);
	}

	ADCSRA|=ptr->pre|ptr->int_state;

}
//============================================================
extern u16 ADC_u16Result_Polling(channel_num index){
	u16 value;
	adc_config *ptr=&configuration;
	ADMUX&=0b11100000;
	ADMUX|=index;
	// start conversion
	set_bit(ADCSRA,6);
	// polling
	while(get_bit(ADCSRA,4)==0){

	}
	// clear flag by write one  as no interrupt
	clr_bit(ADCSRA,4);
	if(ptr->adjust==right)
	{
		value=ADCL;
		value|=(u16)(ADCH<<8);
	}
	else if(ptr->adjust==left)
	{
			value=(ADCL>>6);
			value|=(u16)(ADCH<<2);
	}
	else{

	}

	return value;
}

//============================================================
void __vector_16(void){
	adc_config *ptr=&configuration;
	if(ptr->adjust==right)
		{
			Result=ADCL;
			Result|=(u16)(ADCH<<8);
		}
		else if(ptr->adjust==left)
		{
			Result=(ADCL>>6);
			Result|=(u16)(ADCH<<2);
		}



}
//============================================================
extern u16 ADC_u16Result_Interrupt(void){
   //start conversio again
	set_bit(ADCSRA,6);
	return Result;
}
//============================================================
