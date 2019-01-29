

#ifndef LED_H_
#define LED_H_
#include "button.h"

typedef enum
{
	led1,
	led2
	}ledNumber;


void led_init(ledNumber led_number);
void led_write(ledNumber led_number,char val);
void led_toggle(ledNumber led_number);
void led_update();
uint8_t is_it_minute();
#endif /* LED_H_ */