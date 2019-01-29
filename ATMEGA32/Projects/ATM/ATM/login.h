

#ifndef LOGIN_H_
#define LOGIN_H_
#include "decide.h"
#include "L_C_D.h"
static enum system
	{
		system_login_valid,
		system_login_not_valid
		
	}system_login;
	
typedef enum 
	{
		data_done,
		data_not_done
	}client_info;
	
struct data
	{
		char ID[4];
		char pass[4];
		client_info inputs_state;
	}clients_data;
	

	

	
void login_init(); 
void login_update();
enum system get_system();

#endif /* LOGIN_H_ */