#ifndef CONFIG_H
#define CONFIG_H

#define COUNTERS_RESET_SECONDS 2000

#define VOLTAGE_COMPENSATION 1
#define STRAY_RESISTANCE 0.1132//0.070//0.2285

#define BATT_TEST_CURRENT 0.50
#define BATT_LOW_VOLTAGE 3.0f

//Buzzer config
#define buzzer_pin 5
#define BUZZ_TIME  60

//rotary encoder config
#define encoderSwitchPin 3

//ADC pins
#define voltage_pin A0
#define current_pin A1

//EEPROM config
#define MAS_ADDRESS 0
#define MILLIS_ADDRESS 7
#define SECONDS_DELAY_TO_WRITE_TO_EEPROM 650  //>10 min

#endif

