/*
 * dio.h
 *
 *  Created on: Mar 26, 2019
 *      Author: Yasmeen
 */

#ifndef DIO_H_
#define DIO_H_
#define A 0
#define B 1
#define C 2
#define D 3
#define Output 1
#define Input 0
#define High 1
#define Low 0

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

extern void DIO_vidSetPinDirection(u8 portnum,u8 pinnum,u8 dir);
extern void DIO_vidSetPinValue(u8 portnum,u8 pinnum, u8 value);
extern void DIO_vidTogglePin(u8 portnum,u8 pinnum);
extern u8 DIO_u8GetPinValue(u8 portnum,u8 pinnum);
extern void DIO_vidSetPortDirection(u8 portnum,u8 dir);
extern void DIO_vidSetPortValue(u8 portnum,u8 value);
extern u8 DIO_u8GetPortValue(u8 portnum);

#endif /* DIO_H_ */
