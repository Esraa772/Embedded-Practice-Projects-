#include "service.h"
void start()
{
	for (int cnt1=0;cnt1<2;cnt1++)
	{
		seg_write(seg1,cnt1);
		for (int cnt2=0;cnt2<10;cnt2++)
		{
			if (cnt1 == 1 && cnt2 == 3)
			{
				break;
			}
			seg_write(seg2,cnt2);
			for (int cnt3=0;cnt3<6;cnt3++)
			{
				seg_write(seg4,cnt3);
				for (int cnt4=0;cnt4 <10;cnt4++)
				{
					seg_write(seg3,cnt4);
					for (int cnt5=0;cnt5<6;cnt5++)
					{
						seg_write(seg5,cnt5);
						for (int cnt6=0;cnt6<10;cnt6++)
						{
							seg_write(seg6,cnt6);
							_delay_ms(150);
						}
					}
				}
			}
		}
	}
}