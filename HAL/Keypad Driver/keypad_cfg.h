/*
 * keypad_cfg.h
 *
 *  Created on: Apr 1, 2019
 *      Author: Yasmeen
 */

#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

//configure keypad port
#define keypad_port  C
// configure pin for first column
#define first_col PIN0
//configure pin for first row
#define first_row  PIN3
// configure pin for last column
#define last_col PIN2
//configure pin for last row
#define last_row  PIN5
// configure array of switches values
u8 keypad_arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};
#endif /* KEYPAD_CFG_H_ */
