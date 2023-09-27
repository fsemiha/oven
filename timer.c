#include "ML51.H"
#include "timer.h"
#include "gpio_pin.h"
#include "global.h"
#include "events.h"
#include "pwm_buzzer.h"

#define BT P35
#define BT2 P34
#define BT3 P31
/************************************************************************************************************
*    TIMER 0 interrupt initialize
************************************************************************************************************/
void timer0_initialize(void)
{
	  ENABLE_TIMER0_MODE0;                        //Timer 0 mode configuration
		TIMER0_FSYS_DIV12;
//	TIMER0_FSYS;

    TH0 = TH0_INIT;
    TL0 = TL0_INIT;
      
    ENABLE_TIMER0_INTERRUPT;                    //enable Timer0 interrupt
    ENABLE_GLOBAL_INTERRUPT;                    //enable interrupts

    set_TCON_TR0;                               //Timer0 run
}


/************************************************************************************************************
*    TIMER 0 interrupt subroutine // 1mslik timer
************************************************************************************************************/
void Timer0_ISR (void) interrupt 1           //interrupt address is 0x000B
{
    _push_(SFRS);
 
    TH0 = TH0_INIT;
    TL0 = TL0_INIT;
    TF0 = 0 ;                           
		
	  Buzzer_counter++;
	  CurrentTime2++;
		CurrentTime3++;
	
		if(BT == 1) {
			CurrentTime++;
			elapsedTime = CurrentTime - previousTime;
		}
		
	  if(BT2 == 1) {
			CurrentTime++;
			elapsedTime = CurrentTime - previousTime;
		}
		
		if(BT3 == 1) {
			CurrentTime++;
			elapsedTime = CurrentTime - previousTime;
		}
		
		counter_down++;
		if (counter_down == 76) {
				counter_down = 0;
		
		}
				
		if(FlagPoint == 1) {
			//////////////// SAATIN ILERI GERI SAYMASI /////////////
				FlagPointLong = 1;
				SayacTime++;
		}
		if(SayacTime == 15000) {
			
			FlagPointLong = 0;
			SayacTime = 0;
		}
		sayacTimer++;
		
		TimeCounterUp++;
	  TimeCounterDown++;
		
		if(TimeCounterUp == 1000){
			
			TimeCounterUp = 0;
			
			TimeSecondUp++;
			
			if(TimeSecondUp == 60)
			{
				TimeSecondUp = 0;
				TimeMinuteUp++;
				
				if(TimeMinuteUp == 60)
				{
					TimeMinuteUp = 0;
					TimeHourUp++;
					
					if(TimeHourUp == 24)
					{
						TimeHourUp = 0;
					}
				}
			}
		}
	
		if(TimeCounterDown == 1000) {
				
			TimeCounterDown = 0;
			
			TimeSecondDown--;
			if(TimeMinuteDown > 0)
			{
				if(TimeSecondDown == 0)
				{
					TimeSecondDown = 60;
					TimeMinuteDown--;					
					if(TimeMinuteDown == 0)
					{
						if (TimeSecondDown < 30 && TimeSecondDown > 0) 
						{
							FlagCook = 1;
						}
					}
				}
			}
		}
		
    _pop_(SFRS);
}	

void d_delay_msec(uint16_t msec)
{
  Timer1_Delay(24000000,msec,1000);	
}


void Timer1_Delay(unsigned long u32SYSCLK, unsigned int u16CNT, unsigned int u16DLYUnit)
{
    unsigned char TL1TMP,TH1TMP;
    
    SFRS = 0;
    TIMER1_FSYS_DIV12;                                 //T1M=0, Timer1 Clock = Fsys/12
    ENABLE_TIMER1_MODE1;                                //Timer1 is 16-bit mode
    TL1TMP = LOBYTE(65535-((u32SYSCLK/1000000)*u16DLYUnit)/12);
    TH1TMP = HIBYTE(65535-((u32SYSCLK/1000000)*u16DLYUnit)/12);
  
    while (u16CNT != 0)
    {
      TL1 = TL1TMP;
      TH1 = TH1TMP;
      set_TCON_TR1;                                //Start Timer1
      while (!TF1);                                //Check Timer1 Time-Out Flag
      clr_TCON_TF1;
      clr_TCON_TR1;
      u16CNT --;
    }
}

