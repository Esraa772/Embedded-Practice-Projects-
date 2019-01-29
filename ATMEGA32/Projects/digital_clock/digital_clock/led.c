#include "led.h"
int led_counter,led_state;
#define led_period	1000
clock_mode mod;
void led_init(ledNumber led_Number)
{
	led_counter=0;
	led_state=0;
	switch(led_Number)
	{
		case led1:
		{
			pin_write(led1_dir,led1_pin,output);
			break;
		}
		default:
			break;
	}
}

void led_write(ledNumber led_state,char val)
{
	switch (led_state)
	{
		case led1:
		{
			pin_write(led1_val,led1_pin,val);
			break;
	    }
		default:
			break;			
	}
}

void led_toggle(ledNumber led_number)
{
	switch (led_number)
	{
		case led1:
		{
			toggle_bit(led1_val,led1_pin);
		}
		default:
			break;
	}
}

void led_update()
{
	mod=get_mode();
	if (mod==stop_watch)
	{
		led_write(led1,low);
		return;
	}
	if (mod==adjust)
	{
		led_write(led1,low);
		return;
	}
	static int led_time;
	led_time+=tick;
	if (led_time !=led_period)
	{
		return;
	}
	led_time=0;
	
	led_toggle(led1);
	led_counter++;
	if(led_counter==6)
	{
		led_state=1;
		led_counter=0;
	}
}

uint8_t is_it_minute()
{
	if (led_state)
	{
		led_state=0;
		return 1;
	}
	return 0;
}