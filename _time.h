#ifndef _TIME_H
#define _TIME_H

struct _time 
{
  unsigned long int h,m,s;
  };

extern unsigned long t1;
extern unsigned long t2;
extern unsigned long millis_elapsed;
extern struct _time _time;

void calculateTime(void);
void display_time_on_lcd(void);
void display_time_on_serial();


  


#endif

