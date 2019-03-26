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
#define assign_bit(reg,bitnum,value) do{clr_bit(reg,bitnum);reg=reg|(value<<bitnum);}while(0)

#endif /* UTILSS_H_ */
