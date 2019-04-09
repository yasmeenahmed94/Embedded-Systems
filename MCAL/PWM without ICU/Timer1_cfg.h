/*
 * Timer1_cfg.h
 *
 *  Created on: Apr 7, 2019
 *      Author: Yasmeen
 */

#ifndef TIMER1_CFG_H_
#define TIMER1_CFG_H_
//===============================================
#define comp_A disable
#define comp_B disable
#define overflow enable
//======================================
// configure bits of mode
#define WGM10 0
#define WGM11 0
#define WGM12 0
#define WGM13 0
//==============================================
#define TCNT1L_value 0
#define TCNT1H_value 0

#define OCR1AL_value 0
#define OCR1AH_value 0
#define OCR1BL_value 0
#define OCR1BH_value 0

#define ICR1_value 0

//===============================================
timer1_cfg configre= {
 oc1A_disconnected,
 oc1B_disconnected,
 no__pre,
};
//==============================================
#endif /* TIMER1_CFG_H_ */
