#include "button.h"
#define button_period	20
int mode_counter=0;
#define buttons_number	3
	
#define PULLDOWN	
	
#ifdef PULLDOWN
	#define pushed	1
	#define not_pushed	0
#elif PULLUP
	#define pushed	0
	#define not_pushed	1
#endif // PULLDOWN
	
struct  
{
	char readings[2];
	button_state state;
}button_values[buttons_number];
	
void button_input(button_name butt_name,button_type but_typ)
{
	switch (butt_name)
	{
		case mode_adjust:
		{
			pin_write(mode_adjust_button_dir,mode_adjust_button_pin,input);
			switch (but_typ)
			{
				case pullup:
				{
					pin_write(mode_adjust_button_port,mode_adjust_button_pin,high);
					break;
				}
				case pulldown:
				{
					pin_write(mode_adjust_button_port,mode_adjust_button_pin,low);
					break;
				}
				default:
					break;
			}
			break;
		}
		case plus:
		{
			pin_write(plus_button_dir,plus_button_pin,input);
			switch (but_typ)
			{
				case pullup:
				{
					pin_write(plus_button_port,plus_button_pin,high);
					break;
				}
				case pulldown:
				{
					pin_write(plus_button_port,plus_button_pin,low);
					break;
				}
				
				default:
					break;
			}
			break;
		}
		case minus_or_confirm:
		{
			pin_write(minus_or_confirm_button_dir,minus_or_confirm_button_pin,input);
			switch (but_typ)
			{
				case pullup:
				{
					pin_write(minus_or_confirm_button_port,minus_or_confirm_button_pin,high);
					break;
				}
				case pulldown:
				{
					pin_write(minus_or_confirm_button_port,minus_or_confirm_button_pin,low);
					break;
				}
				default:
					break;
			}				
			break;
		}
		default:
			break;
	}
		
}

void button_init()
{
	int iter=0;
	for (iter;iter<buttons_number;iter++)
	{
		button_values[iter].readings[0]=not_pushed;
		button_values[iter].readings[1]=not_pushed;
		button_values[iter].state=not_pressed;
	}
}

char button_read(button_name but_name)
{
	char val;
	switch (but_name)
	{
		case mode_adjust:
		{
			val=get_bit(mode_adjust_button_val,mode_adjust_button_pin);
			return val;
		}
		case plus:
		{
			val=get_bit(plus_button_val,plus_button_pin);
			return val;
		}
		case minus_or_confirm:
		{
			val=get_bit(minus_or_confirm_button_val,minus_or_confirm_button_pin);
			return val;
		}
		default:
			return;
	}
}	

void button_update()
{
	static int button_time;
	button_time+=tick;
	if (button_time!=button_period)
	{
		return;
	}
	button_time=0;
	int iter=0;
	if (button_values[mode_adjust].state==pre_pressed)
	{
		mode_counter++;
		mode_counter%=3;
	}
	for (iter;iter<buttons_number;iter++)
	{
		button_values[iter].readings[0]=button_values[iter].readings[1];
		if (iter==mode_adjust)
		{
			button_values[mode_adjust].readings[1]=button_read(mode_adjust);
		}
		else if (iter==plus)
		{
			button_values[plus].readings[1]=button_read(plus);
		}
		else if (iter==minus_or_confirm)
		{
			button_values[minus_or_confirm].readings[1]=button_read(minus_or_confirm);
		}
		switch (button_values[iter].state)
		{
			case not_pressed:
			{
				if (button_values[iter].readings[0]==pushed && button_values[iter].readings[1]==pushed)
				{
					button_values[iter].state=pre_pressed;
				}
				break;
			}
			case pre_pressed:
			{
				if(button_values[iter].readings[0]==pushed && button_values[iter].readings[1]==pushed)
				{
					button_values[iter].state=pressed;
				}
				break;
			}
			case pressed:
			{
				if (button_values[iter].readings[0]==not_pushed && button_values[iter].readings[1]==not_pushed)
				{
					button_values[iter].state=post_pressed;
				}
				break;
			}
			case post_pressed:
			{
				if (button_values[iter].readings[0]==not_pushed && button_values[iter].readings[1]==not_pushed)
				{
					button_values[iter].state=not_pressed;
				}
				break;
			}
			default:
				break;
		}
	}
}

button_state get_button_state(button_name butt_name)
{
	
	switch(butt_name)
	{
		case mode_adjust:
			return button_values[mode_adjust].state;
		case plus:
			return button_values[plus].state;
		case minus_or_confirm:
			return button_values[minus_or_confirm].state;
		default:
			return;
	}
}

clock_mode get_mode()
{
	
	switch (mode_counter)
	{
		case watch:
			return watch;
		case adjust:
			return adjust;
		case stop_watch:
			return stop_watch;
		default:
			return;
	}
}		