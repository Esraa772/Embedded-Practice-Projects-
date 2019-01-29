

#include "login.h"
#include "E2PRM.h"
#include "L_C_D.h"

ISR(TIMER1_OVF_vect)
{
	keypad_update();
	decide_update();
	login_update();
	signUp_update();
	lcd_update();
	timer1_update();
}

int main(void)
{
	
	keypad_init();
	lcd_init();
	//lcd_send_command(display_off_cursor_off);
	
	decide_init();
	//login_init();
	signUp_init();
	//EEPROM_init();
	timer1_init(normal,factor_1024);
	timer1_update();
	//timer1_init();
    while(1)
    {
		MCUCR|=(1<<7);
		//lcd_set_cursor(first_row,first_column);
       // lcd_send_data('a');
    }
}