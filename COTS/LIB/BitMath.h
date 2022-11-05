/*
 * BitMath.h
 *
 *  Created on: Nov 4, 2022
 *      Author: Mohanned
 */

#ifndef COTS_LIB_BITMATH_H_
#define COTS_LIB_BITMATH_H_

#define setbit(var,bit) (var) |=  (1 << (bit))
#define clearbit(var,bit) (var) &= ~(1 << (bit))
#define togglebit(var, bit) (var) ^=  (1 << (bit))
#define getbit(var,bit) (((var) >> (bit)) & 0x01)


#endif /* COTS_LIB_BITMATH_H_ */
