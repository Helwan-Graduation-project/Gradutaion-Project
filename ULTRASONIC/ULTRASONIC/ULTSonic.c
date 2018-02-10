/*
 * ULTSonic.c
 *
 * Created: 2/10/2018 3:41:57 PM
 *  Author: Ebraam
 */ 

#include "ULTSonic.h"

uint16_t getPulseWidth()
 {
      uint32_t i,result;

	      //Wait for the rising edge
	       for(i=0;i<600000;i++)
		    {
	          if(!(US_PIN & (1<<US_POS))) 
			  continue; 
			  else break;
	        }
	
	       if(i==600000)
	         return 0xffff; //Indicates time out
	
	      //High Edge Found
	
	      //Setup Timer1
	      TCCR1A=0X00;
	     TCCR1B=(1<<CS11); //Prescaler = Fcpu/8
	      TCNT1=0x00;       //Init counter

	       //Now wait for the falling edge
	       for(i=0;i<600000;i++)
	   {
		        if(US_PIN & (1<<US_POS))
		    {
			            if(TCNT1 > 60000) break; else continue;
		       }
		        else
		           break;
	     }

	     if(i == 600000)
	        return 0xffff; //Indicates time out

	    //Falling edge found
	
	     result=TCNT1;

	      //Stop Timer
	      TCCR1B = 0x00;

	      if(result > 60000)
	         return 0xfffe; //No obstacle
	 else
  return (result>>1);
 }

void Wait()
{
	      uint8_t i;
	     for(i=0;i<10;i++)
	         _delay_loop_2(0);
  }