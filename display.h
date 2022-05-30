#ifndef DISPLAY_H
#define DISPLAY_H

extern LiquidCrystal lcd;
extern byte happy[8];
extern byte sad[8];
extern byte cross[8];
extern byte tick[8]; 

void display_voltage_on_lcd(void);
void display_set_current_on_lcd();
void display_measured_current_on_lcd();
void display_set_power_on_lcd();
void display_measured_power_on_lcd(void);
void display_mah_on_lcd();
void display_time_on_lcd();
void display_insert_battery(void);
void display_tick_symbol(void);
void display_over_discharged(void);
void display_int_res_mode(void);

#endif

