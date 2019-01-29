
#ifndef DECIDE_H_
#define DECIDE_H_
#include "keypad.h"
extern char phase;
static enum user{
	
		waiting_state,
		login_state,
		sign_up_state
	
	}user_state;

void decide_init();
void decide_update();
enum user get_user_state();


#endif /* DECIDE_H_ */