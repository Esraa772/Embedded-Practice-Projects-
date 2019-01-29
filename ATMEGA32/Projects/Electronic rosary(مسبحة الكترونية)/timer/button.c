#include "button.h"
int button_time=tick;
#define buttons_number	2
	
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
	
void button_init(button_name butt_name,button_type but_typ)
{
	switch (butt_name)
	{
		case adjust:
		{
			pin_write(adjust_button_dir,adjust_button_pin,input);
			switch (but_typ)
			{
				case pullup:
				{
					pin_write(adjust_button_port,adjust_button_pin,high);
					break;
				}
				case pulldown:
				{
					pin_write(adjust_button_port,adjust_button_pin,low);
					break;
				}
				default:
				break;
			}
			break;
		}
		case reset:
		{
			pin_write(reset_button_dir,reset_button_pin,input);
			switch (but_typ)
			{
				case pullup:
				{
					pin_write(reset_button_port,reset_button_pin,high);
					break;
				}
				case pulldown:
				{
					pin_write(reset_button_port,reset_button_pin,low);
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
		case adjust:
		{
			val=get_bit(adjust_button_val,adjust_button_pin);
			return val;
		}
		case reset:
		{
			val=get_bit(reset_button_val,reset_button_pin);
			return val;
		}
		default:
		break;
	}
}	

void button_update()
{
	if (button_time!=20)
	{
		button_time+=tick;
		return;
	}
	int iter=0;
	for (iter;iter<buttons_number;iter++)
	{
		button_values[iter].readings[0]=button_values[iter].readings[1];
		if (iter==adjust)
		{
			button_values[adjust].readings[1]=button_read(adjust);
		}
		else if (iter==reset)
		{
			button_values[reset].readings[1]=button_read(reset);
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
	button_time=tick;
}

button_state get_button_state(button_name butt_name)
{
	switch(butt_name)
	{
		case adjust:
			return button_values[adjust].state;
		case reset:
			return button_values[reset].state;
		default:
			break;
	}
}