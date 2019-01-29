/*
 * flash.c
 *
 * Created: 9/30/2018 10:59:18 PM
 *  Author: Esraa Abdelnaby
 */ 
#include "flash.h"
void blink()
{
	led_write(high);
	_delay_ms(1000);
	led_write(low);
	_delay_ms(1000);
}