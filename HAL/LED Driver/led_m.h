/*
 * led_m.h
 *
 *  Created on: Mar 26, 2019
 *      Author: Yasmeen
 */

#ifndef LED_M_H_
#define LED_M_H_
// set number of leds to control
#define Led_Num 3
// set number of port which leds will be connected to
#define Led_Port B
// configure aray of pins in port that leds will be connected to
u8 Led_Pins[Led_Num]={PIN0,PIN1,PIN2};


#endif /* LED_M_H_ */
