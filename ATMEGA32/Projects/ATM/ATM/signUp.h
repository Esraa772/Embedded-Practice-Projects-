
#ifndef SIGNUP_H_
#define SIGNUP_H_
#include "decide.h"
#include "L_C_D.h"
static enum signUp_system
{
	system_signUp_valid,
	system_signUp_invalid
	}signUp_system_state;
	
typedef enum
{
	data_completed,
	data_not_complete
	}signUp_info;
	
struct sign_up_data
{
	char ID[4];
	char pass[4];
	signUp_info inputs_state
	}client_signup_data;

void signUp_init();
void signUp_update();
struct sign_up_data get_new_client();
enum signUp_system get_signUp_system_state();
#endif /* SIGNUP_H_ */