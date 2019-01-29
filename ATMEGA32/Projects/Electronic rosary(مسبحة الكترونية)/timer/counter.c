#include "counter.h"
int counter;

#define period_counter 20
void counter_init()
{
	counter=0;
}
void counter_update()
{
	static int counter_time;
	counter_time+=tick;
	if (counter_time!=period_counter)
	{
		return;
	}
	counter_time=0;
	
	if (get_button_state(adjust)==pre_pressed)
	{
		counter++;
		counter%=99;
	}
	if (get_button_state(reset)==pre_pressed)
	{
		counter=0;
	}
	
}
struct counter_val get_number()
{
	struct counter_val number;
	number.unit=counter%10;
	number.tens=counter/10;
	return number;
}