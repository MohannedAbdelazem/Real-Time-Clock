/*
 * Timer0.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohanned
 */

#ifndef COTS_MCAL_TIMER0_H_
#define COTS_MCAL_TIMER0_H_

void TimerInit();
void TimerCTC_Preload(u8 value);
void SetCallBack(void (*ISR)(void));
u8 CheckFlag();


#endif /* COTS_MCAL_TIMER0_H_ */
