/*
 * stepper_cfg.h
 *
 *  Created on: Apr 2, 2019
 *      Author: Yasmeen
 */

#ifndef STEPPER_CFG_H_
#define STEPPER_CFG_H_
// configure mode full step or half step
#define full_step disable
#define half_step enable
// configure pins for uln2003A driver and opposite pins for motor
#define yellow  B,PIN2
#define blue    B,PIN0
#define pink    B,PIN1
#define orange  B,PIN3
//
#define disable 0
#define enable 1


#endif /* STEPPER_CFG_H_ */
