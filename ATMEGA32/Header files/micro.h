/*
 * micro.h
 *
 * Created: 9/30/2018 11:13:21 PM
 *  Author: Esraa Abdelnaby
 */ 


#ifndef MICRO_H_
#define MICRO_H_
#include "config.h"
#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7
//----------------------------------------
#define dira DDRA
#define dirb DDRB
#define dirc DDRC
#define dird DDRD

//----------------------------------------
#define vala PORTA
#define valb PORTB
#define valc PORTC
#define vald PORTD
//-----------------------------------------
#define input 0
#define output 1
#define high 1
#define low 0

#define pin_write(reg,index,val) reg=(reg&(~(1<<index)))|(val<<index) 
#define higher_nibble_val(reg,val) reg=(reg&0x0f)|(val<<4)
#define lower_nibble_val(reg,val) reg=(reg&0xf0)|(val)

#endif /* MICRO_H_ */
