
#ifndef COUNTER_H_
#define COUNTER_H_
#include "button.h"

static struct counter_val
{
	char unit;
	char tens;
	};
void counter_init();
void counter_update();
struct counter_val get_number();


#endif /* COUNTER_H_ */