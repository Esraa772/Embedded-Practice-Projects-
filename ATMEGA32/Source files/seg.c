#include "seg.h"

void seg_output()
{
	higher_nibble_val(seg1_dir,0x0f);
	lower_nibble_val(seg2_dir,0x0f);
	
	higher_nibble_val(seg4_dir,0x0f);
	lower_nibble_val(seg3_dir,0x0f);
	
	higher_nibble_val(seg5_dir,0x0f);
	lower_nibble_val(seg6_dir,0x0f);
}

void seg_write(nseg seg_num,char val)
{
	switch(seg_num)
	{
		case seg1:
		{
			higher_nibble_val(seg1_val,val);
			break;
		}
		case seg2:
		{
			lower_nibble_val(seg2_val,val);
			break;
		}
		case seg3:
		{
			lower_nibble_val(seg3_val,val);
			break;
		}
		case seg4:
		{
			higher_nibble_val(seg4_val,val);
			break;
		}
		case seg5:
		{
			lower_nibble_val(seg5_val,val);
			break;
		}
		case seg6:
		{
			higher_nibble_val(seg6_val,val);
			break;
		}
	}
}
