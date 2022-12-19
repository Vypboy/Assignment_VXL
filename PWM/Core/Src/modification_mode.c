
#include "modification_mode.h"



void modification_mode(){
	//cap nhat cac gia tri Time_Auto_... khi nhan button2
	switch(status_col){
		case MAN_RED:
			//nhan button2 de tang gia tri Time_Auto_Red (1->99)
			if(isButtonPressed(1)==1){
				Time_Auto_Red = (Time_Auto_Red+1000)%100000;//ms
				set_Time_Auto_Red(Time_Auto_Red);
				set_time_value(Time_Auto_Red);
			}
			break;

		case MAN_GREEN:
			if(isButtonPressed(1)==1){
				Time_Auto_Green = (Time_Auto_Green+1000)%100000;//ms
				set_Time_Auto_Green(Time_Auto_Green);
				set_time_value(Time_Auto_Green);
			}
			break;

		case MAN_YELLOW:
			if(isButtonPressed(1)==1){
				Time_Auto_Yellow = (Time_Auto_Yellow+1000)%100000;//ms
				set_Time_Auto_Yellow(Time_Auto_Yellow);
				set_time_value(Time_Auto_Yellow);
			}
			break;
		default:
			break;
	}
	//nhan button3 de ket thuc mode va reset lại hệ thống
	if(isButtonPressed(2)==1){
		Init();
	}
}
