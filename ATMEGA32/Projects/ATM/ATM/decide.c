#include "decide.h"
#include "L_C_D.h"
#include "signUp.h"
#define decide_period	40
char phase;
void decide_init()
{
	phase=0;
	user_state=waiting_state;
}

void decide_update()
{
	static int decide_time;
	decide_time+=tick;
	if(decide_time!=decide_period)
	{
		return;
	}
	decide_time=0;
	if(user_state==sign_up_state&&get_signUp_system_state()==system_signUp_invalid)
	{
		return;
	}
	switch (keypad_get_key())
	{
		case 1:
		{
			user_state=login_state;
			lcd_clear();
			phase=1;
			break;
		}
		case 2:
		{
			user_state=sign_up_state;
			lcd_clear();
			phase=2;
			break;
		}
		default:
			break;
	}
}
enum user get_user_state()
{
	return user_state;
}
