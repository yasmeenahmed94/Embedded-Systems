/*
 * UART.h
 *
 *  Created on: Apr 13, 2019
 *      Author: Yasmeen
 */

#ifndef UART_H_
#define UART_H_

#define RX8_bit 1

extern void  UART_vidSend(u8 CHAR);
extern void UART_vidInit(void);
extern u8 UART_u8Receive(void);
extern void UART_vidSendString(u8*str);
extern void UART_vidSendNum(u32 NUM);
extern u8 UART_vidReceiveNum();
#endif /* UART_H_ */
