/*
 * EXTI_cfg.h
 *
 *  Created on: Apr 3, 2019
 *      Author: Yasmeen
 */

#ifndef EXTI_CFG_H_
#define EXTI_CFG_H_
// INT0 D2//INT1 D3//INT2 B2
//===========================================================
#define Enable 1
#define Disable 0
// configure which external interrput peripheral  you will use
#define INT0 Enable
#define INT1 Enable
#define INT2 Enable
//==============================================================
//configure trigger event for interrupt
//==============================================================
#if INT0==Enable
#define ISC00 0
#define ISC01 1
#define ISC00_bit 0
#define ISC01_bit 1
#endif
//===============================================================
#if INT1==Enable
#define ISC10 0
#define ISC11 1
#define ISC10_bit 2
#define ISC11_bit 3
#endif
//===============================================================
#if INT2==Enable
#define ISC2 0 // falling edge
#define ISC2_bit 6
#endif
//================================================================
#endif /* EXTI_CFG_H_ */
