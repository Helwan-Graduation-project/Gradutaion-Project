/*
 * Project_learn.c
 *
 * Created: 2/11/2018 9:37:49 PM
 *  Author: Ebraam
 */ 


#include "lcd/lcd.h"
#include "ultrasonic/ult.h"

int main(void)
{
	static uint32_t dis = 0;
	lcd_init();
	
	Ultrasonic_init();
	lcd_write_txt("distance= ");
	dis = Ultrasonic_Read();
	
	
	
	//lcd_write_cmd(clear);
    while(1)
    {
		
		 dis = Ultrasonic_Read();
		lcd_goto_X(10);
		lcd_write_number(dis);
		lcd_write_txt("cm");
		 _delay_ms(500);
		 
    }
}