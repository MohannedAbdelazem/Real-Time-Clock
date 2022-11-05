/*
 * LCD_Prog.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohanned
 */

#include "../MCAL/DIO_int.h"
#include "LCD_int.h"
#include "avr/delay.h"
void LCD_Init(){
	SetPortDirection(ControlPort, 0xff);
	SetPortDirection(DataPort, 0xff);
	_delay_ms(30); // Wait for LCD to start
	SendCommand(Home);
	_delay_ms(15);
	SendCommand(Set8BitMode);
	_delay_ms(1);
	SendCommand(DisplayOn);
	_delay_ms(1);
	SendCommand(ClearLCD);
	_delay_ms(15);
	SendCommand(EntryMode);
	_delay_ms(2);

}

void SendCommand(u8 DB_Command){
	SetPinValue(ControlPort, RS, INPUT);
	SetPinValue(ControlPort, RW, INPUT);
	SetPinValue(ControlPort, E, OUTPUT); // Set E to high
	SetPortValue(DataPort, DB_Command);
	SetPinValue(ControlPort, E, INPUT); // Set E to low
	_delay_ms(5);
	SetPinValue(ControlPort, E, OUTPUT);
	_delay_ms(10);
}

void WriteChar(u8 character){
	SetPinValue(ControlPort, RS, 1);
	SetPinValue(ControlPort, RW, 0);
	SetPinValue(ControlPort, E, 1);
	SetPortValue(DataPort, character);
	SetPinValue(ControlPort, E, 0);
	_delay_ms(5);
	SetPinValue(ControlPort, E, 1);
	_delay_ms(10);
}
void SetPos (u8 Y,u8 X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	SendCommand(X+127);
		    break;
		    case 2:
		    	SendCommand(X+127+ 0x40);
		    break;
		    default:
		    break;
	    }
	}
}

void WriteString(u8 pu8StringCpy[], u8 u8Index)
{
	u8 iteration=0;
	for (iteration=0; iteration<u8Index ; iteration++)
	{
		WriteChar(pu8StringCpy[iteration]);

		_delay_ms(2);
	}

}

void PrintNumber(u16 number)
{
	do
	{
		u16 remainder = number%10;
		number = number/10;
		WriteChar(remainder+'0');

	}while(number != 0);
}


void LCD_CLEAR()
{
	SendCommand(ClearLCD);
	_delay_ms(10);
}
