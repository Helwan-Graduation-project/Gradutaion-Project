/*
 * ult.h
 *
 * Created: 2/11/2018 9:39:45 PM
 *  Author: Ebraam
 */ 


#ifndef ULT_H_
#define ULT_H_


#include "std_macros.h"
/*
init timer 0
turn overflow on
*/
static void Timer0_init(void);

/*
Start Count
prescaler = 256
*/
static void Timer0_Start(void);

/*
Turn off timer
*/
static void Timer0_Stop(void);

/*
This function return TCNT0 value
*/
static uint32_t Timer0_read(void);

/*
init ultrasonic
*/
void Ultrasonic_init();

uint32_t Ultrasonic_Read();



#endif /* ULT_H_ */