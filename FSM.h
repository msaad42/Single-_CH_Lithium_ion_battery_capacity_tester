#ifndef FSM_H
#define FSM_H

#define INSERT_BATTERY  0
#define INT_RESISTANCE  1
#define TESTING         2
#define TEST_COMPLETE   3
#define OVER_DISCHARGED 4

extern int state;

void finite_state_machine();

#endif

