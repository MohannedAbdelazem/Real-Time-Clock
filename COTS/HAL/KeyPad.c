/*
 * KeyPad.c
 *
 *  Created on: Nov 5, 2022
 *      Author: Mohanned
 */

#include "../MCAL/DIO_int.h"
#include "KeyPad_Int.h"
#include "avr/delay.h"

const u8 KPD_au8SwitchVal[4][4] = {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'A','0','=','+'}};
void KeyPadInit(){
	SetPortDirection(PORT, 0b00001111);
	SetPortValue(PORT, 0xff);

}

u8 KeyPadGetPressed(){

	  u8 Column;

	  u8 LOC_u8Row;
	  u8 LOC_u8Retrun = NOT_PRESSED;
	  for (Column = 0 + COL_INIT; Column < COL_FIN; Column++)
	  {
	    SetPinValue(PORT, Column, 0);
	    for (LOC_u8Row = 0 + ROW_INIT; LOC_u8Row < ROW_FIN; LOC_u8Row++)
	    {
	      if (!GetPinValue(PORT, LOC_u8Row))
	      {
	        LOC_u8Retrun = KPD_au8SwitchVal[Column - COL_INIT][LOC_u8Row - ROW_INIT];
	        while (!GetPinValue(PORT, LOC_u8Row));
	        _delay_ms(10);

	      }
	    }
	    SetPinValue(PORT, Column, 1);
	  }

	  return LOC_u8Retrun;
}

