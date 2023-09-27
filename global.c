// Clock function parameters
int Hour = 0;
int Minute = 0;
int Second = 0;
int i;
int int_counter = 0;
int counter = 0;
int counterOld  = 0;
int counter1 = 0;
int buttonCounter = 0;
int count_1_sec = 0;
int value = 0; 

int CurrentTime3 = 0;
int CurrentTime = 0;
int previousTime = 0;
int debounceTime = 200;
int buttonPressDuration = 0;
int buttonPressLong = 0;

volatile int TimeCounterUp = 0;
volatile int TimeSecondUp = 0;
volatile int TimeMinuteUp = 0;
volatile int TimeHourUp = 0;

volatile int TimeCounterDown = 0;
volatile int TimeSecondDown = 60;
volatile int	TimeMinuteDown = 0;


int First_digit = 0;
int Second_digit = 0;
int Third_digit = 0;
int Fourth_digit = 0;

int Second_flag = 0;
int Minute_flag = 0;
int Hour_flag = 0;

int Units_digit = 0;
int Tens_digit = 0;
int Units_digit_min = 0;
int Tens_digit_min = 0;
int Units_digit_sec = 0;
int Tens_digit_sec = 0;
int Hundreds_digit = 0;
int Thousands_digit = 0;

code const unsigned char num_0[9] = {1, 1, 1, 1, 1, 1, 0, 0, 0};
code const unsigned char num_1[9] = {0, 1, 1, 0, 0, 0, 0, 0, 0};
code const unsigned char num_2[9] = {1, 1, 0, 1, 1, 0, 1, 0, 0};
code const unsigned char num_3[9] = {1, 1, 1, 1, 0, 0, 1, 0, 0};
code const unsigned char num_4[9] = {0, 1, 1, 0, 0, 1, 1, 0, 0};
code const unsigned char num_5[9] = {1, 0, 1, 1, 0, 1, 1, 0, 0};
code const unsigned char num_6[9] = {1, 0, 1, 1, 1, 1, 1, 0, 0};
code const unsigned char num_7[9] = {1, 1, 1, 0, 0, 0, 0, 0, 0};
code const unsigned char num_8[9] = {1, 1, 1, 1, 1, 1, 1, 0, 0};
code const unsigned char num_9[9] = {1, 1, 1, 1, 0, 1, 1, 0, 0};
code const unsigned char sym_k3_k4[9] = {0, 0, 0, 0, 0, 0, 0, 1, 0};
code const unsigned char sym_l1_l2_l3[9] = {0, 0, 0, 0, 0, 0, 0, 0, 1};

int FlagPoint = 0;
int SayacTime = 0;
int sayacTime_1sec = 0;
int sayacTimer = 0;
int FlagPointLong = 0;
int setClock_Flag = 0;
int elapsedTime = 0;
int displayNo = 0;
int counter_tens = 0;
int counter_unit = 0 ;
int CurrentTime2 = 0;
int Flag_Back_Count = 0;
int PreviousTime2 = 0;
int PreviousTime3 = 0;

int CurrentTime_Refresh = 0;
int Flag_Refresh = 0;
int PreviousTime_Refresh = 0;
int counter_down = 0;
int value_min = 0;
int value_sec = 0;

 int FlagCook = 0;
 int Buzzer_counter = 0;