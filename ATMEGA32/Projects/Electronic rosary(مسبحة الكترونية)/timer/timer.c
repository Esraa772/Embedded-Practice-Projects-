#include "seven_segment.h"
ISR(TIMER1_OVF_vect)
{
	button_update();
	counter_update();
	seg_update();
	timer1_update();
}
int main(void)
{
	counter_init();
	button_init(adjust,pulldown);
	button_init(reset,pulldown);
	segment_output(segment1,higher);
	timer1_init(normal,factor_1024);
	timer1_update();
    while(1)
    {
        
    }
}