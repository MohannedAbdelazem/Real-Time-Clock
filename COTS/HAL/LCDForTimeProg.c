/*
 * LCDForTimeProg.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohanned
 */

#include "../MCAL/DIO_int.h"
#include "avr/delay.h"
#include "LCDToTime.h"

void LCD_InitForTime(){
	SetPortDirection(ControlPort_T, 0xff);
	SetPortDirection(DataPort_T, 0xff);
	_delay_ms(30); // Wait for LCD to start
	SendCommandForTime(Home_T);
	_delay_ms(15);
	SendCommandForTime(Set8BitMode_T);
	_delay_ms(1);
	SendCommandForTime(DisplayOn_T);
	_delay_ms(1);
	SendCommandForTime(ClearLCD_T);
	_delay_ms(15);
	SendCommandForTime(EntryMode_T);
	_delay_ms(2);

}

void SendCommandForTime(u8 DB_Command){
	SetPinValue(ControlPort_T, RS_T, INPUT);
	SetPinValue(ControlPort_T, RW_T, INPUT);
	SetPinValue(ControlPort_T, E_T, OUTPUT); // Set E to high
	SetPortValue(DataPort_T, DB_Command);
	SetPinValue(ControlPort_T, E_T, INPUT); // Set E to low
	_delay_ms(5);
	SetPinValue(ControlPort_T, E_T, OUTPUT);
	_delay_ms(10);
}

void WriteCharForTime(u8 character){
	SetPinValue(ControlPort_T, RS_T, 1);
	SetPinValue(ControlPort_T, RW_T, 0);
	SetPinValue(ControlPort_T, E_T, 1);
	SetPortValue(DataPort_T, character);
	SetPinValue(ControlPort_T, E_T, 0);
	_delay_ms(5);
	SetPinValue(ControlPort_T, E_T, 1);
	_delay_ms(10);
}
void SetPosForTime (u8 Y,u8 X)
{
	if (X>0 && X<=16)
	{
	    switch(Y)
	    {
		    case 1:
		    	SendCommandForTime(X+127);
		    break;
		    case 2:
		    	SendCommandForTime(X+127+ 0x40);
		    break;
		    default:
		    break;
	    }
	}
}

void WriteStringForTime(u8 pu8StringCpy[], u8 u8Index)
{
	u8 iteration=0;
	for (iteration=0; iteration<u8Index ; iteration++)
	{
		WriteCharForTime(pu8StringCpy[iteration]);

		_delay_ms(2);
	}

}

void PrintNumberForTime(u16 number)
{
	do
	{
		u16 remainder = number%10;
		number = number/10;
		WriteCharForTime(remainder+'0');

	}while(number != 0);
}


void LCD_CLEARForTime()
{
	SendCommandForTime(ClearLCD_T);
	_delay_ms(10);
}

