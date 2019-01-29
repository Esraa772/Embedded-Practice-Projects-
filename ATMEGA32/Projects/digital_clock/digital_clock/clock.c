#include "clock.h" 
#define clock_period	20
int stop_watch_timer=0;
int flag;
int main_counter,watch_counter,stop_watch_counter;

void clock_init()
{
	main_counter=watch_counter=stop_watch_counter=0;
}

void clock_update()
{
	static int clock_time;
	clock_time+=tick;
	if (clock_time !=clock_period)
	{
		return;
	}
	clock_time=0;
	switch (get_mode())
	{
		case watch:
		{
			if (is_it_minute())  //from led blinking
			{
				watch_counter++;
			}
			main_counter=watch_counter;
			break;
		}
		case adjust:
		{
			if (get_button_state(plus)==pre_pressed)
			{
				watch_counter++;
			}
			if (get_button_state(minus_or_confirm)==pre_pressed)
			{
				watch_counter--;
			}
			if (watch_counter<0)
				main_counter=0;
			else
				main_counter=watch_counter;
			break;
		}
		case stop_watch:
		{
			main_counter=stop_watch_counter;
			if (get_button_state(plus)==pre_pressed)
			{
				stop_watch_counter++;
				flag=0;
			}
			if (get_button_state(minus_or_confirm)==pre_pressed)
			{
				flag=1;
			}
			if (flag)
			{
				if (stop_watch_timer==6000)
				{
					stop_watch_counter--;
					if(stop_watch_counter<0)
					main_counter=0;
					else
					main_counter=stop_watch_counter;
					stop_watch_timer=0;
				}
				else
				{
					stop_watch_timer+=20;
				}
			}
			break;
		}
		default:
			break;
	}
}

struct clock_counter get_counter()
{
	main_counter%=59;
	struct clock_counter cnt;
	cnt.units=main_counter%10;
	cnt.tens=main_counter/10;
	return cnt;
}
