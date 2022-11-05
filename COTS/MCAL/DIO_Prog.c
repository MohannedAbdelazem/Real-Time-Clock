/*
 * DIO_Prog.c
 *
 *  Created on: Nov 4, 2022
 *      Author: Mohanned
 */

#include"../LIB/BitMath.h"
#include "../LIB/StandardTypes.h"
#include"DIO_int.h"
#include "DIO_Registers.h"
void SetPinDirection(u8 port,u8 pin,u8 direction){
if(direction==OUTPUT){
switch(port){
case PORTA: setbit(DDRA_REG,pin);	break;
case PORTB: setbit(DDRB_REG,pin);	break;
case PORTC: setbit(DDRC_REG,pin);	break;
case PORTD: setbit(DDRD_REG,pin);	break;

}
}
else if (direction==INPUT){
	switch(port){
case PORTA: clearbit(DDRA_REG,pin);	break;
case PORTB: clearbit(DDRB_REG,pin);  break;
case PORTC: clearbit(DDRC_REG,pin);	break;
case PORTD: clearbit(DDRD_REG,pin);	break;
	}

}
}
void SetPinValue(u8 port,u8 pin,u8 value){
	if(value==1){
switch(port){
case PORTA: setbit(PORTA_REG,pin);	break;
case PORTB: setbit(PORTB_REG,pin);	break;
case PORTC: setbit(PORTC_REG,pin);	break;
case PORTD: setbit(PORTD_REG,pin);	break;

}


}
else if (value==0){
	switch(port){
case PORTA: clearbit(PORTA_REG,pin);	break;
case PORTB: clearbit(PORTB_REG,pin);  break;
case PORTC: clearbit(PORTC_REG,pin);	break;
case PORTD: clearbit(PORTD_REG,pin);	break;
	}

}
}
u8 GetPinValue(u8 port,u8 pin){
    u8 result=0xff;
	switch(port){
case PORTA: result= getbit(PINA_REG,pin);	break;
case PORTB: result= getbit(PINB_REG,pin);  break;
case PORTC: result= getbit(PINC_REG,pin);	break;
case PORTD: result= getbit(PIND_REG,pin);	break; 	}
	return result;

}
void SetPortDirection(u8 port,u8 direction){
switch(port){
case PORTA: DDRA_REG=direction;	break;
case PORTB: DDRB_REG=direction;	break;
case PORTC: DDRC_REG=direction;	break;
case PORTD: DDRD_REG=direction;	break;

}

}
void SetPortValue(u8 port,u8 value){
	switch(port){
case PORTA: PORTA_REG=value;	break;
case PORTB: PORTB_REG=value;	break;
case PORTC: PORTC_REG=value;	break;
case PORTD: PORTD_REG=value;	break;
	}






}
u8 GetPortValue(u8 port){
    u8 result=0x00;
	switch(port){
case PORTA: result=PINA_REG;	break;
case PORTB: result=PINB_REG;	break;
case PORTC: result=PINC_REG;	break;
case PORTD: result=PIND_REG;	break; 	}
	return result;

}


