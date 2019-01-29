

#ifndef SEVEN_SEGMENT_H_
#define SEVEN_SEGMENT_H_

#include "port.h"
typedef enum
{
	seg1, seg2,
	seg3, seg4,
	seg5, seg6,
}nseg;

void seg_output();
void seg_write(nseg seg_num,char val);



#endif /* SEVEN_SEGMENT_H_ */
