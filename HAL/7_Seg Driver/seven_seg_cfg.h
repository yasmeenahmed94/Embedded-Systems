/*
 * seven_seg_cfg.h
 *
 *  Created on: Mar 26, 2019
 *      Author: Yasmeen
 */

#ifndef SEVEN_SEG_CFG_H_
#define SEVEN_SEG_CFG_H_
// number of seven segment you will use one or two
#define num_seven_seg 2

#if num_seven_seg==1
#define port1 A
#endif
#if num_seven_seg==2
#define port1 A
#define port2 B
#endif





#endif /* SEVEN_SEG_CFG_H_ */
