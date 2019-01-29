#include "seven_segment.h"
ISR(TIMER1_OVF_vect)
{
	button_update();
	led_update();
	clock_update();
	segment_update();
	timer1_update();
}
int main(void)
{
	
	/***** button initialization*****/
		button_input(mode_adjust,pulldown);
		button_input(plus,pulldown);
		button_input(minus_or_confirm,pulldown);
		button_init();
		
	/*****segment initialization*****/
		segment_init(segment1,higher);
		segment_init(segment2,higher);
		
	/****timer initialization********/
		timer1_init(normal,factor_1024);
		timer1_update();
		
	/*******clocl initialization****/
		clock_init();
		
	/******led initialization******/
		led_init(led1);
    while(1)
    {
        
    }
}