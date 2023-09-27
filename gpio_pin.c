#include "ML51.H"
#include "gpio_pin.h"
#include "timer.h"
#include "global.h"



//
static void number_value(int value);

void gpio_initialize(void)
{
		P25_PUSHPULL_MODE;
		P17_PUSHPULL_MODE;
		P16_PUSHPULL_MODE;
		P15_PUSHPULL_MODE;
		P14_PUSHPULL_MODE;
		P01_PUSHPULL_MODE;
		P02_PUSHPULL_MODE;
		P03_PUSHPULL_MODE;
		P40_PUSHPULL_MODE;
		P41_PUSHPULL_MODE;
		P42_PUSHPULL_MODE;
		P43_PUSHPULL_MODE;
		P44_PUSHPULL_MODE;
		P45_PUSHPULL_MODE;
	  P13_PUSHPULL_MODE;
		P33_PUSHPULL_MODE;
		P34_INPUT_MODE;	
		P35_INPUT_MODE;	
		P07_PUSHPULL_MODE;
		P13_INPUT_MODE;	
		P31_INPUT_MODE;

}

void zero (void)
{
	PIN_A = 1;					//  ____								
	PIN_B = 1;          // |    |
	PIN_C = 1;          // |    |
	PIN_D = 1;          // |    |
	PIN_E = 1;          // |____|
	PIN_F = 1;
	PIN_G = 0;
	PIN_SYM1 = 0;
	PIN_SYM2 = 0;
}

void one (void)
{
	PIN_A = 0;					//      						
	PIN_B = 1;          //      |
	PIN_C = 1;          //      |
	PIN_D = 0;          //      |
	PIN_E = 0;          //      |
	PIN_F = 0;
	PIN_G = 0;
	PIN_SYM1 = 0;
	PIN_SYM2 = 0;
}

void two (void)
{
	PIN_A =  1;					//  ____
	PIN_B =  1;         //      |
	PIN_C =  0;         //  ____|
	PIN_D =  1;         // |     
	PIN_E =  1;         // |____
	PIN_F =  0;
	PIN_G =  1;
	PIN_SYM1 = 0;
	PIN_SYM2 = 0;
}

void three (void)
{
	PIN_A = 1;					//  ____
	PIN_B = 1;          //      |
	PIN_C = 1;          //  ____|
	PIN_D = 1;          //      |
	PIN_E = 0;          //  ____|
	PIN_F = 0;
	PIN_G = 1;
	PIN_SYM1 = 0;
	PIN_SYM2 = 0;
}

void four (void)
{
	PIN_A =  0;					//  
	PIN_B =  1;         // |    |
	PIN_C =  1;         // |____|
	PIN_D =  0;         //      |
	PIN_E =  0;         //      |
	PIN_F =  1;
	PIN_G =  1;
	PIN_SYM1 = 0;
	PIN_SYM2 = 0;
}

void five (void)
{
	PIN_A =  1;					//  ____
	PIN_B =  0;         // |
	PIN_C =  1;         // |____
	PIN_D =  1;         //      |
	PIN_E =  0;         //  ____|
	PIN_F =  1;
	PIN_G =  1;
	PIN_SYM1 = 0;
	PIN_SYM2 = 0;
}

void six (void)
{
	PIN_A =  1;					//  ____
	PIN_B =  0;         // |
	PIN_C =  1;         // |____
	PIN_D =  1;         // |    |
	PIN_E =  1;         // |____|
	PIN_F =  1;
	PIN_G =  1;
	PIN_SYM1 = 0;
	PIN_SYM2 = 0;
}

void seven (void)
{
	PIN_A =  1;					//  ____
	PIN_B =  1;         //      |
	PIN_C =  1;         //      |
	PIN_D =  0;         //      |
	PIN_E =  0;         //      |
	PIN_F =  0;
	PIN_G =  0;
	PIN_SYM1 = 0;
	PIN_SYM2 = 0;
}

void eight (void)
{
	PIN_A =  1;					//  ____
	PIN_B =  1;         // |    |
	PIN_C =  1;         // |____|
	PIN_D =  1;         // |    |
	PIN_E =  1;         // |____|
	PIN_F =  1;
	PIN_G =  1;
	PIN_SYM1 = 0;
	PIN_SYM2 = 0;
}

void nine (void)
{
	PIN_A =  1;					//  ____
	PIN_B =  1;         // |    |
	PIN_C =  1;         // |____|
	PIN_D =  1;         //      |
	PIN_E =  0;         //  ____|
	PIN_F =  1;
	PIN_G =  1;
	PIN_SYM1 = 0;
	PIN_SYM2 = 0;
}

void display_scan(void)
{
	switch(displayNo)
	{
			case 0:
				DIGIT4 = 0;
				one();
				DIGIT1 = 1; //digit1
				break;
			
			case 1:
				DIGIT1 = 0;
				two();
				DIGIT2 = 1; //digit2
				break;
			
			case 2:
				DIGIT2 = 0;
				three();
				DIGIT3 = 1; //digit3
				break;
			
			case 3:
				DIGIT3 = 0;
				four();
  			DIGIT4 = 1; //digit4
				break;
		}

		displayNo++;

		if(displayNo>=4)
		{
			displayNo = 0;
		}
}


