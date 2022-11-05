/*
 * DIO_int.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Mohanned
 */

#ifndef COTS_MCAL_DIO_INT_H_
#define COTS_MCAL_DIO_INT_H_

#include "../LIB/StandardTypes.h"

void SetPinDirection(u8 port,u8 pin,u8 directon);
void SetPinValue(u8 port,u8 pin,u8 value);
u8 GetPinValue(u8 port,u8 pin);
u8 GetPortValue(u8 port);
void SetPortDirection(u8 port,u8 directon);
void SetPortValue(u8 port,u8 value);

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

#define DDRA 0
#define DDRB 1
#define DDRC 2
#define DDRD 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define OUTPUT 1
#define INPUT  0


#endif /* COTS_MCAL_DIO_INT_H_ */
