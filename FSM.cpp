#include "main.h"

int state = 0;

//*************************************************************  
void finite_state_machine()
{

	//state = TEST_COMPLETE;

  switch(state)
  {
    case INSERT_BATTERY:  
      measure_voltage();
      if(voltage <= 0.3)
        { 
          display_insert_battery();
          }
       
      else if(voltage>0.3 && voltage<3)
      {
        state = OVER_DISCHARGED; 
        }

      else
      {
        state = TESTING;
        t1 = millis();
        lcd.clear();
        lcd.setCursor(2, 0);
        lcd.print("Starting Test");
        delay(300);
        //int_res_counter = 0;
        set_current = BATT_TEST_CURRENT;
        set_current_on_hardware();
        }
        
    break;

    
    case INT_RESISTANCE:
        /*
        display_int_res_mode();
        measure_voltage();
        measure_current();
        display_voltage_on_lcd();
        display_measured_current_on_lcd();
        
        if(int_res_counter == 0)
        {
          v_open_circuit = voltage; 
          set_current = 0.5;
          set_current_on_hardware();
        }

        if(int_res_counter == 6)
        {
          
          v1 = voltage; 
          i1 = measured_current;
          set_current = 1;
          set_current_on_hardware();
        }
        
        if(int_res_counter == 12)
        {
          v2 = voltage; 
          i2 = measured_current;
          calculate_int_resistance();
          state = TESTING;
          set_current = BATT_TEST_CURRENT;
          set_current_on_hardware();
          lcd.clear();
          }
          
        int_res_counter++;
        */
     break;
        
    case TESTING:
      if(voltage>0 && voltage<=(BATT_LOW_VOLTAGE-0.05))
        {
          state = INSERT_BATTERY;
          set_current = 0;
          set_current_on_hardware();
          lcd.clear();
        }

        else if(voltage > BATT_LOW_VOLTAGE)
        {
         measure_voltage();
         measure_current();
  
         calculateTime();
         calculate_mas();
         save_to_eeprom();

  		 lcd.clear();
         display_mah_on_lcd();
         display_time_on_lcd();display_time_on_serial();
         display_voltage_on_lcd();
         display_measured_current_on_lcd();
          
        }
        
        
      else if( voltage>(BATT_LOW_VOLTAGE-0.1)  && voltage < BATT_LOW_VOLTAGE)
      {
        if(testing_completeness_counter++ == 5)
        {
        testing_completeness_counter = 0;
        state = TEST_COMPLETE;
        set_current = 0;
        set_current_on_hardware();
        lcd.clear();
        }
      } 
     break;    
         
    case TEST_COMPLETE:
        display_tick_symbol();
        measure_voltage();
        measure_current();
        display_mah_on_lcd();
        display_time_on_lcd();
        display_voltage_on_lcd();
        display_measured_current_on_lcd();

		//trigger_Buzzer();

        if(voltage == 0)
          {
          state = INSERT_BATTERY;
		  clear_Buzzer_State();
          //lcd.clear();
            } 
      
     break; 
      
    case OVER_DISCHARGED:
      measure_voltage();
      if(voltage == 0)
        {
          state = INSERT_BATTERY;
          lcd.clear();
          }
      else if(voltage>0 && voltage <3)
        {
        /*#define delayy 600
         digitalWrite(buzzer_pin, HIGH);
         delay(delayy);
         digitalWrite(buzzer_pin, LOW);
         delay(delayy);

         digitalWrite(buzzer_pin, HIGH);
         delay(delayy);
         digitalWrite(buzzer_pin, LOW);
         delay(delayy);

         digitalWrite(buzzer_pin, HIGH);
         delay(delayy);
         digitalWrite(buzzer_pin, LOW);
*/
          display_over_discharged();//same over discharged state
          display_voltage_on_lcd();
          set_current = 0;
          set_current_on_hardware();
        }
      else //if(voltage > 3)
        {
         state = TESTING;
         t1 = millis();
         set_current = BATT_TEST_CURRENT;
         set_current_on_hardware();
         lcd.clear();
          }
      
     break;
     
    }//end switch
  
  
 
}


