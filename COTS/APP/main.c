/*
 * main.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Mohanned
 */

#include "../MCAL/DIO_int.h"
#include "avr/delay.h"
#include "../HAL/LCD_int.h"
#include "../HAL/KeyPad_Int.h"
#include "../HAL/SevenSeg_int.h"
#include "../MCAL/Timer0.h"
#include "../MCAL/GIE_INT.h"
#include "../HAL/LCDToTime.h"

u32 flag = 0;
u8 counter = 0;
u8 FirstDigit = 0;
u8 SecondDigit = 0;
u8 hours_counters = 0;
u8 minutes_counter = 0;
u8 seconds_counter = 0;
// Count To 5000 everytime to get to one second By Calculation which I'm not one hundred percent sure about but it's ok


int main(){
	GIE_Enable();
	TimerInit();
	TimerCTC_Preload(56);
	LCD_InitForTime();
	LCD_Init();
	KeyPadInit();
	WriteString("Press 1 to: ", 12);
	SetPos(2, 1);
	WriteString("Set Clock", 9);
	while(1){
		SetPos(1, 1);
		u8 value = KeyPadGetPressed();
		if(value != NOT_PRESSED){
			if(value == '1'){
				LCD_CLEAR();
				WriteString("Hours=--", 8);
				_delay_ms(500);
				do{
					FirstDigit = KeyPadGetPressed();
				}while(FirstDigit == NOT_PRESSED);
				WriteChar(FirstDigit);
				_delay_ms(300);
				do{
					SecondDigit = KeyPadGetPressed();
				}while(SecondDigit == NOT_PRESSED);
				WriteChar(SecondDigit);
				_delay_ms(300);
				hours_counters = (SecondDigit-'0')+10*(FirstDigit-'0');
				LCD_CLEAR();
				SetPos(1, 1);
				WriteString("Minutes=--", 10);
				do{
					FirstDigit = KeyPadGetPressed();

				}while(FirstDigit == NOT_PRESSED);
				WriteChar(FirstDigit);
				_delay_ms(300);
				do{
					SecondDigit = KeyPadGetPressed();
				}while(SecondDigit == NOT_PRESSED);
				WriteChar(SecondDigit);
				_delay_ms(300);
				minutes_counter = (SecondDigit-'0')+10*(FirstDigit-'0');
				LCD_CLEAR();
				SetPos(1, 1);
				WriteString("Seconds=--", 10);
				do{
					FirstDigit = KeyPadGetPressed();
				}while(FirstDigit == NOT_PRESSED);
				WriteChar(FirstDigit);
				_delay_ms(300);
				do{
					SecondDigit = KeyPadGetPressed();
				}while(SecondDigit == NOT_PRESSED);
				WriteChar(SecondDigit);
				_delay_ms(300);
				seconds_counter = (SecondDigit-'0')+10*(FirstDigit-'0');
				LCD_CLEAR();
				SetPos(1, 1);
				WriteString("Press 1 to", 10);
				SetPos(2, 1);
				WriteString("Set Clock", 9);
			}
			else{
				LCD_CLEAR();
				WriteString("Wrong Choice", 12);
				_delay_ms(1000);
				LCD_CLEAR();
				SetPos(1, 1);
				WriteString("Press 1 to", 10);
				SetPos(2, 1);
				WriteString("Set Clock", 9);
			}
		}

		SetPosForTime(1, 1);
		PrintNumberForTime(hours_counters/10);
		PrintNumberForTime(hours_counters%10);
		WriteCharForTime(':');
		PrintNumberForTime(minutes_counter/10);
		PrintNumberForTime(minutes_counter%10);
		WriteCharForTime(':');
		PrintNumberForTime(seconds_counter/10);
		PrintNumberForTime(seconds_counter%10);
				if (seconds_counter==60)
				{
					seconds_counter=0;
					minutes_counter++;
				}
				if (minutes_counter==60)
				{
					minutes_counter=0;
					hours_counters++;
				}
				if (hours_counters==24)
				{
					hours_counters=0;
				}
				if(CheckFlag()){
					flag++;
				}
				if(flag == 6){
					seconds_counter++;
					flag = 0;
				}
	}
	return 0;
}


