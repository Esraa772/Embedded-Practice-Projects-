#include "time.h"
				/****variables********/ 
				
float timer_0_prescaler,timer_1_prescaler,timer_2_prescaler;
uint8_t timer_0_mode,timer_1_mode,timer_2_mode;

				/***timer1 initialization****/
				
void timer1_init(timer_mode mode,prescaler_selectors prescaler)
{
	sei();
	switch (mode)
	{
		case normal:
		{
			pin_write(timer_counter_interrupt_mask_register,timer1_overflow_interrupt_enable_bit,high);
			pin_write(timer1_counter_control_register_A,timer1_mode_selectors_bit10,low);
			pin_write(timer1_counter_control_register_A,timer1_mode_selectors_bit11,low);
			pin_write(timer1_counter_control_register_B,timer1_mode_selectors_bit12,low);
			pin_write(timer1_counter_control_register_B,timer1_mode_selectors_bit13,low);
			timer_1_mode=normal;
			break;
		}
		case clear_timer_on_compare_match:
		{
			pin_write(timer1_counter_control_register_A,timer1_mode_selectors_bit10,low);
			pin_write(timer1_counter_control_register_A,timer1_mode_selectors_bit11,low);
			pin_write(timer1_counter_control_register_B,timer1_mode_selectors_bit12,high);
			pin_write(timer1_counter_control_register_B,timer1_mode_selectors_bit13,low);
			timer_1_mode=clear_timer_on_compare_match;
			break;
		}
		default:
			break;
	}
	switch (prescaler)
	{
		case no_clock_source:
		{
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit10,low);
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit11,low);
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit12,low);
			break;
		}
		case no_prescaling:
		{
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit10,high);
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit11,low);
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit12,low);
			timer_1_prescaler=1;
			break;
		}
		case factor_8:
		{
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit10,low);
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit11,high);
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit12,low);
			timer_1_prescaler=8;
			break;
		}
		case factor_64:
		{
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit10,high);
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit11,high);
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit12,low);
			timer_1_prescaler=64;
			break;
		}
		case factor_256:
		{
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit10,low);
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit11,low);
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit12,high);
			timer_1_prescaler=256;
			break;
		}
		case factor_1024:
		{
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit10,high);
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit11,low);
			pin_write(timer1_counter_control_register_B,timer1_prescaler_selector_bit12,high);
			timer_1_prescaler=1024;
			break;
		}
		default:
			break;
	}
}

    //*******update timer 1******
	
void timer1_update()
{
	float frequency=F_CPU/1000000;  // because we write it as 8000000
	float time_tick=(timer_1_prescaler/frequency);
	float pulses=((time_delay_in_milliseconds*0.001)/(time_tick*pow(10,-6)))-1;
	switch(timer_1_mode)
	{
		case normal:
		{
			timer1_counter_register=65536-pulses;
			break;
		}
		case clear_timer_on_compare_match:
		{
			timer1_output_compare_register_A=pulses;
			timer1_counter_register=0;
			break;
		}
		default:
			break;
	}
}

//********timer0 initialization*******

void timer0_init(timer_mode mode,prescaler_selectors prescaler)
{
	sei();
	switch (mode)
	{
		case normal:
		{
			pin_write(timer_counter_interrupt_mask_register,timer0_overflow_interrupt_enable_bit,high);
			pin_write(timer_counter_control_register0,timer0_mode_selector_bit00,low);
			pin_write(timer_counter_control_register0,timer0_mode_selector_bit01,low);
			timer_0_mode=normal;
			break;
		}
		case clear_timer_on_compare_match:
		{
			pin_write(timer_counter_interrupt_mask_register,timer0_output_compare_interrupt_enable_bit,high);
			pin_write(timer_counter_control_register0,timer0_mode_selector_bit00,low);
			pin_write(timer_counter_control_register0,timer0_mode_selector_bit01,high);
			timer_0_mode=clear_timer_on_compare_match;
			break;
		}
		case phase_PWM:
		{
			pin_write(timer_counter_control_register0,timer0_mode_selector_bit00,high);
			pin_write(timer_counter_control_register0,timer0_mode_selector_bit01,low);
			timer_0_mode=phase_PWM;
			break;
		}
		case fast_PWM:
		{
			pin_write(timer_counter_control_register0,timer0_mode_selector_bit00,high);
			pin_write(timer_counter_control_register0,timer0_mode_selector_bit01,high);
			timer_0_mode=fast_PWM;
			break;
		}
		default:
			break;
	}
	
	switch (prescaler)
	{
		case no_clock_source:
		{
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs00,low);
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs01,low);
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs02,low);
			break;
		}
		case no_prescaling:
		{
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs00,high);
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs01,low);
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs02,low);
			timer_0_prescaler=1;
			break;
		}
		case factor_8:
		{
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs00,low);
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs01,high);
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs02,low);
			timer_0_prescaler=8;
			break;
		}
		case factor_64:
		{
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs00,high);
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs01,high);
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs02,low);
			timer_0_prescaler=64;
			break;
		}
		case factor_256:
		{
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs00,low);
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs01,low);
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs02,high);
			timer_0_prescaler=256;
			break;
		}
		case factor_1024:
		{
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs00,high);
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs01,low);
			pin_write(timer_counter_control_register0,timer0_prescaler_selector_bitcs02,high);
			timer_0_prescaler=1024;
			break;
		}
		default:
			break;
	}
}

//******timer 0 update*******

void timer0_update()
{
	float frequency=F_CPU/1000000;  // because we write it as 8000000
	float time_tick=(timer_0_prescaler/frequency);
	float pulses=((time_delay_in_milliseconds*0.001)/(time_tick*pow(10,-6)))-1;
	switch(timer_0_mode)
	{
		case normal:
		{
			timer0_counter_register=255-pulses;
			break;
		}
		case clear_timer_on_compare_match:
		{
			timer0_output_compare_register=pulses;
			timer0_counter_register=0;
			break;
		}
		default:
			break;
	}
	
}

//******timer 2 initialization*********

void timer2_init(timer_mode mode,prescaler_selectors prescaler,timer2_clock_source_selector clc_source)
{
	sei();
	switch (clc_source)
	{
			case internal:
			{
				pin_write(Asynchronous_status_register,realtime_clock_selector_bit,low);
				break;
			}
			case real_clock:
			{
				pin_write(Asynchronous_status_register,realtime_clock_selector_bit,high);
				break;
			}
			default:
				break;
	}
	
	switch(mode)
	{
		case normal:
		{
			pin_write(timer_counter_interrupt_mask_register,timer2_overflow_interrupt_enable_bit,high);
			pin_write(timer_counter_control_register2,timer2_mode_selector_bit20,low);
			pin_write(timer_counter_control_register2,timer2_mode_selector_bit21,low);
			timer_2_mode=normal;
			break;
		}
		case clear_timer_on_compare_match:
		{
			pin_write(timer_counter_interrupt_mask_register,timer2_output_compare_interrupt_enable_bit,high);
			pin_write(timer_counter_control_register2,timer2_mode_selector_bit20,low);
			pin_write(timer_counter_control_register2,timer2_mode_selector_bit21,high);
			timer_2_mode=clear_timer_on_compare_match;
			break;
		}
		case phase_PWM:
		{
			pin_write(timer_counter_control_register2,timer2_mode_selector_bit20,high);
			pin_write(timer_counter_control_register2,timer2_mode_selector_bit21,low);
			timer_2_mode=phase_PWM;
			break;
		}
		case fast_PWM:
		{
			pin_write(timer_counter_control_register2,timer2_mode_selector_bit20,high);
			pin_write(timer_counter_control_register2,timer2_mode_selector_bit21,high);
			timer_2_mode=fast_PWM;
			break;
		}
		default:
			break;
	}
	
	switch (prescaler)
	{
		case no_clock_source:
		{
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs20,low);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs21,low);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs22,low);
			break;
		}
		case no_prescaling:
		{
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs20,high);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs21,low);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs22,low);
			timer_2_prescaler=1;
			break;
		}
		case factor_8:
		{
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs20,low);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs21,high);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs22,low);
			timer_2_prescaler=8;
			break;
		}
		case factor_32:
		{
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs20,high);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs21,high);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs22,low);
			timer_2_prescaler=32;
			break;
		}
		case factor_64:
		{
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs20,low);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs21,low);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs22,high);
			timer_2_prescaler=64;
			break;
		}
		case factor_128:
		{
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs20,high);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs21,low);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs22,high);
			timer_2_prescaler=128;
			break;
		}
		case factor_256:
		{
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs20,low);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs21,high);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs22,high);
			timer_2_prescaler=256;
			break;
		}
		case factor_1024:
		{
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs20,high);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs21,high);
			pin_write(timer_counter_control_register2,timer2_prescaler_selector_bitcs22,high);
			timer_2_prescaler=1024;
			break;
		}
		default:
			break;
	}
}

//********timer 2 update******

void timer2_update()
{
	float frequency=F_CPU/1000000;  // because we write it as 8000000
	float time_tick=(timer_2_prescaler/frequency);
	float pulses=((time_delay_in_milliseconds*0.001)/(time_tick*pow(10,-6)))-1;
	switch(timer_2_mode)
	{
		case normal:
		{
			timer2_counter_register=255-pulses;
			break;
		}
		case clear_timer_on_compare_match:
		{
			timer2_output_compare_register=pulses;
			timer2_counter_register=0;
			break;
		}
		default:
			break;
	}
}
