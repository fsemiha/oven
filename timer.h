#define TH0_INIT        0xC0 
#define TL0_INIT        0x10

void Timer0_ISR (void);
void timer0_initialize(void);
void d_delay_msec(uint16_t msec);
void delay(uint32_t);