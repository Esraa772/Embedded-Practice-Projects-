#include "L_C_D.h"
#define lcd_period	40
#define clr_bit(reg,index) reg&=(~(1<<index))
#define set_bit(reg,index) reg|=(1<<index)
void lcd_init()
{
	lcd_dir_data=0xf0;   //port of data output 
	lcd_dir_crl=0x0E;    //0000 0011  control bit of E and RS to be output 
	/*_delay_ms(200);*/
	
	
	lcd_send_command (0x33)  ;
	lcd_send_command (0x32)  ;
	lcd_send_command (0x28)  ;
	lcd_send_command(0x0c);
	lcd_send_command (0x01)  ;
	lcd_send_command (0x82)  ;
	clr_bit(lcd_val_crl,rw);
	
	
}


void lcd_send_command(uint8_t cmd)
{
	clr_bit(lcd_val_crl,rs);
	lcd_val_data=((lcd_val_data&0x0f)|(cmd&0xf0));
	
	clr_bit(lcd_val_crl,en);
	lcdwait;
	set_bit(lcd_val_crl,en);
	lcdwait;
	
	lcd_val_data=((lcd_val_data&0x0f)|((cmd<<4)&0xf0));
	clr_bit(lcd_val_crl,en);
	lcdwait;
	set_bit(lcd_val_crl,en);
	lcdwait;
	
for (int i=0;i<100;i++)
{
}
	
	
}

void lcd_send_data(unsigned char data)
{
	set_bit(lcd_val_crl,rs);
	lcd_val_data=((lcd_val_data&0x0f)|(data&0xf0));
	
	clr_bit(lcd_val_crl,en);
	lcdwait;
	set_bit(lcd_val_crl,en);
	lcdwait;
	
	lcd_val_data=((lcd_val_data&0x0f)|((data<<4)&0xf0));
	clr_bit(lcd_val_crl,en);
	lcdwait;
	set_bit(lcd_val_crl,en);
	lcdwait;
for (int i=0;i<100;i++)
{
}
	
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
		case 0:
		{
			lcd_set_cursor(first_row,first_column);
			lcd_send_string("1-login");
			lcd_set_cursor(second_row,first_column);
			lcd_send_string("2-sign up");
			break;
		}
		case 1:
		{
			lcd_set_cursor(first_row,first_column);
			lcd_send_string("ID: ");
			lcd_set_cursor(second_row,first_column);
			lcd_send_string("pass: ");
			break;
		}
		case 2:
		{
			lcd_set_cursor(first_row,first_column);
			lcd_send_string("ID: ");
			lcd_set_cursor(second_row,first_column);
			lcd_send_string("pass: ");
			break;
		}
	}
}

void lcd_clear(void)
{
	lcd_send_command(0x01);
}

void lcd_set_cursor(unsigned char x,unsigned char y)
{
	if (x==0)
	{
		lcd_send_command(0x80+y);
	}
	else 
	{
		lcd_send_command(0xc0+y);
	}
}	

void lcd_send_string(char * str)
{
	while (*str!='\0')
	{
		lcd_send_data(*str);
		str++;
	}
	
	
	
}	
 void lcd_out(unsigned char x,unsigned char y,char *str) 
 {
	 lcd_set_cursor(x,y);
	 lcd_send_string(str);
 }
 
 char * convert_data(unsigned int var)
 {
	 static char data[17];
	 char * arr=&data[16];
	 *arr='\0';
	 if (var==0)
	 {
		 return "0";
	 }
	 while (var !='\0')
	 {
		 arr--;
		 * arr = (var%10)+'0';
		 var=var/10;
		 
	 }
	 
	 return arr ;
	 
 }