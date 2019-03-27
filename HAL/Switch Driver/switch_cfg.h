/*
 * switch_cfg.h
 *
 *  Created on: Mar 27, 2019
 *      Author: Yasmeen
 */

#ifndef SWITCH_CFG_H_
#define SWITCH_CFG_H_

// configure the port which you will connect switch to
#define sw_port B
// configure the number of switches
#define sw_num 4
// configure array with pins of switches

 u8 sw_pins[sw_num]={PIN0,PIN1,PIN2,PIN3};


#endif /* SWITCH_CFG_H_ */
