/*
 * Timer0Registers.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohanned
 */

#ifndef COTS_MCAL_TIMER0REGISTERS_H_
#define COTS_MCAL_TIMER0REGISTERS_H_

#define TCCR0 *((volatile u8*) 0x53)
#define OCR0 *((volatile u8*) 0x5C)
#define TCNT0 *((volatile u8*) 0x52)
#define TIMSK *((volatile u8*) 0x59)
#define TIFR *((volatile u8*) 0x58)


#endif /* COTS_MCAL_TIMER0REGISTERS_H_ */
