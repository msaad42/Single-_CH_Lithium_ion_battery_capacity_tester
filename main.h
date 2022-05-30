#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>
#include "buzzer.h"
#include "config.h"
#include "display.h"
#include "eeprom.h"
#include "FSM.h"
#include "measurement.h"
#include "rotary_encoder.h"
#include "_time.h"
#include "TimerOne.h"

extern double set_current;//set current in Amperes

extern char switch_Pressed;

extern int testing_completeness_counter;


void set_current_on_hardware();

#endif

