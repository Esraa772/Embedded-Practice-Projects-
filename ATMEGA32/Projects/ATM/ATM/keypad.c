
#include "keypad.h"

#define period_keypad	10

struct data 
{
	char oldstate,currentstate;
	pin_states states;
	char row,col;
}keypad_data[4];

static char key_val;
static char key[4][4]={{1,2,3,'a'},{4,5,6,'b'},{7,8,9,'c'},{'*','0','#','d'}};
static char flag;

void keypad_init()
{
	keypad_dir=0xf0;
	keypad_port=0xff;
	
	key_val=no_pressed;
	keypad_data[0].oldstate=1;
	keypad_data[0].col=0;
	keypad_data[0].row=no_pressed;
	keypad_data[0].states=high_val;
	keypad_data[1].states=high_val;
	keypad_data[2].states=high_val;
	keypad_data[3].states=high_val;
}
char search(char val )
{
	char iter,new_val;
	for(iter=0;iter<4;iter++)
	{
		new_val=val&(1<<iter);
		if (new_val==0)
		{
			return iter;
	
		}	
	}
	
		return no_pressed;
	
}

void keypad_update()
{
	static char keypad_period=0,col=0;
	keypad_period+=tick;
	if(keypad_period!=period_keypad)
	{
		return ;
	}
	keypad_period=0;
	
	keypad_port|=0xf0;
	pin_write(keypad_port,col+4,low);

	keypad_data[col].oldstate=keypad_data[col].currentstate;
	keypad_data[col].col=col;
	keypad_data[col].row=search((keypad_input&0x0f));
	
	if (keypad_data[col].row!=no_pressed)
	{
	keypad_data[col].currentstate=((keypad_input>>keypad_data[col].row)&0x01);
	}
	else
	{
		keypad_data[col].currentstate=1;
	}
		
	
	
	switch(keypad_data[col].states)
	{
		case high_val:
		if (keypad_data[col].oldstate==0&&keypad_data[col].currentstate==0)
		{
			keypad_data[col].states=falling;
		}
		break;
		
		case falling:
		if (keypad_data[col].currentstate==0)
		{
			keypad_data[col].states=low_val;
		}
		break;
		
		case low_val:
		if (keypad_data[col].oldstate==1&&keypad_data[col].currentstate==1)
		{
			keypad_data[col].states=rising;
		}
		break;
		
		case rising:
		if (keypad_data[col].currentstate==1)
		{
			keypad_data[col].states=high_val;
		}
		break;
	
	default:
	break;
	}
	int i;
	for (i=0;i<4;i++)
	{
		if(keypad_data[i].row!=no_pressed)
		{
			key_val=key[keypad_data[i].row][keypad_data[i].col];
			flag=i;
			break;
		}
	}
	col++;
	col=col==4?0:col;
	
}

char keypad_get_key()
{
	static char oldval;
	if(keypad_data[flag].states==falling)
	{
		oldval=key_val;
		return key_val;
		
	}
	else
	{
		return no_pressed;
	}
}