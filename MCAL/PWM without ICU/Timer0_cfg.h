/*
 * Timer0_cfg.h
 *
 *  Created on: Apr 7, 2019
 *      Author: Yasmeen
 */

#ifndef TIMER0_CFG_H_
#define TIMER0_CFG_H_
//==================================================
#define TCNT0_value 0
#define OCR0_value 127
//=============================================
timer_cfg config ={
		no_pre,
		fast_pwm,
		non_inverting,
};


#endif /* TIMER0_CFG_H_ */
