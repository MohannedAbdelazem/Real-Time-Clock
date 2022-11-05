/*
 * GIE_Prog.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohanned
 */

#include "../LIB/BitMath.h"
#include "../LIB/StandardTypes.h"
#include "GIE_Register.h"
#include "GIE_INT.h"


void GIE_Enable(){
	setbit(SREG, 7);
}

void GIE_Disable(){
	clearbit(SREG, 7);
}

