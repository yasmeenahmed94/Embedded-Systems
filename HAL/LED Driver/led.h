/*
 * led.h
 *
 *  Created on: Mar 26, 2019
 *      Author: Yasmeen
 */

#ifndef LED_H_
#define LED_H_
extern void LED_vidInit(void);
extern void LED_vidTurnONLed(u8 Led_Index);
extern void LED_vidTurnOffLed(u8 Led_Index);
extern void LED_vidToggleLed(u8 Led_Index);
#endif /* LED_H_ */
