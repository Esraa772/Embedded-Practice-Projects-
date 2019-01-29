#ifndef L_C_D_h
#define L_C_D_h
#include "port.h"
#include "decide.h"
typedef enum
{
	clear_display_screen=0x01,
	return_home=0x02,
	decrement_cursor=0x04,
	increment_cursor=0x06,
	shift_display_right=0x05,
	shift_display_left=0x07,
	display_off_cursor_off=0x08,
	display_off_cursor_on=0x0A,
	display_on_cursor_off=0x0C,
	display_on_cursor_blink=0x0F,
	shift_cursor_left=0x10,
	shift_cursor_right=0x14,
	shift_entire_display_left=0x18,
	shift_entire_display_right=0x1C,
	force_cursor_to_begin_at_first_ine=0x80,
	forcr_cursor_to_begin_at_second_line=0xC0,
	lcd_4_mode=0x28,
	lcd_8_mode=0x38
}command_name;

typedef enum
{
	first_column, second_column,
	third_column, fourth_column,
	fifth_column, sixth_column,
	seventh_column, eighth_column,
	ninth_column, tenth_column,
	eleventh_column, twelfth_column,
	thirteenth_column, fourteenth_column,
	fifteenth_column, sixteenth_column
}column_number;

typedef enum
{
	first_row,
	second_row
}row_number;
void lcd_init();
char * convert_data(unsigned int var);
void lcd_send_command(unsigned char cmd);
void lcd_send_data(unsigned char data);
void lcd_clear(void);
void lcd_update();
void lcd_set_cursor(unsigned char x,unsigned char y);
void lcd_send_string(char * str);
void lcd_out(unsigned char x,unsigned char y,char *str) ;

#define lcd_dir_data  DDRA  //from D0 to D7
#define lcd_dir_crl   DDRB  // E@RS
#define lcd_val_data  PORTA  //do to d7 port
#define lcd_val_crl   PORTB
#define en   3  //E
#define rs   1  //RS
#define rw  2
#define lcdwait    _delay_us(1)
//#define uint8_t   unsigned char


#endif
