

#ifndef TIME_H_
#define TIME_H_
#include "port.h"
#define tick 10
#define time_delay_in_milliseconds	10
#include <math.h>


typedef enum
{
	normal=1,
	clear_timer_on_compare_match,
	phase_PWM,
	fast_PWM
	}timer_mode;
	
typedef enum
{
	no_clock_source=1,
	no_prescaling,
	factor_8,
	factor_64,
	factor_256,
	factor_1024,
	factor_32,
	factor_128
	}prescaler_selectors;
	
typedef enum
{
	falling_edge=1,
	rising_edge
	}edge_detector;
typedef enum
{
	internal=1,
	real_clock
	}timer2_clock_source_selector;
void timer0_init(timer_mode mode,prescaler_selectors prescaler);
void timer1_init(timer_mode mode,prescaler_selectors prescaler);
void timer2_init(timer_mode mode,prescaler_selectors prescaler,timer2_clock_source_selector clc_source);
void timer1_update();
void timer0_update();
void timer2_update();
//void time_init(timer_number tim,timer_mode mode,prescaler_selectors prescaler,float time_delay_in_miliseconds,timer2_clock_source_selector source);
#endif /* TIME_H_ */