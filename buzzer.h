#ifndef BUZZER_H
#define BUZZER_H

#define BUZZER_ON digitalWrite(buzzer_pin, HIGH);
#define BUZZER_OFF digitalWrite(buzzer_pin, LOW);

void trigger_buzzer(uint8_t);
void clear_Buzzer_State(void);
void buzzer_handler();


#endif

