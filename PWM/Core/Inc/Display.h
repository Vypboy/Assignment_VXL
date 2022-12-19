#ifndef INC_DISPLAY_H_
#define INC_DISPLAY_H_

//=========================
//	FOR DISPLAY COLORFUL LEDS
//=========================

#include "main.h"
#include "global.h"
#include "Software_timer.h"

enum TypeLed {Red, Green, Yellow};

void Init();
void BlinkLed(enum TypeLed);

void Display_Init();
void Display_Led_Red1();
void Display_Led_Green1();
void Display_Led_Yellow1();

void Display_Led_Red2();
void Display_Led_Green2();
void Display_Led_Yellow2();

void Display_P_Led_Reset();
void Display_P_Led_Red1();
void Display_P_Led_Green1();



#endif /* INC_DISPLAY_H_ */
