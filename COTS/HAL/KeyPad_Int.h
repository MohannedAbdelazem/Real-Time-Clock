/*
 * KeyPad_Int.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohanned
 */

#ifndef COTS_HAL_KEYPAD_INT_H_
#define COTS_HAL_KEYPAD_INT_H_

#define PORT PORTB
#define COL_INIT 0
#define COL_FIN 4
#define ROW_INIT 4
#define ROW_FIN 8

#define NOT_PRESSED 0xff

void KeyPadInit();
u8 KeyPadGetPressed();

#endif /* COTS_HAL_KEYPAD_INT_H_ */
