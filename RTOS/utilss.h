/*
 * utilss.h
 *
 *  Created on: Mar 26, 2019
 *      Author: Yasmeen
 */

#ifndef UTILSS_H_
#define UTILSS_H_

// function like macro
#define set_bit(reg,bitnum) reg=reg|(1<<bitnum)
#define clr_bit(reg,bitnum)  reg=reg&(~(1<<bitnum))
#define toggle_bit(reg,bitnum)  reg=reg^(1<<bitnum)
#define get_bit(reg,bitnum) ((reg&(1<<bitnum))>>bitnum)
#define assign_bit(reg,bitnum,value) do{clr_bit(reg,bitnum);reg=reg|((value)<<bitnum);}while(0)

#define set_high_nibble(reg) reg=reg|0xf0
#define clr_high_nibble(reg) reg=reg&0x0f
#define set_low_nibble(reg) reg=reg|0x0f
#define clr_low_nibble(reg) reg=reg&0xf0
#define get_high_nibble(reg) ((reg&0xf0)>>4)
#define get_low_nibble(reg)  (reg&0x0f)

#endif /* UTILSS_H_ */
