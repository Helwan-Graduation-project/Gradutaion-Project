/*
 * ULTRASONIC.c
 *
 * Created: 2/10/2018 2:27:31 PM
 *  Author: Ebraam
 */ 


#include "LCD.h"
#include "ULTSonic.h"

int main(void)
{
	uint16_t r;
	lcd_init();
	lcd_write_txt("Distance: ");
	
	
	
    while(1)
    {
         //Set Ultra Sonic Port as out
         US_DDR|=(1<<US_POS);
        _delay_us(10);
    //Give the US pin a 15us High Pulse
             US_PORT|=(1<<US_POS);   //High
    
             _delay_us(15);
    
             US_PORT&=(~(1<<US_POS));//Low
   
            _delay_us(20);
   
             //Now make the pin input
            US_DDR&=(~(1<<US_POS));
    
             //Measure the width of pulse
             r=getPulseWidth();
			 //Handle Errors
			          if(r==US_ERROR)
			         {
				            lcd_write_txt("Error !");
			         }
			         else  if(r==US_NO_OBSTACLE)
			        {
		           lcd_write_txt("Clear !");
			        }
			        else
			       {
				 
				             static int d;
							
				            d=(r/58.3); //Convert to cm
							
							lcd_write_cmd(clear);
							lcd_write_txt("Distance: ");
							
							lcd_write_number(d);
							lcd_write_txt(" cm");
			
					 Wait();
				   }					 
	
	}
}