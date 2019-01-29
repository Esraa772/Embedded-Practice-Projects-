#include "lcd.h"
#define lcd_period	10
void lcd_initialization()
{
	switch (lcd_mode)
	{
		case lcd_4_mode:
		{
			higher_nibble_write(lcd_data_dir,0x0f);
			pin_write(lcd_control_dir,lcd_RS_pin,output);
			pin_write(lcd_control_dir,lcd_enable_pin,output);
			pin_write(lcd_control_val,lcd_enable_pin,high);
			_delay_ms(200);
			
			lcd_send_command(0x33);
			lcd_send_command(0x32);
			lcd_send_command(lcd_4_mode);
			break;
		}
		case lcd_8_mode:
		{
			lcd_data_dir=0xff;
			pin_write(lcd_control_dir,lcd_RS_pin,output);
			pin_write(lcd_control_dir,lcd_enable_pin,output);
			pin_write(lcd_control_val,lcd_enable_pin,high);  //ask
			
			lcd_send_command(lcd_8_mode);
			break;
		}
	}
	lcd_send_command(display_on_cursor_blink);
	lcd_send_command(clear_display_screen);
}

void lcd_send_command(uint8_t command)
{
	pin_write(lcd_control_val,lcd_RS_pin,low);
	
	switch (lcd_mode)
	{
		case lcd_8_mode:
		{
			lcd_data_val=command;
			break;
		}
		case lcd_4_mode:
		{
			
			lcd_data_val=send_first_half(lcd_data_val,command);
			
			pin_write(lcd_control_val,lcd_enable_pin,high);
			_delay_ms(1);
			pin_write(lcd_control_val,lcd_enable_pin,low);
			_delay_ms(1);
			
			lcd_data_val=send_second_half(lcd_data_val,command);
			break;
		}
	}
	pin_write(lcd_control_val,lcd_enable_pin,high);
	_delay_ms(1);
	pin_write(lcd_control_val,lcd_enable_pin,low);
	_delay_ms(1);
	
	_delay_ms(2);
	
}
void lcd_update()
{   
	int current =fifth_column;
	static char loc=0;
	static int lcd_time;
	lcd_time+=tick;
	if (lcd_time!=lcd_period)
	{
		return;
	}
	lcd_time=0;
	switch (phase)
	{
		case '0':
		{
			lcd_set_cursor(first_row,first_column);
			lcd_send_string("1-login");
			lcd_set_cursor(second_row,first_column);
			lcd_send_string("2-sign up");
			break;
		}
		case '1':
		{
			lcd_set_cursor(first_row,first_column);
			lcd_send_string("ID: ");
			lcd_set_cursor(second_row,first_column);
			lcd_send_string("pass: ");
			
			if (loc<3)
			{
				lcd_set_cursor(first_row,current+loc);
				loc++;
			}
			else
			{
				lcd_set_cursor(second_row,current+(loc-1));
			}
			char key=keypad_get_key();
			lcd_send_data(key);
			if (loc>=5)
			{
				loc=0;
			}
			break;
		}
		case '2':
		{
			lcd_set_cursor(first_row,first_column);
			lcd_send_string("ID: ");
			lcd_set_cursor(second_row,first_column);
			lcd_send_string("pass: ");
			
			if (loc<3)
			{
				lcd_set_cursor(first_row,current+loc);
				loc++;
			}
			else
			{
				lcd_set_cursor(second_row,current+(loc-1));
			}
			char key=keypad_get_key();
			lcd_send_data(key);
			if (loc>=5)
			{
				loc=0;
			}
			break;
		}
	}
}
void lcd_send_data(uint8_t val)
{
	pin_write(lcd_control_val,lcd_RS_pin,high);
	switch (lcd_mode)
	{
		case lcd_8_mode:
		{
			
			lcd_data_val=val;
			break;
		}
		case lcd_4_mode:
		{
			
			lcd_data_val=send_first_half(lcd_data_val,val);
			
			pin_write(lcd_control_val,lcd_enable_pin,high);
			_delay_ms(1);
			pin_write(lcd_control_val,lcd_enable_pin,low);
			_delay_ms(1);
			
			lcd_data_val=send_second_half(lcd_data_val,val);
			break;
		}
	}
	pin_write(lcd_control_val,lcd_enable_pin,high);
	_delay_ms(1);
	pin_write(lcd_control_val,lcd_enable_pin,low);
	_delay_ms(1);
	
	_delay_ms(2);
}

void lcd_send_string(char* str)
{
	while (*str!='\0')
	{
		lcd_send_data(*str);
		str++;
	}
}

void lcd_clear()
{
	lcd_send_command(clear_display_screen);
}

void lcd_set_cursor(row_number row,column_number col)
{
	switch (row)
	{
		case first_row:
		{
			lcd_send_command(force_cursor_to_begin_at_first_ine+col);
			break;
		}
		case second_row:
		{
			lcd_send_command(forcr_cursor_to_begin_at_second_line+col);
			break;
		}
	}
}

void lcd_print(row_number row,column_number col,char *str)
{
	lcd_set_cursor(row,col);
	lcd_send_string(str);
}

char*convert_data(uint16_t val)
{
	static char data[17];
	char *arr=&data[16];
	*arr='\0';
	 
	 if (val==0)
	 {
		 return "0";
	 }
	 else
	 {
		while(val !=0) 
		{
			arr--;
			*arr=(val%10)+'0';
			val=val/10;
		}
		return arr;			
	 }
}