#include "ML51.H"
#include "driver_timer.h"
#include "driver_gpio.h"

void pwm0_initialize(void)
{
	  MFP_P25_PWM0_CH0;  // PIN 2
	
	  PWM0_IMDEPENDENT_MODE;
    PWM0_CLOCK_DIV_2;
//  PWM0PH = 0x2F;    // 1KHz
//  PWM0PL = 0x10;
	  PWM0PH = 0x2E;		//1.01KHz 
	  PWM0PL = 0xDF;
/**********************************************************************
  PWM frequency = Fpwm/((PWMPH,PWMPL) + 1) <Fpwm = Fsys/PWM_CLOCK_DIV>   Fsys = 24MHz for ML56
                = (24MHz/2)/(0x2EDF + 1)
                = 1KHz (1ms)
***********************************************************************/
    SFRS = 1;                 //Duty is in SFRS page 1
    PWM0C0H = 0x17;          
    PWM0C0L = 0x10;

/* PWM output inversly enable */
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
	/*-------- PWM stop run--------------*/ 
    clr_PWM0CON0_PWMRUN;
    clr_PWM0CON0_LOAD;  
}