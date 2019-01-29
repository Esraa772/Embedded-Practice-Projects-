
#ifndef MICRO_H_
#define MICRO_H_
#include "configuration.h"


//************ input/output registers*************************************************************

	#define dira	DDRA
	#define dirb	DDRB
	#define dirc	DDRC
	#define dird	DDRD

//************************************************************************************************

	#define vala	PORTA
	#define valb	PORTB
	#define valc	PORTC
	#define vald	PORTD
	
//***********************************************************************************************

	#define inputa	PINA
	#define inputb	PINB
	#define inputc	PINC
	#define inputd	PIND

//***********************************************************************************************

	#define pin0	0
	#define pin1	1
	#define pin2	2
	#define pin3	3
	#define pin4	4
	#define pin5	5
	#define pin6	6
	#define pin7	7
	
//************************************************************************************************

	#define input	0
	#define output	1
	#define low		0
	#define high	1
	
//****************keyppad macros*******************************************************************

	#define no_pressed_key			0xff
	#define rows_input_cols_output	0xf0
	#define rows_pullup_cols_high	0xff
	
//**************adc configuration********************************************************************
	
	#define adc_control		ADCSRA
	#define multiplixer		ADMUX
	#define adc_enable_pin	ADEN
	#define adc_flag_pin	ADIF
	#define adc_SC_pin		ADSC
	#define ref_0_pin		REFS0
	#define ref_1_pin		REFS1
	#define s0_pin			ADPS0
	#define s1_pin			ADPS1
	#define s2_pin			ADPS2
	
//****************interrupt configuration **********************************************************

	#define general_interrupt_register	GICR
	#define interrupt_pin0				INT0
	#define interrupt_pin1				INT1
	#define interrupt_pin2				INT2
	#define edge_detect_pin0			ISC00
	#define edge_detect_pin1			ISC01
	#define edge_detect_pin2			ISC10
	#define edge_detect_pin3			ISC2
	#define edge_detect_pin4			ISC11
	#define interrupt_control			MCUCR
	#define adc_interrupt_pin			ADIE	

//************EEPROM configuration*******************************************************************

	#define		EEPROM_high_address_register	EEARH
	#define		EEPROM_low_address_register		EEARL
	#define		EEPROM_master_write_enable		EEMWE
	#define		EEPROM_CONTROL_REGISTER			EECR
	#define		EEPROM_address_register			EEAR
	#define		EEPROM_data_register			EEDR
	#define		EEPROM_write_enable				EEWE
	#define		EEPROM_read_enable				EERE

//*************USART configuration*******************************************************************

	#define USART_control_status_register_A		UCSRA
	#define USART_control_status_register_B		UCSRB
	#define USART_control_status_register_C		UCSRC
	#define usart_transmission_speed_bit		U2X
	#define usart_recieve_complete_flag			RXC
	#define USART_baud_rate_register_L			UBRRL
	#define USART_baud_rate_register_H			UBRRH
	#define data_register_empty_flag			UDRE
	#define transmit_enable_bit					TXEN
	#define character_size_bit0					UCSZ0
	#define character_size_bit1					UCSZ1
	#define character_size_bit2					UCSZ2
	#define register_select_bit					URSEL
	#define USART_data_register					UDR
	#define recieve_enable_bit					RXEN
	#define parity_mode_bit0					UPM0
	#define parity_mode_bit1					UPM1
	#define usart_mode_bit						UMSEL
	#define stop_bit							USBS
//**************timer configuration********************************************************************
              //****timer0*****
	#define timer_counter_control_register0		TCCR0
	#define timer0_counter_register				TCNT0
	#define timer0_output_compare_register		OCR0
	#define timer_counter_interrupt_flag_register	TIFR
	#define timer_counter_interrupt_mask_register	TIMSK
	#define timer0_mode_selector_bit00			WGM00
	#define timer0_mode_selector_bit01			WGM01
	#define timer0_prescaler_selector_bitcs00	CS00
	#define timer0_prescaler_selector_bitcs01	CS01
	#define timer0_prescaler_selector_bitcs02	CS02
	#define timer0_overflow_flag				TOV0
	#define timer0_output_compare_flag			OCF0
	#define timer0_overflow_interrupt_enable_bit	TOIE0
	#define timer0_output_compare_interrupt_enable_bit	OCIE0
	
	
	      //*****timer2*********
		  
	#define timer_counter_control_register2		TCCR2
	#define timer2_counter_register				TCNT2
	#define timer2_output_compare_register		OCR2
	#define timer2_mode_selector_bit20			WGM20
	#define timer2_mode_selector_bit21			WGM21
	#define timer2_prescaler_selector_bitcs20	CS20
	#define timer2_prescaler_selector_bitcs21	CS21
	#define timer2_prescaler_selector_bitcs22	CS22
	#define timer2_overflow_flag				TOV2
	#define timer2_output_compare_flag			OCF2
	#define Asynchronous_status_register		ASSR
	#define realtime_clock_selector_bit			AS2
	#define timer2_overflow_interrupt_enable_bit	TOIE2
	#define timer2_output_compare_interrupt_enable_bit	OCIE2
			//****timer1********
	#define timer1_counter_control_register_A	TCCR1A
	#define timer1_counter_control_register_B	TCCR1B
	#define timer1_counter_register				TCNT1
	#define timer1_output_compare_register_A	OCR1A
	#define timer1_output_compare_register_B	OCR1B
	#define timer1_counter_register_H			TCNT1H
	#define timer1_counter_register_L			TCNT1L
	#define timer1_overflow_flag				TOV1
	#define timer1_output_compare_B_match_flag		OCF1B
	#define timer1_output_compare_A_match_flag		OCF1A
	#define timer1_input_capture_flag				ICF1
	#define auxiliary_register						ICR1
	#define	timer1_mode_selectors_bit10				WGM10
	#define timer1_mode_selectors_bit11				WGM11
	#define timer1_mode_selectors_bit12				WGM12
	#define timer1_mode_selectors_bit13				WGM13
	#define timer1_prescaler_selector_bit10			CS10
	#define timer1_prescaler_selector_bit11			CS11
	#define timer1_prescaler_selector_bit12			CS12
	#define timer1_overflow_interrupt_enable_bit	TOIE1
	#define timer1_output_compare_register_A_iterrupt_bit	OCIE1A
	#define timer1_output_compare_register_B_iterrupt_bit	OCIE1B
	
//********macros definitions***************************************************************************

#define pin_write(reg,index,val)		reg=(reg & (~ (1<<index))) | (val<<index)
#define lower_nibble_write(reg,val)		reg= (reg & 0xf0) | val
#define higher_nibble_write(reg,val)	reg= (reg &0x0f ) | (val<<4)
#define get_bit(reg,index)				(reg>>index) & 0x01
#define toggle_bit(reg,index)			reg=reg ^(1<<index)
#define send_first_half(reg,val)		(reg & 0x0f) | (val & 0xf0)  //send the first half of data
#define send_second_half(reg,val)		(reg & 0x0f) | (val<<4)		//send the second half of data
#define higher_nibble(reg)				reg|=0xf0					// to write on the higher nibble

#endif /* MICRO_H_ */