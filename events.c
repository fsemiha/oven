#include "ML51.h"
#include "timer.h"
#include "gpio_pin.h"
#include "global.h"
#include "pwm_buzzer.h"
#include "icon.h"

#define UPDATE_TIME 0

#define BT P35
#define BT2 P34
#define BT3 P31

#define LONGTIME 3000
#define DEBOUNCETIME 100
#define LONGTIMESETCLOCK 1000
#define DISPLAY_UPDATE 1


void countBack() {
		
			if ((CurrentTime - previousTime  > LONGTIME ) ) {
			    
					previousTime = CurrentTime;
				
				
					if(counter == 1) 
				 {
					 buzzer_correct_bip(50);
					 zero();
					 d_delay_msec(500);		
					 counter = 0;					 
				 } else if(counter == 2 ) {
					 buzzer_correct_bip(50);
					 one();
					 d_delay_msec(500);
					 zero();
					 d_delay_msec(500);
					 counter = 0;
				} else if(counter == 3 ) {
					 buzzer_correct_bip(50);
					 two();
					 d_delay_msec(500);
					 one();
					 d_delay_msec(500);
					 zero();
					 d_delay_msec(500);
					 counter = 0;	
				} else if(counter == 4 ) {
					 buzzer_correct_bip(50);
					 d_delay_msec(500);
					 three();
					 d_delay_msec(500);
					 two();
					 d_delay_msec(500);
					 one();
					 d_delay_msec(500);
					 zero();
					 d_delay_msec(500);
					 counter = 0;	
				} else if(counter == 5 ) {		  
					 buzzer_correct_bip(50);
					 d_delay_msec(500);
					 four();
					 d_delay_msec(500);				
					 three();
					 d_delay_msec(500);
					 two();
					 d_delay_msec(500);
					 one();
					 d_delay_msec(500);
					 zero();
					 d_delay_msec(500);
					 counter = 0;	
				
		} else if(counter == 6 ) {
			     buzzer_correct_bip(50);
					 five();
					 d_delay_msec(500);
					 four();
					 d_delay_msec(500);				
					 three();
					 d_delay_msec(500);
					 two();
					 d_delay_msec(500);
					 one();
					 d_delay_msec(500);
					 zero();
					 d_delay_msec(500);
					 counter = 0;	
				} else if(counter == 7 ) {
					 buzzer_correct_bip(50);
					 six();
					 d_delay_msec(500);
					 five();
					 d_delay_msec(500);
					 four();
					 d_delay_msec(500);				
					 three();
					 d_delay_msec(500);
					 two();
					 d_delay_msec(500);
					 one();
					 d_delay_msec(500);
					 zero();
					 d_delay_msec(500);
					 counter = 0;	
				} else if(counter == 8 ) {
					 buzzer_correct_bip(50);
					 seven();
					 d_delay_msec(500);
					 six();
					 d_delay_msec(500);
					 five();
					 d_delay_msec(500);
					 four();
					 d_delay_msec(500);				
					 three();
					 d_delay_msec(500);
					 two();
					 d_delay_msec(500);
					 one();
					 d_delay_msec(500);
					 zero();
					 d_delay_msec(500);
					 counter = 0; 	
				} else if(counter == 9 ) {
					 buzzer_correct_bip(50);
					 eight();
					 d_delay_msec(500);
					 seven();
					 d_delay_msec(500);
					 six();
					 d_delay_msec(500);
					 five();
					 d_delay_msec(500);
					 four();
					 d_delay_msec(500);				
					 three();
					 d_delay_msec(500);
					 two();
					 d_delay_msec(500);
					 one();
					 d_delay_msec(500);
					 zero();
					 d_delay_msec(500);
					 counter = 0;	
				} 
	}
}
		
		
void counterDigit (void) {
			DIGIT1 = 1;
			DIGIT2 = 0;
			DIGIT3 = 0;
			DIGIT4 = 0;
			
		if(BT == 1) {
				d_delay_msec(1);
				if(BT == 1) {   //arklari önlemek için 2 if iç içe
					d_delay_msec(1);
					if(BT == 1) {
						if(BT == 1 && CurrentTime - previousTime > DEBOUNCETIME) {		   	
							previousTime = CurrentTime;
							counter++; 
							buzzer_bip(10);
								}
							}
						}
					}
			while (BT == 1) {  countBack(); }  
				
				switch(counter) {
				case 0:
				{
					zero();
					break;
				}
				case 1:
				{
					one();
					break;
				}
					case 2:
				{
					two();
					break;
				}
				case 3:
				{
					three();
					break;
				}
					case 4:
				{
					four();
					break;
				}
				case 5:
				{
					five();
					break;
				}
				case 6:
				{
					six();
					break;
				}
				case 7:
				{
					seven();
					break;
				}
				case 8:
				{
					eight();
					break;
				}
				case 9:
				{
					nine();
					break;
				}
				default:
				{
					counter = 0;
					break;
				}
			} 
}


void lcd_set(unsigned char *value) {
	
	PIN_A = value[0];					  							
	PIN_B = value[1];
	PIN_C = value[2];    
	PIN_D = value[3]; 
	PIN_E = value[4];  
	PIN_F = value[5];
	PIN_G = value[6];
	PIN_SYM1 = value[7];
	PIN_SYM2 = value[8];
}

void digits_off(void){
	DIGIT1 = 0;
	DIGIT2 = 0;
	DIGIT3 = 0;
	DIGIT4 = 0;
}

static void number_value(int value){
	if(value == 0)
	{
		zero();
	}
	else if(value == 1)
	{
		one();
	}
	else if(value == 2)
	{
		two();
	}
	else if(value == 3)
	{
		three();
	}
	else if(value == 4)
	{
		four();
	}
	else if(value == 5)
	{
		five();
	}
	else if(value == 6)
	{
		six();
	}
	else if(value == 7)
	{
		seven();
	}
	else if(value == 8)
	{
		eight();
	}
	else if(value == 9)
	{
		nine();
	}
}

void display_update(int value) {
	
	Units_digit = (value % 10);
	Tens_digit = ((value % 100)-Units_digit)/10;
	Hundreds_digit = ((value % 1000)-(value % 100))/100;
	Thousands_digit = (value-(value % 1000))/1000;
	
	while(1)
	{
		DIGIT1 = 1;
		DIGIT2 = 0;
		DIGIT3 = 0;
		DIGIT4 = 0;
		number_value(Thousands_digit);
		
		d_delay_msec(5);
		
		DIGIT1 = 0;
		DIGIT2 = 1;
		DIGIT3 = 0;
		DIGIT4 = 0;
		number_value(Hundreds_digit);
		
		d_delay_msec(5);
		
		DIGIT1 = 0;
		DIGIT2 = 0;
		DIGIT3 = 1;
		DIGIT4 = 0;
    number_value(Tens_digit);
		
		d_delay_msec(5);
		
		
		DIGIT1 = 0;
		DIGIT2 = 0;
		DIGIT3 = 0;
		DIGIT4 = 1;
    number_value(Units_digit);
		
		d_delay_msec(5);
	}
}

void display_update_alarm_sec(int value) {
	Fourth_digit = (value % 10);
	Third_digit = ((value % 100)-Fourth_digit)/10;
	
	while(1)
	{		
		if(value)
		{
			digits_off();
			
			number_value(Fourth_digit);
			DIGIT1 = 0;
			DIGIT2 = 0;
			DIGIT3 = 0;
			DIGIT4 = 1;

			d_delay_msec(UPDATE_TIME);		
			
		  digits_off();
			
			number_value(Third_digit);
			DIGIT1 = 0;
			DIGIT2 = 0;
			DIGIT3 = 1;
			DIGIT4 = 0;
			
			d_delay_msec(UPDATE_TIME);
		}
		break;
 }
}

void display_update_alarm_min(int value) {
	Second_digit = (value % 10);
	First_digit = ((value % 100)-Second_digit)/10;
	
	while(1)
	{		
	if(value)
	{
		DIGIT1 = 1;
		DIGIT2 = 0;
		DIGIT3 = 0;
		DIGIT4 = 0;
	  number_value(First_digit);
		
		d_delay_msec(UPDATE_TIME);
		
		DIGIT1 = 0;
		DIGIT2 = 1;
		DIGIT3 = 0;
		DIGIT4 = 0;
		number_value(Second_digit);
		
		d_delay_msec(UPDATE_TIME);
	}
	break;
 }
}

void display_update_alarm_hour(int value){
	
	Second_digit = (value % 10);
	First_digit = ((value % 100)-Second_digit)/10;
	
	while(1)
	{		
	if(value != 24)
	{
		DIGIT1 = 1;
		DIGIT2 = 0;
		DIGIT3 = 0;
		DIGIT4 = 0;
	  number_value(First_digit);
		
		d_delay_msec(UPDATE_TIME);
		
		DIGIT1 = 0;
		DIGIT2 = 1;
		DIGIT3 = 0;
		DIGIT4 = 0;
		number_value(Second_digit);
		
		d_delay_msec(UPDATE_TIME);
	}
	else if ( value == 24)
	{
		DIGIT1 = 1;
		DIGIT2 = 0;
		DIGIT3 = 0;
		DIGIT4 = 0;
	  zero();
		
		d_delay_msec(UPDATE_TIME);
		
		DIGIT1 = 0;
		DIGIT2 = 1;
		DIGIT3 = 0;
		DIGIT4 = 0;
		zero();
		
		d_delay_msec(UPDATE_TIME);
	}
	break;
 }
}

void alarm(int value) {
  point_icon_on();
	TimeMinuteDown = value - 1;

	
	while(1)
	{
		display_update_alarm_sec(TimeSecondDown);
	  display_update_alarm_min(TimeMinuteDown);
	}
}



void setClockUp_min () {		
	Units_digit = (value_min % 10);
	Tens_digit = ((value_min % 100)-Units_digit)/10;

		if(BT2 == 1) {
				d_delay_msec(10);
				if(BT2 == 1) {   //arklari önlemek için 2 if iç içe
					d_delay_msec(10);
					if(BT2 == 1) {
						if(BT2 == 1 && CurrentTime - previousTime > DEBOUNCETIME) {		   //100 ms   	
							previousTime = CurrentTime;
							value_min++; 
							
							}  
					 }
				}
		} buzzer_bip_min(10); 
		 
		
			
			while (BT2 == 1 ) {                     // arttirma butonuna basili tutulurken ilerlememesi için
				DIGIT1 = 1;
				DIGIT2 = 0;
				DIGIT3 = 0;
				DIGIT4 = 0;
				number_value(Tens_digit);
				
				d_delay_msec(DISPLAY_UPDATE);   //1 ms beklet
				
				DIGIT1 = 0;
				DIGIT2 = 1;
				DIGIT3 = 0;
				DIGIT4 = 0;
				number_value(Units_digit);
				
				d_delay_msec(DISPLAY_UPDATE);
			}
				DIGIT1 = 1;
				DIGIT2 = 0;
				DIGIT3 = 0;
				DIGIT4 = 0;
				number_value(Tens_digit);
				
				d_delay_msec(DISPLAY_UPDATE);
				
				DIGIT1 = 0;
				DIGIT2 = 1;
				DIGIT3 = 0;
				DIGIT4 = 0;
				number_value(Units_digit);
				
				d_delay_msec(DISPLAY_UPDATE );
} 

	
void setClockDown () {

	Units_digit_min = (value_min % 10);
	Tens_digit_min = ((value_min % 100) - Units_digit_min)/10;

	Units_digit_sec = (value_sec % 10);
	Tens_digit_sec = ((value_sec % 100) - Units_digit_sec)/10;
	
	
	if(BT == 1)
	{
		 previousTime = CurrentTime;

		while(BT == 1)
		{
			// uzun basma durumunda display reflash etmesi icin eklendi
			TimeMinuteDown = value_min;
			TimeSecondDown = value_sec;
			
			display_update_alarm_sec(TimeSecondDown);
			display_update_alarm_min(TimeMinuteDown);
		
			// Eger butona uzun basildiysa
			if (BT == 1 && (CurrentTime - previousTime  > LONGTIME)) { //1000 ms  basili tutulduysa geri sayma islemine basla
	      previousTime = CurrentTime;
		
				TimeMinuteDown = value_min;
				TimeSecondDown = value_sec;
	
				while(1)
				{
					display_update_alarm_sec(TimeSecondDown);
					display_update_alarm_min(TimeMinuteDown);
					
					if (TimeMinuteDown == 0 && TimeSecondDown < 30 && TimeSecondDown > 0)
					{
						display_update_alarm_sec(TimeSecondDown);
						buzzer_bip(20);
					} 
					
					// Display degeri 0 olduysa buradan cik.
					if(TimeMinuteDown == 0 && TimeSecondDown == 0)
					{
						value_min = 0;
						value_sec = 0;
						TimeSecondDown = 0;
						TimeMinuteDown = 0;
						buzzer_correct_bip(500);
					//	buzzer_correct_bip2(500,750,1250);
						break;	
					}			 
				}		
			}	
		}
	}
}	 

void setClockUp_sec () {		
	Units_digit = (value_sec % 10);
	Tens_digit = ((value_sec % 100)-Units_digit)/10;
		
		if(BT3 == 1) {
				d_delay_msec(10);
				if(BT3 == 1) {   //arklari önlemek için 2 if iç içe
					d_delay_msec(10);
					if(BT3 == 1) {
						if(BT3 == 1 && CurrentTime - previousTime > DEBOUNCETIME) {		   //100 ms   	
							previousTime = CurrentTime;
							value_sec++; 

							}
						}
					}
		} 
		 buzzer_bip_sec (10);

			while (BT3 == 1 ) {                     // arttirma butonuna basili tutulurken ilerlememesi için
				DIGIT1 = 0;
				DIGIT2 = 0;
				DIGIT3 = 1;
				DIGIT4 = 0;
				number_value(Tens_digit);
				
				d_delay_msec(DISPLAY_UPDATE);   //1 ms beklet
				
				DIGIT1 = 0;
				DIGIT2 = 0;
				DIGIT3 = 0;
				DIGIT4 = 1;
				number_value(Units_digit);
				
				d_delay_msec(DISPLAY_UPDATE);
			}
				DIGIT1 = 0;
				DIGIT2 = 0;
				DIGIT3 = 1;
				DIGIT4 = 0;
				number_value(Tens_digit);
				
				d_delay_msec(DISPLAY_UPDATE);
				
				DIGIT1 = 0;
				DIGIT2 = 0;
				DIGIT3 = 0;
				DIGIT4 = 1;
				number_value(Units_digit);
				
				d_delay_msec(DISPLAY_UPDATE );
} 




void setFlash () {
	

		if (elapsedTime > 500 ) 
		{
						previousTime = CurrentTime;
						elapsedTime = 0;
						FlagPoint = 1; 
					
						lcd_set(sym_l1_l2_l3);
						
						DIGIT1 = 0;
						DIGIT2 =~ DIGIT2;
						DIGIT3 = 0;
						DIGIT4 = 0;				
		}	
}