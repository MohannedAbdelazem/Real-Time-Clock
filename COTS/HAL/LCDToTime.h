/*
 * LCDToTime.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohanned
 */

#ifndef COTS_HAL_LCDTOTIME_H_
#define COTS_HAL_LCDTOTIME_H_

#define ControlPort_T PORTA
#define DataPort_T PORTD
#define RS_T PIN3
#define RW_T PIN4
#define E_T PIN5

#define ClearLCD_T 0x01
#define Home_T 0x02
#define EntryMode_T 0x06
#define DisplayOn_T 0x0C
#define DisplayOff_T 0x08
#define Set8BitMode_T 0x38

void LCD_InitForTime();
void SendCommandForTime(u8 DB_Command);
void WriteCharForTime(u8 character);
void SetPosForTime (u8 Y,u8 X);
void WriteStringForTime(u8 pu8StringCpy[], u8 u8Index);
void PrintNumberForTime(u16 number);
void LCD_CLEARForTime();


#endif /* COTS_HAL_LCDTOTIME_H_ */
