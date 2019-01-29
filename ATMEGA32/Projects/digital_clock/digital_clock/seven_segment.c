#include "seven_segment.h"
#define reg_output	0x0f
#define segment_period	20

void segment_init(segment_number seg_num , segment_position seg_pos)
{
	pin_write(seg1_dir,seg1_enable_bin,high);
	pin_write(seg2_dir,seg2_enable_bin,high);
	pin_write(seg1_val,seg1_enable_bin,high);
	pin_write(seg2_val,seg2_enable_bin,high);
	switch (seg_pos)
	{
		case lower:
		{
			switch (seg_num)
			{
				case segment1:
				{
					lower_nibble_write(seg1_dir,reg_output);
					break;
				}
				case segment2:
				{
					lower_nibble_write(seg2_dir,reg_output);
					break;
				}
				default:
				break;
				
			}
			break;
		}
		case higher:
		{
			switch (seg_num)
			{
				case segment1:
				{
					higher_nibble_write(seg1_dir,reg_output);
					break;
				}
				case segment2:
				{
					higher_nibble_write(seg2_dir,reg_output);
					break;
				}
				default:
				break;
			}
			break;
		}
		default:
		break;
	}
}
void segment_write(segment_number seg_num, segment_position seg_pos,char val)
{
	switch (seg_pos)
	{
		case lower:
		{
			switch (seg_num)
			{
				case segment1:
				{
					pin_write(seg1_val,seg1_enable_bin,high);
					pin_write(seg2_val,seg2_enable_bin,low);
					lower_nibble_write(seg1_val,val);
					break;
				}
				case segment2:
				{
					pin_write(seg1_val,seg1_enable_bin,low);
					pin_write(seg2_val,seg2_enable_bin,high);
					lower_nibble_write(seg2_val,val);
					break;
				}
				default:
				break;
			}
			break;
		}
		case higher:
		{
			switch (seg_num)
			{
				case segment1:
				{
					
					pin_write(seg1_val,seg1_enable_bin,high);
					pin_write(seg2_val,seg2_enable_bin,low);
					higher_nibble_write(seg1_val,val);
					break;
				}
				case segment2:
				{
					pin_write(seg1_val,seg1_enable_bin,low);
					pin_write(seg2_val,seg2_enable_bin,high);
					higher_nibble_write(seg2_val,val);
					break;
				}
				default:
				break;
			}
			break;
		}
		default:
		break;
	}
}
void segment_update()
{
	static int SSD_period;
	SSD_period+=tick;
	struct clock_counter counter=get_counter();
	
	if(SSD_period==segment_period/2)
	{
		segment_write(segment1,higher,counter.units);
	}
	else if(SSD_period==segment_period )
	{
		segment_write(segment1,higher,counter.units);
		segment_write(segment2,higher,counter.tens);
		SSD_period=0;
	}
}