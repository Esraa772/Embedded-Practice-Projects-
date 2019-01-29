
#include "login.h"
#define login_period	40

void login_init()
{
	
	clients_data.inputs_state=data_not_done;
	system_login=system_login_not_valid;
}

void login_update()
{
	int current_loc=fifth_column;
	static char loc=0;
	static int login_time;
	login_time+=tick;
	
	if(login_time!=login_period)
	{
		return;
	}
	
	login_time =0;
	
	char i=0,j=0,x,flag;
    static char *ptr;
    ptr=getlist();
	switch(get_user_state())
	{
		case login_state:
		{   
			x=keypad_get_key();
			
			if (x!=no_pressed)
			{
				//write the key value in lcd
				if (loc<3)
				{
					lcd_set_cursor(0,current_loc+loc);
					loc++;
				}
				else
				{
					lcd_set_cursor(1,current_loc+(loc-1));
				}
				lcd_send_data(x);
				if (loc>=5)//if the ID and pass completed, start over
				{
					loc=0;
				}
				//finish
				if(i>=0&&i<=2)
				{
					clients_data.ID[i++]=x;
					clients_data.ID[3]='\0';
					i++;
				}
				
				if (j>=0&&j<=2)
				{
					clients_data.pass[j++]=x;
					clients_data.pass[3]='\0';
				}
				if (i==3 && j==3)
				{
					clients_data.inputs_state=data_done;
					i=j=0;
				}
			}
			if (clients_data.inputs_state==data_done)
			{
				for (i=0;i<4;i++)
				{
					if (ptr[i]==clients_data.ID[i])
					{
						flag++;
					}
					else 
					{
						flag=0;
					}
				}
				
				for (i=0;i<4;i++)
				{
					if (ptr[i]==clients_data.pass[i])
					{
						flag++;
					}
					else 
					{
						flag=0;
					}
				}
				if (flag==8)
				{
					system_login =system_login_valid;
				}
			}
			
			
			break;	
		}
	}
}	
enum system get_system(){
	return system_login;
	};