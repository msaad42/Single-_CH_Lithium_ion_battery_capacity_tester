#include "main.h"

unsigned long t1 = 0;
unsigned long t2 = 0;
unsigned long millis_elapsed = 0;
extern double measured_current;
struct _time _time;

//*************************************************************
void calculateTime(){
  
    
  t2 = millis()-t1;
  t1 = millis();
       Serial.print("t="); Serial.println(t2);
  if(measured_current != 0)
   millis_elapsed = millis_elapsed + t2;
    //Serial.println(millis());
     //Serial.println(millis_elapsed);
  _time.s = millis_elapsed/1000; 
  _time.m = _time.s/60;
  _time.s = _time.s%60;  
  _time.h = _time.m/60;
  _time.m = _time.m%60;
}


//*************************************************************
void display_time_on_serial(){
  Serial.print("Time: "); 
  Serial.print(_time.h); 
  Serial.print(":");
  Serial.print(_time.m); 
  Serial.print(":");
  Serial.println(_time.s); 
}

