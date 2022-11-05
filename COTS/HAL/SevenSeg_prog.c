/*
 * SevenSeg_prog.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohanned
 */

#include "../MCAL/DIO_int.h"
#include "SevenSeg_int.h"

void Segment_Init(){
	SetPortDirection(PORTD, 0xff);
}

void WriteSegment(u8 number){
	u8 arr[] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x47,0x7f,0x6f};
	SetPortValue(PORTD, arr[number]);
}


