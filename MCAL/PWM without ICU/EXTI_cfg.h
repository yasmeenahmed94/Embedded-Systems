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
#define INT1 Disable
#define INT2 Disable
//==============================================================
//configure trigger event for interrupt
//==============================================================
// configure first time with rising edge to enter ISR at rising edge
#if INT0==Enable
#define ISC00 1
#define ISC01 1

#endif
//===============================================================
#if INT1==Enable
#define ISC10 0
#define ISC11 1

#endif
//===============================================================
#if INT2==Enable
#define ISC2 0 // falling edge

#endif
//================================================================
#endif /* EXTI_CFG_H_ */
