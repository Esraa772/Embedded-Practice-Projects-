

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_
#include "clock.h"
typedef enum
{
	lower,
	higher
	}segment_position;

typedef enum
{
	segment1,
	segment2
	}segment_number;

void segment_init(segment_number seg_num , segment_position seg_pos);
void segment_write(segment_number seg_num, segment_position seg_pos,char val);
void segment_update();

#endif /* SEVEN_SEGMENT_H_ */