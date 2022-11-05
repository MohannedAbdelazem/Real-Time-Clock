/*
 * Timer0Prog.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohanned
 */

#include "../LIB/BitMath.h"
#include "../LIB/StandardTypes.h"
#include "Timer0.h"
#include "Timer0Registers.h"



void TimerInit(){
	//Set Timer mode to CTC mode
	setbit(TCCR0, 3);
	//Set PreScaler To 8
	setbit(TCCR0, 1);
	//Enable CTC interrupt
	setbit(TIMSK, 1);
}
void TimerCTC_Preload(u8 value){
	OCR0 = value;
}

void (*ISR_CPY)(void) = 0x00;
void SetCallBack(void (*ISR_func)(void)){
	ISR_CPY = ISR_func;
}
void __vector_10(void) __attribute__((signal));
void __vector_10(void){
	ISR_CPY();
}

u8 CheckFlag(){
	u8 res = 0;
	if(getbit(TIFR, 1) == 1){
		setbit(TIFR, 1);
		res = 1;
	}
	return res;
}
