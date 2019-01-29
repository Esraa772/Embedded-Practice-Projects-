#include "E2PRM.h"
#define eeprom_period	40
static int number_of_clients;
static char *arr[100*8];
void EEPROM_init()
{
	char n_clients=EEPROM_read(0x00);
	if(n_clients==255)
	{
		number_of_clients=0;
	}
	else
	{
		number_of_clients=n_clients;
	}
}

void set_data_list(struct sign_up_data obj)
{
	
	char iter;
	for (iter=0;iter<8;iter++)
	{
		if (iter<4)
		{
			EEPROM_write((0x01+iter)+(8*number_of_clients),obj.ID[iter]);
		}
		else
		{
			EEPROM_write((0x01+iter)+(8*number_of_clients),obj.pass[iter%4]);
		}
	}
}

void  EEPROM_update()
{
	static int eeprom_time;
	eeprom_time+=tick;
	if (eeprom_time!=eeprom_period)
	{
		return;
	}
	eeprom_time=0;
	switch (get_user_state())
	{
		case sign_up_state:
		{
			switch (get_signUp_system_state())
			{
				case system_signUp_valid:
				{
					set_data_list(get_new_client());// set clients data in EEPRROM
					number_of_clients++;
					EEPROM_write(0x00,number_of_clients);
					break;
				}
			}
			break;
		}
		case login_state:
		{
			char itr;
			for (itr=0;itr<number_of_clients*8;itr++)
			{
				arr[itr]=EEPROM_read(0x01+itr);
			}
		}
	}
}
char * getlist()
{
	return arr;
}
void EEPROM_write(uint16_t address, uint8_t data)
{
	while(EEPROM_CONTROL_REGISTER & (1<<EEPROM_write_enable));
	
	EEPROM_address_register=address;
	EEPROM_data_register=data;
	EEPROM_CONTROL_REGISTER |= 1<<EEPROM_master_write_enable;
	EEPROM_CONTROL_REGISTER |= 1<<EEPROM_write_enable;
}


void EEPROM_write_integer(uint16_t address,uint16_t data)
{
	uint8_t new_data,itr;  // itr  means iterator to iterate through memory and data
	
	for (itr=0;itr<sizeof(data);itr++)
	{
		new_data=(uint8_t)(data>>(8*itr));
		
		EEPROM_write(address+itr,new_data);
	}
}

void EEPROM_write_string(uint16_t address,uint8_t * data)
{
	uint16_t itr;
	
	for (itr=0;itr<strlen(data);itr++)
	{
		EEPROM_write(address+itr,*(data+itr));
		if (itr>1023)
		{
			break;
		}
	}
}


uint8_t EEPROM_read(uint16_t address)
{
	while(EEPROM_CONTROL_REGISTER & (1<<EEPROM_write_enable));
	
	EEPROM_address_register=address;
	
	EEPROM_CONTROL_REGISTER |= 1<<EEPROM_read_enable;
	uint16_t data=EEPROM_data_register;
	return data;
}

uint16_t EEPROM_read_integer(uint16_t address)
{
	
	uint16_t data;
	uint8_t itr,val;
	for (itr=0;itr<4;itr++)
	{
		val=EEPROM_read(address+itr);
		
		data+=val;
	}
	
	return data;
}

//   extra functions

//void update_client_list()
//{
	//clients=(client_list*)realloc(clients,number_of_clients*sizeof(client_list));
	//char iter,itr2;
	//for (iter=0;iter<number_of_clients;iter++)
	//{
		//for (itr2=0;itr2<8;itr2++)
		//{
			//if (itr2<4)
			//{
				//clients[iter].ID[itr2]=EEPROM_read((0x01+itr2)+(iter*8));
			//}
			//else
			//{
				//clients[iter].pass[itr2%4]=EEPROM_read((0x01+itr2)+(iter*8));
			//}
			//
		//}
	//}
//}
//char is_client_ID_inList(char*id)
//{
	//char itr,result=-1;
	//for (itr=0;itr<number_of_clients;itr++)
	//{
		//if (strcmp(id,clients[itr].ID)==0)
		//{
			//result=itr;
			//break;
		//}
	//}
	//return result;
//}
//
//char is_client_pass_inList(char*pass,char id_index)
//{
	//char result=0;
	//
	//
	//if (strcmp(pass,clients[id_index].pass)==0)
	//{
		//result=1;
		//break;
	//}
	//return result;
	//
//}