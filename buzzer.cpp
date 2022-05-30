#include "main.h"

int var_buz = 0;

volatile char buzzer_cntr = 0;

/*void trigger_Buzzer(void)
{
  if(buzzer_cntr > BUZZ_TIME)
  {
	 digitalWrite(buzzer_pin, LOW); 
	 return;
  }
  	
  var_buz^= 1;
  digitalWrite(buzzer_pin, var_buz);
  buzzer_cntr++;
}*/


//*************************************************************
void clear_Buzzer_State(void)
{
 digitalWrite(buzzer_pin, LOW);
 buzzer_cntr = 0;
}


/*****************************************************************************
call this function every 10ms i timer interrupt
*****************************************************************************/
void buzzer_handler()
{
  if(buzzer_cntr && --buzzer_cntr == 0)
  {
    BUZZER_OFF;
  }
}


/*****************************************************************************
call this function to turn on buzzing, buzzer handler will trun it off
after the required ON time
*****************************************************************************/
void trigger_buzzer(uint8_t t)
{
  if(buzzer_cntr == 0)//no previous buzz is going on
  {
    BUZZER_ON;
    buzzer_cntr = t;//1 means 10 ms
  }
}


