#include "main.h"

#define UNPRESSED 0
#define PRESSED 1

char btn_press_cntr = 0;
char btn_unpress_cntr = 0;
char btn_state = UNPRESSED;


//*************************************************************
void encoderSwitchInterrupt(void)
{
  /*
  detachInterrupt(digitalPinToInterrupt(encoderSwitchPin));
  Serial.println("entered");
  et1= millis();
  while(digitalRead(encoderSwitchPin)==0);
  et2=millis();
  if(et2 - et1 == 4000)
     Serial.println("4s");

     attachInterrupt(digitalPinToInterrupt(encoderSwitchPin), encoderSwitchInterrupt, FALLING);
  
  if(encoder_switch_debounce++ == 4)
  {
    mas = 0;
    millis_elapsed = 0;
    reset_eeprom_contents();
    Serial.println("Reset");
    state = INSERT_BATTERY;
    lcd.clear();
    }
    */
  }


//*************************************************************
void button_handler()
{
if(digitalRead(encoderSwitchPin) == 0)
{ 	
    Serial.println("low");
	if(btn_state == UNPRESSED)
	{

	   lcd.setCursor(7, 1);
	   lcd.print('\3');//display cross symbol upon button press
	   
		if(++btn_press_cntr > 2)  
		{
		    btn_state = PRESSED;
			btn_press_cntr = 0;
			btn_unpress_cntr = 0;
		    mas = 0;
		    millis_elapsed = 0;
		    reset_eeprom_contents();
		    state = INSERT_BATTERY;
		    clear_Buzzer_State();
		    Serial.println("Reset");
		    lcd.clear();
		    lcd.setCursor(5, 0);
		    lcd.print("Reset");
		    delay(1000);
	    }
	    
    }
}
 else
	btn_press_cntr = 0;
		
  if(digitalRead(encoderSwitchPin) == 1)
   {
    if(btn_state == PRESSED)
	{
		if(++btn_unpress_cntr > 1) 
		{
			btn_state = UNPRESSED;
			btn_unpress_cntr = 0;
			btn_press_cntr = 0;
		}
		
	}  
  }
  else
		btn_unpress_cntr = 0;
}

