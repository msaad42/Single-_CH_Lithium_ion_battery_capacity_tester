#include "main.h"
int     eeprom_seconds_counter = 0;

//*************************************************************
void reset_eeprom_contents(void)
{
    EEPROM.put(MAS_ADDRESS, mas);
    EEPROM.put(MILLIS_ADDRESS, millis_elapsed); 
}


//*************************************************************
void save_to_eeprom(void)
{
  if(eeprom_seconds_counter++ == SECONDS_DELAY_TO_WRITE_TO_EEPROM)
  {
    EEPROM.put(MAS_ADDRESS, mas);
    EEPROM.put(MILLIS_ADDRESS, millis_elapsed);
    eeprom_seconds_counter = 0;
    }
}


//*************************************************************
void load_from_eeprom(void)
{
  EEPROM.get(MAS_ADDRESS,mas);
  EEPROM.get(MILLIS_ADDRESS, millis_elapsed);
  
  Serial.print("ee mas=");
  Serial.println(mas);
}


