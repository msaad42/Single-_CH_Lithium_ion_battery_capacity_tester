#ifndef MEASUREMENT_H
#define MEASUREMENT_H

extern double voltage;
extern volatile double mas;//milli amperes seconds
extern double voltage;
extern double set_current;
extern double measured_current;
extern double set_power;
extern double measured_power;


void measure_current(void);
void measure_voltage(void);
void calculate_mas();
void calculate_int_resistance(void);

#endif

