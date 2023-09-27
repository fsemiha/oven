/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: ML51 simple GPIO toggle out demo code
//***********************************************************************************************************
#include "ML51.h"
#include "timer.h"
#include "gpio_pin.h"
#include "global.h"
#include "events.h"
#include "pwm_buzzer.h"
#include "icon.h"

#define BT P35
#define BT2 P34
#define BT3 P31

const int periodDuration=500;

void main(void)
{
	  gpio_initialize();
	  timer0_initialize();
 	  Timer0_ISR();
		pwm0_initialize();
	
   while(1) 
	 {
// 			display_scan();
//  		display_counter();
// 			counterDigit();
// 			countBack (); 
//	 		buzzer_bip(20);
//	 		buzzer_correct_bip(50);
//			oven_start();		 
//			key_icon_on();
//			key_icon_off();	 
//	    alarm(1);
//		  setFlash();
				setClockUp_min();
				setClockUp_sec();
				setClockDown ();
//	buzzer_correct_bip2(500,750,1250);
//		 buzzer_bip(100); 

	 	
		}
}

