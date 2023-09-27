#include "ML51.h"
#include "timer.h"
#include "gpio_pin.h"
#include "global.h"
#include "events.h"

#define BT P35
#define BT2 P34
#define BT3 P31
void pwm0_initialize(void)
{
	  MFP_P25_PWM0_CH0;  // PIN 2
		
	  PWM0_IMDEPENDENT_MODE;
	
		PWM0PH = 0x2E;		//1.01KHz 
	  PWM0PL = 0xDF;
		
	  SFRS = 1;                 //Duty is in SFRS page 1
    PWM0C0H = 0x17;          
    PWM0C0L = 0x10;
		
		PWM0_CHANNEL0_OUTPUT_INVERSE;
}
void pwm0_start(void)
{
	/*-------- PWM start run--------------*/ 
    set_PWM0CON0_LOAD;
    set_PWM0CON0_PWMRUN;
}
void pwm0_stop(void)
{ 
    clr_PWM0CON0_LOAD;  
		clr_PWM0CON0_PWMRUN;
}

void buzzer_bip_min(int value)
{
	  if (BT2== 1)
		{
			PreviousTime2 = CurrentTime2;
			pwm0_start();
				
		}
		if(CurrentTime2 - PreviousTime2 >= value)
		{
			pwm0_stop();
		} 

}

void buzzer_bip_sec(int value)
{
	  if (BT3== 1)
		{
			PreviousTime2 = CurrentTime2;
			pwm0_start();		
		}
		if(CurrentTime2 - PreviousTime2 >= value)
		{
			pwm0_stop();
		}  
}

void buzzer_bip(int value)
{
	pwm0_start();
	d_delay_msec(value);
	pwm0_stop();
	d_delay_msec(value);
	/*	if (CurrentTime2-PreviousTime2 <= periodDuration)
		{
			PreviousTime2 == CurrentTime2;
			pwm0_start();;
		} else if (CurrentTime2-PreviousTime2 >= periodDuration)
		{
			pwm0_stop();; 
		}	 */
	/*		 if(Buzzer_counter <= value)
			{
				pwm0_start();
			} else 
			{
				pwm0_stop();
			} */
}
void buzzer_correct_bip(int value)
{
	buzzer_bip(value);
	buzzer_bip(value);
	buzzer_bip(value);
	buzzer_bip(value);
}

void buzzer_last30_bip(int value)
{
	buzzer_bip(value);
	buzzer_bip(value);
}

void buzzer_correct_bip2(int periodDuration, int periodDuration2, int periodDuration3)
{
	/*previousTime = CurrentTime;
		if (CurrentTime - previousTime <= periodDuration)
		{
			previousTime = CurrentTime;
			pwm0_start();;
		} else if (CurrentTime - previousTime >= periodDuration  && CurrentTime2 - previousTime <= periodDuration2  )
		{
			previousTime = CurrentTime;
			pwm0_stop();; 
		} else if (CurrentTime - previousTime >= periodDuration && CurrentTime - previousTime <= periodDuration3 )
		{
			previousTime = CurrentTime;
			pwm0_start();; 
		} else if (CurrentTime - previousTime >= periodDuration)
		{
			previousTime = CurrentTime;
			pwm0_stop();; 
		} */
			if(Buzzer_counter <= periodDuration)
			{
				pwm0_start();
			} else if (Buzzer_counter >= periodDuration && Buzzer_counter <= periodDuration2 ) 
			{
				pwm0_stop();
			} else if (Buzzer_counter >= periodDuration2 && Buzzer_counter <= periodDuration3 ) 
			{
				pwm0_start();
			} else if (Buzzer_counter >= periodDuration3) 
			{
				pwm0_stop();
			}
}


