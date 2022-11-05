/*
 * LCD_int.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohanned
 */

#ifndef COTS_HAL_LCD_INT_H_
#define COTS_HAL_LCD_INT_H_

#define ControlPort PORTA
#define DataPort PORTC
#define RS PIN0
#define RW PIN1
#define E PIN2

#define ClearLCD 0x01
#define Home 0x02
#define EntryMode 0x06
#define DisplayOn 0x0C
#define DisplayOff 0x08
#define Set8BitMode 0x38

void LCD_Init();
void SendCommand(u8 DB_Command);
void WriteChar(u8 character);
void SetPos (u8 Y,u8 X);
void WriteString(u8 pu8StringCpy[], u8 u8Index);
void PrintNumber(u16 number);
void LCD_CLEAR();


#endif /* COTS_HAL_LCD_INT_H_ */
