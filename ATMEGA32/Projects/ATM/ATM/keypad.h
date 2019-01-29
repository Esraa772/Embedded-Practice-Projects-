


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "time.h"
#include "port.h"
void keypad_init();
void keypad_update();
char keypad_get_key();
char search(char val );
#define no_pressed 10
typedef enum {
	high_val=1,
	falling,
	low_val,
	rising,
	}pin_states;



#endif /* KEYPAD_H_ */