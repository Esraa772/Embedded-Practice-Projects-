/*
 * led.c
 *
 * Created: 9/30/2018 10:58:30 PM
 *  Author: Esraa Abdelnaby
 */ 
#include "led.h"
void led_output()
{
	pin_write(led_dir,led_pin,output);
}
void led_write(char val)
{
	pin_write(led_val,led_pin,val);
}
