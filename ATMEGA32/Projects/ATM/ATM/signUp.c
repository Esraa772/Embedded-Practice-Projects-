#include "signUp.h"
#define signUp_period	40
void signUp_init(){
	client_signup_data.inputs_state=data_not_complete;
	signUp_system_state=system_signUp_invalid;
}

void signUp_update(){
	int current_loc=fifth_column;
	static int loc=0;
	static int signup_time;
	signup_time+=tick;
	if (signup_time!=signUp_period)
	{
		return;
	}
	signup_time=0;
	switch (get_user_state())
	{
		case sign_up_state:
		{
			static char i=0; //counter to count number of characters in ID and pass
			if (client_signup_data.inputs_state==data_not_complete)
			{
				char key_value=keypad_get_key();
				
				if (key_value!=no_pressed)
				{
					//write the key value in lcd 
					if (loc<3)
					{
						lcd_set_cursor(first_row,current_loc+loc);
						loc++;
					}
					else
					{
						lcd_set_cursor(second_row,current_loc+(loc));
						loc++;
					}
					lcd_send_data(key_value+48);
					if (loc>=5)//if the ID and pass completed, start over
					{
						loc=0;
					}
					//finish
					
					
					// start to check if data complete or not
					if (i<3)
					{
						client_signup_data.ID[i++]=key_value;
					}
					else if(i==3)
					{
						client_signup_data.ID[3]='\0';
						i++;
					}
					else
					{
						client_signup_data.pass[i++%4]=key_value;
						if (i==7)
						{
							client_signup_data.pass[3]='\0';
						}
					}
				}
				if (i==7)
				{
					client_signup_data.inputs_state=data_completed;
					i=0;
				}
			}
			//data completed
			else if (client_signup_data.inputs_state==data_completed)
			{
					signUp_system_state=system_signUp_valid;
				
			}
			break;
		}
	}
}
struct sign_up_data get_new_client()
{
	return client_signup_data;
}

enum signUp_system get_signUp_system_state()
{
	return signUp_system_state;
	};