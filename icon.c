#include "ML51.h"
#include "timer.h"
#include "gpio_pin.h"
#include "global.h"
#include "pwm_buzzer.h"
#include "events.h"

void key_icon_on(void)
{			
	lcd_set(sym_k3_k4);
	
	DIGIT1 = 0;
	DIGIT2 = 0;
	DIGIT3 = 1;
	DIGIT4 = 1;
	
	
}

void key_icon_off(void)
{			
	lcd_set(sym_k3_k4);
	
	DIGIT1 = 0;
	DIGIT2 = 0;
	DIGIT3 = 0;
	DIGIT4 = 0;
}

void automatic_cooking_icon_on(void)
{
	lcd_set(sym_k3_k4);
	
	DIGIT1 = 1;
	DIGIT2 = 1;
	DIGIT3 = 0;
	DIGIT4 = 0;	
}

void automatic_cooking_icon_off(void)
{
	lcd_set(sym_k3_k4);
	
	DIGIT1 = 0;
	DIGIT2 = 0;
	DIGIT3 = 0;
	DIGIT4 = 0;
}

void alarm_icon_on(void)
{
  lcd_set(sym_l1_l2_l3);
	
	DIGIT1 = 0;
	DIGIT2 = 0;
	DIGIT3 = 1;
	DIGIT4 = 0;
}

void alarm_icon_off(void)
{
	lcd_set(sym_l1_l2_l3);
	
	DIGIT1 = 0;
	DIGIT2 = 0;
	DIGIT3 = 0;
	DIGIT4 = 0;
}

void cooking_icon_on(void)
{
	lcd_set(sym_l1_l2_l3);
	
	DIGIT1 = 1;
	DIGIT2 = 0;
	DIGIT3 = 0;
	DIGIT4 = 0;	
}

void cooking_icon_off(void)
{
	lcd_set(sym_l1_l2_l3);
	
	DIGIT1 = 0;
	DIGIT2 = 0;
	DIGIT3 = 0;
	DIGIT4 = 0;
}

void point_icon_on(void)
{
	lcd_set(sym_l1_l2_l3);
	
	DIGIT1 = 0;
	DIGIT2 = 1;
	DIGIT3 = 0;
	DIGIT4 = 0;
	
	
}

void point_icon_off(void)
{
	lcd_set(sym_l1_l2_l3);
	
	DIGIT1 = 0;
	DIGIT2 = 0;
	DIGIT3 = 0;
	DIGIT4 = 0;	
}

void oven_start(void)
{
	DIGIT1 = 1;
	DIGIT2 = 1;
	DIGIT3 = 1;
	DIGIT4 = 1;
		
	lcd_set(num_0);
	d_delay_msec(1);
	
	point_icon_on();
	d_delay_msec(1);

	automatic_cooking_icon_on();
	d_delay_msec(1);
	
}

void flash (void )
{

		point_icon_on();
		d_delay_msec(100);
		point_icon_off();
		d_delay_msec(100);
		FlagPoint = 1;   // butona basili iken sayaç baslatmak için kullanilir
}	
