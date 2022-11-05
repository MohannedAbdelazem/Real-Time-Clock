/*
 * DIO_Registers.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Mohanned
 */

#ifndef COTS_MCAL_DIO_REGISTERS_H_
#define COTS_MCAL_DIO_REGISTERS_H_

//PORTs registers
#define PORTA_REG *((volatile u8*)0x3B)
#define PORTB_REG *((volatile u8*)0x38)
#define PORTC_REG *((volatile u8*)0x35)
#define PORTD_REG *((volatile u8*)0x32)
//DDR registers
#define DDRA_REG *((volatile u8*)0x3A)
#define DDRB_REG *((volatile u8*)0x37)
#define DDRC_REG *((volatile u8*)0x34)
#define DDRD_REG *((volatile u8*)0x31)
//PIN registers
#define PINA_REG *((volatile u8*)0x39)
#define PINB_REG *((volatile u8*)0x36)
#define PINC_REG *((volatile u8*)0x33)
#define PIND_REG *((volatile u8*)0x30)



#endif /* COTS_MCAL_DIO_REGISTERS_H_ */
