/*
 * global.h
 *
 *  Created on: Oct 24, 2022
 *      Author: ADMIN
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "Software_timer.h"
#include "button.h"
#include "main.h"

#define INIT       	1
#define AUTO_RED  	2
#define AUTO_GREEN 	3
#define AUTO_YELLOW 4

#define MAN_RED	 	12
#define MAN_GREEN	13
#define MAN_YELLOW 	14

#define PEDESTRIAN_MODE 15

//thoi gian trang thai mode
#define MODE_TIME 	15000

extern int status_col;
extern int status_row;
extern int status_pad;
extern int flag_pad;
extern int cycle_pad;

extern int Time_Auto_Red;
extern int Time_Auto_Green;
extern int Time_Auto_Yellow;

extern int time_value;
void set_time_value(int duration);

void set_Time_Auto_Red(int duration);
void set_Time_Auto_Green(int duration);
void set_Time_Auto_Yellow(int duration);
void run_time_value();
#endif /* INC_GLOBAL_H_ */
