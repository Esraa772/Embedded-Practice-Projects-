


#ifndef BUTTON_H_
#define BUTTON_H_
#include "time.h"

typedef enum{
	mode_adjust,
	plus,
	minus_or_confirm
	}button_name;
	
typedef enum
{
	pullup,
	pulldown
	}button_type;
	
typedef enum
{
	not_pressed,
	pre_pressed,
	pressed,
	post_pressed
	}button_state;
	
typedef enum
{
	watch,
	adjust,
	stop_watch
	}clock_mode;



void button_input(button_name butt_name,button_type but_typ);
button_state get_button_state(button_name butt_name);
char button_read(button_name butt_name);
clock_mode get_mode();
void button_update();
void button_init();

#endif /* BUTTON_H_ */