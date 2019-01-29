
#ifndef CLOCK_H_
#define CLOCK_H_
#include "led.h"

static struct clock_counter{
	char units;
	char tens;
};

void clock_init();
struct clock_counter get_counter();
void clock_update();



#endif /* CLOCK_H_ */