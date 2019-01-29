
#ifndef E2PRM_H_
#define E2PRM_H_
#include "port.h"
#include "signUp.h"
#include <string.h>
#include <stdlib.h>

//************* Reading functions *****************
void EEPROM_init();
void set_data_list(struct sign_up_data obj);
void update_client_list();
char * getlist();
void EEPROM_update();
void EEPROM_write(uint16_t address, uint8_t data);
void EEPROM_write_integer(uint16_t address,uint16_t data);
void EEPROM_write_string(uint16_t address,uint8_t * data);

//***********Writing functions ******************

uint8_t EEPROM_read(uint16_t address);
uint16_t EEPROM_read_integer(uint16_t address);



#endif /* E2PRM_H_ */