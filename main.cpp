#include "main.h"

int testing_completeness_counter = 0;
int encoder_switch_debounce = 0;
int int_res_counter = 0;
char boot_tick_pass_cntr = 0;

volatile unsigned int counter_1s = 0;
volatile char tick_1s = 0;
double set_current = 0;//set current in Amperes
double measured_current = 0;

extern unsigned long t1;
extern unsigned long t2;
extern double v_open_circuit;
extern double v1,v2;
extern double i1,i2;
const int pwm_pin = 6;

char switch_Pressed = 0;

void set_pwm_frequency(void);
void set_current_on_hardware();
void timer_interrupt_10ms();

//*************************************************************
void setup()
{
  Timer1.initialize(10000);		  // initialize timer1, and set a 10 ms period
  Timer1.attachInterrupt(timer_interrupt_10ms);  // attaches callback() as a timer overflow interrupt
	  
  pinMode(buzzer_pin , OUTPUT);
               
  lcd.begin(16, 2);    
  lcd.setCursor(3, 0);
  lcd.print("1-CH Li-ion");
  
  lcd.setCursor(1, 1);
  lcd.print("battery tester");

  trigger_buzzer(14);
  
  Serial.begin(115200);
  
  lcd.createChar(1, happy);
  lcd.createChar(2, sad);
  lcd.createChar(3, cross);
  lcd.createChar(4, tick);

  analogReference(INTERNAL);//1.1V Vref
  analogWrite(pwm_pin, 0);
  pinMode(pwm_pin, OUTPUT); 
  set_pwm_frequency();
  set_current_on_hardware();
  t1 = millis();
  
  pinMode (encoderSwitchPin,INPUT_PULLUP);
  //attachInterrupt(digitalPinToInterrupt(encoderSwitchPin), encoderSwitchInterrupt, FALLING);
  
  load_from_eeprom();
   
  Serial.println(mas);
}



//***************10ms timer interrupt**************************  
void timer_interrupt_10ms()
{

   if(++counter_1s > 99)
   {
	counter_1s = 0;
	tick_1s = 1;
   }

   buzzer_handler();
}

  
//****************** loop ************************************
void loop()
{
  if(tick_1s)
  {
	  tick_1s = 0;
	  
	  if(boot_tick_pass_cntr == 0)
		  boot_tick_pass_cntr = 1;

	  else if(boot_tick_pass_cntr == 1)
	  {
	     boot_tick_pass_cntr = 2;
		 lcd.clear();
		}

	  else
	  {
	  calculateTime();

	  finite_state_machine();
	  button_handler();
	  }
  }
}



//*************************************************************
void set_current_on_hardware()
  {
      analogWrite(pwm_pin, set_current / 0.00404);
      Serial.println(set_current);
    }



//************************************************************
void set_pwm_frequency(void)
{
  //https://arduino-info.wikispaces.com/Arduino-PWM-Frequency
 //TCCR0B = TCCR0B & B11111000 | B00000001;    // set timer 0 divisor to     1 for PWM frequency of 62500.00 Hz
 //TCCR0B = TCCR0B & B11111000 | B00000010;    // set timer 0 divisor to     8 for PWM frequency of  7812.50 Hz
 //TCCR0B = TCCR0B & B11111000 | B00000011;    // set timer 0 divisor to    64 for PWM frequency of   976.56 Hz (The DEFAULT)
 //TCCR0B = TCCR0B & B11111000 | B00000100;    // set timer 0 divisor to   256 for PWM frequency of   244.14 Hz
 //TCCR0B = TCCR0B & B11111000 | B00000101;    // set timer 0 divisor to  1024 for PWM frequency of    61.04 Hz
  }
 

