
#ifndef PORT_H_
#define PORT_H_
#include "micro.h"

	#define seg1_dir		dirc
	#define seg2_dir		dirc
	
//*********************************

	#define seg2_val		valc
	#define seg1_val		valc
	
//********************************
	#define adjust_button_dir	dird
	#define reset_button_dir	dird
	
	#define adjust_button_port	vald
	#define reset_button_port	vald
	
	#define adjust_button_val	inputd
	#define reset_button_val	inputd
//********************************

//********************************
	#define adjust_button_pin		pin2
	#define reset_button_pin		pin1
	#define seg1_enable_bin			pin2
	#define seg2_enable_bin			pin3

#endif /* PORT_H_ */