/*
 * counter.c
 *
 * Created: 10/1/2018 10:15:00 PM
 *  Author: Esraa Abdelnaby
 */ 
#include "counter.h"
int cnt;
void count0_9()
{
	for(cnt=0;cnt<9;cnt++)
	{
		seg_write(lower,cnt);
		_delay_ms(1000);
	}	
}
void count9_0()
{
	for(cnt=9;cnt>0;cnt--)
	{
		seg_write(lower,cnt);
		_delay_ms(1000);
	}
}