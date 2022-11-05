/*
 * SevenSeg_int.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohanned
 */

#ifndef COTS_HAL_SEVENSEG_INT_H_
#define COTS_HAL_SEVENSEG_INT_H_

// Port D is going to be always on Output Display
#define DigitOne PIN3
#define DigitTwo PIN4
#define DigitThree PIN5
#define DigitFour PIN6

void Segment_Init();
void WriteSegment(u8 number);


#endif /* COTS_HAL_SEVENSEG_INT_H_ */
