/*
 * registers.h
 *
 *  Created on: Mar 26, 2019
 *      Author: Yasmeen
 */

#ifndef REGISTERS_H_
#define REGISTERS_H_
#define PORTA *((volatile u8 *)0x3b)
#define DDRA *((volatile u8 *)0x3a)
#define PINA *((volatile u8 *)0x39)

#define PORTB *((volatile u8 *)0x38)
#define DDRB *((volatile u8 *)0x37)
#define PINB *((volatile u8 *)0x36)

#define PORTC *((volatile u8 *)0x35)
#define DDRC *((volatile u8 *)0x34)
#define PINC *((volatile u8 *)0x33)

#define PORTD *((volatile u8 *)0x32)
#define DDRD *((volatile u8 *)0x31)
#define PIND *((volatile u8 *)0x30)

#define MCUCR (*(volatile u8 *)0x55)
#define MCUCSR (*(volatile u8 *)0x54)
#define SREG (*(volatile u8 *)0x5f)
#define GICR (*(volatile u8 *)0x5b)

#define SFIOR  *((volatile u8 *)0x50)
#define ADMUX  *((volatile u8 *)0x27)
#define ADCSRA *((volatile u8 *)0x26)
#define ADCH   *((volatile u8 *)0x25)
#define ADCL  *((volatile u8 *)0x24)


#define TCCR0  *((volatile u8 *)0x53)
#define TCNT0 *((volatile u8 *)0x52)
#define TIMSK   *((volatile u8 *)0x59)
#define TIFR  *((volatile u8 *)0x58)
#define OCR0    *((volatile u8 *)0x5C)

#define TCCR1A  *((volatile u8 *)0x4F)
#define TCCR1B *((volatile u8 *)0x4E)
#define TCNT1H   *((volatile u8 *)0x4D)
#define TCNT1L  *((volatile u8 *)0x4C)

#define OCR1AH    *((volatile u8 *)0x4B)
#define OCR1AL    *((volatile u8 *)0x4A)
#define OCR1BH    *((volatile u8 *)0x49)
#define OCR1BL    *((volatile u8 *)0x48)
#define ICR1H    *((volatile u8 *)0x47)

#define ICR1L    *((volatile u16 *)0x46)
#define WDTCR   *((volatile u8 *)0x41)
////////////////////////////////////////
#define UDR   *((volatile u8 *)0x2c)
#define UCSRA   *((volatile u8 *)0x2b)
#define UCSRB   *((volatile u8 *)0x2a)
#define UBRRL   *((volatile u8 *)0x29)
#define UCSRC   *((volatile u8 *)0x40)
#define UBRRH   *((volatile u8 *)0x40)
///////////////////////////////////////////
#define SPDR  *((volatile u8 *)0x2f)
#define SPSR   *((volatile u8 *)0x2E)
#define SPCR   *((volatile u8 *)0x2D)




#endif /* REGISTERS_H_ */
