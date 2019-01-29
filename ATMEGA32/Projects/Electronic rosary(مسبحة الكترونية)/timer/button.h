


#ifndef BUTTON_H_
#define BUTTON_H_
#include "time.h"

typedef enum{
	adjust,
	reset
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
	
void button_update();

button_state get_button_state(button_name butt_name);

void button_init(button_name butt_name,button_type but_typ);

char button_read(button_name butt_name);

#endif /* BUTTON_H_ */