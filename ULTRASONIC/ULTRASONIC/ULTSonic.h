/*
 * ULTSonic.h
 *
 * Created: 2/10/2018 3:42:12 PM
 *  Author: Ebraam
 *Configuration Area.
    UltraSonic (US) sensor connection in this example it is connected to PORTA bit 0
 */ 



#ifndef ULTSONIC_H_
#define ULTSONIC_H_


#include "std_macros.h"

#define  US_PORT PORTA
#define  US_PIN   PINA
#define  US_DDR    DDRA
#define  US_POS PORTA0     //PORTA0 is position of US

// This function measusers the width of high pulse in micro second.
#define  US_ERROR 0xffff
#define  US_NO_OBSTACLE 0xff

uint16_t getPulseWidth();


#endif /* ULTSONIC_H_ */