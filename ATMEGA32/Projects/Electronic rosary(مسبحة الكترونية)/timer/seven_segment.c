#include "seven_segment.h"
#define reg_output	0x0f
#define segment_time	20

void segment_output(segment_number seg_num , segment_position seg_pos)
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

void seg_update()
{
	static int SSD_period;
	SSD_period+=tick;
	struct counter_val counter=get_number();
	
	if(SSD_period==segment_time/2)
	{
		segment_write(segment1,higher,counter.unit);
	}
	else if(SSD_period==segment_time )
	{
		segment_write(segment1,higher,counter.unit);
		segment_write(segment2,higher,counter.tens);
		SSD_period=0;
	}
}