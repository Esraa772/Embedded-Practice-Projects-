
#ifndef PORT_H_
#define PORT_H_
#include "micro.h"

	#define seg1_dir		dirc
	#define seg2_dir		dirc
	
//*********************************

	#define seg2_val		valc
	#define seg1_val		valc
	
//********************************
	#define mode_adjust_button_dir			dird
	#define plus_button_dir					dird
	#define minus_or_confirm_button_dir		dird
	
	#define mode_adjust_button_port			vald
	#define plus_button_port				vald
	#define minus_or_confirm_button_port	vald
	     
	#define mode_adjust_button_val			inputd
	#define plus_button_val					inputd
	#define minus_or_confirm_button_val		inputd
//********************************
	#define led1_dir						dird
	#define led1_val						vald
	
	#define led1_pin						pin7
//********************************
	#define minus_or_confirm_button_pin		pin0
	#define plus_button_pin					pin1
	#define mode_adjust_button_pin			pin2
	#define seg1_enable_bin					pin2
	#define seg2_enable_bin					pin3

#endif /* PORT_H_ */