#include "main.h"

double set_power = 0;
double measured_power = 0;
double voltage = 0;
double v_open_circuit = 0;
double v1,v2 = 0;
double i1,i2=0;
double int_resistance = 0;
volatile double mas = 0;//milli amperes seconds

//*************************************************************
void measure_current(void)
{
  measured_current = 0;
  for(int i=0;i<20;i++){
  measured_current = measured_current + analogRead(current_pin);
                      }
  measured_current = measured_current/20;
  measured_current = measured_current/927.778;//*0.0010778441558442;
  //Serial.print(measured_current);
  //Serial.println(" A");
}


//*************************************************************
void measure_voltage(void)
{
  voltage = 0;
  for(int i=0;i<20;i++){
  voltage = voltage + analogRead(voltage_pin);
                      }
  voltage = voltage/20;
  voltage = voltage/156.576;//*0.0063866488730724;
  
  #if VOLTAGE_COMPENSATION
  voltage += measured_current*STRAY_RESISTANCE;
  #endif
}


//*************************************************************
void calculate_mas()
{  
  mas += measured_current * 1000;//t2;
  }


//*************************************************************
void calculate_int_resistance(void)
{
  //int_resistance = (v_open_circuit - voltage)/measured_current;
  int_resistance = (v1 - v2) / (i2-i1); 
  Serial.print("R_int= ");
  Serial.println(int_resistance);
  }
