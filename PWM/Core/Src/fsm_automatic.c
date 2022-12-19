#include "fsm_automatic.h"


void press_ped_lag(){
	flag_pad=1;
	cycle_pad = 0;
}
void reset_pad_led(){
	flag_pad=0;
	cycle_pad=0;
	Display_P_Led_Reset();
}

int x=190;
void fsm_automatic_run(){
	//quan ly den tin hieu hang doc
	switch(status_col){

		case INIT:
			Display_Init();
			//chuyen trang thai ko dk
			status_col=AUTO_RED;
			setTimerCol(Time_Auto_Red);
			//dat gia tri bien dem time_value de hien thi tren terminal
//			set_time_value(Time_Auto_Red);
			break;
		case AUTO_RED:
			Display_Led_Red1();

			//chuyen trang thai co dk
			if(timerCol_flag==1){
				status_col=AUTO_GREEN;
				setTimerCol(Time_Auto_Green);
//				//dat gia tri bien dem time_value de hien thi tren terminal
//				set_time_value(Time_Auto_Green);
			}
			//trang thai mode 2
			if(isButtonPressed(0)==1){
				status_col=MAN_RED;
				status_row=MAN_RED;
				setTimerCol(MODE_TIME);
			}
			if(isButtonPressed(3)==1){
				press_ped_lag();
			}
			break;
		case AUTO_GREEN:
			Display_Led_Green1();

			//chuyen trang thai co dk
			if(timerCol_flag==1){
				status_col=AUTO_YELLOW;
				setTimerCol(Time_Auto_Yellow);
//				//dat gia tri bien dem time_value de hien thi tren terminal
//				set_time_value(Time_Auto_Yellow);
			}
			if(isButtonPressed(0)==1){
				status_col=MAN_GREEN;
				status_row=MAN_GREEN;
				setTimerCol(MODE_TIME);
			}
			if(isButtonPressed(3)==1){
				press_ped_lag();
			}
			break;
		case AUTO_YELLOW:
			Display_Led_Yellow1();

			//chuyen trang thai co dk
			if(timerCol_flag==1){
				status_col=AUTO_RED;
				setTimerCol(Time_Auto_Red);
//				set_time_value(Time_Auto_Red);
			}
			if(isButtonPressed(0)==1){
				status_col=MAN_YELLOW;
				status_row=MAN_YELLOW;

				setTimerCol(MODE_TIME);
			}
			if(isButtonPressed(3)==1){
				press_ped_lag();
			}
			break;
//		case PEDESTRIAN_MODE:
//			Buzzer();
//			if(timerCol_flag==1){
//				if(timerCol_flag==1){
//					status_col=INIT;
//					status_row=INIT;
//				}
//			}
//			break;
		default:
			break;
	}
///////////////////////////////////////////////////////////////////////
	//quan ly den tin hieu hang ngang
	switch(status_row){
		case INIT:
			Display_Init();

			//chuyen trang thai ko dk
			status_row=AUTO_GREEN;
			setTimerRow(Time_Auto_Green);
			//dat gia tri bien dem time_value de hien thi tren terminal
			set_time_value(Time_Auto_Red);
			break;
		case AUTO_RED:
			if(flag_pad==1) Display_P_Led_Red1();
			Display_Led_Red2();
			Buzzer_Off();
			//chuyen trang thai co dk
			if(timerRow_flag==1){
				status_row=AUTO_GREEN;
				setTimerRow(Time_Auto_Green);
				setTimerBuzzer(10);
				//dat gia tri bien dem time_value de hien thi tren terminal
				set_time_value(Time_Auto_Green);
			}
			break;
		case AUTO_GREEN:
			if(flag_pad==1) {
				Display_P_Led_Green1();
				//thuc hien buzzer
				if (timerBuzzer_flag == 1){
					float per = (float)(time_value / Time_Auto_Green);
					setTimerBuzzer((int)(Time_Auto_Green * per));
//					Buzzer(200 - (int)(190 * (1 - per)));
//					Buzzer(200 - 190*time_value / Time_Auto_Green);
					Buzzer(200 - x);
//					Buzzer(100);
				}
				Buzzer(200 - x);

				if(timer3_flag==1){
					setTimer3(1000);
//					if(time_value>=0) time_value-=1000;
//					else set_time_value(Time_Auto_Green);
					if(x>0) x-= 190/(Time_Auto_Green/1000);
					else x=190;
				}
			}
			Display_Led_Green2();

			//chuyen trang thai co dk
			if(timerRow_flag==1){
				if (cycle_pad >= 1){
					reset_pad_led();//tat den cho nguoi di duong
				}
				else cycle_pad++;
				status_row=AUTO_YELLOW;
				setTimerRow(Time_Auto_Yellow);
				//dat gia tri bien dem time_value de hien thi tren terminal
				set_time_value(Time_Auto_Yellow);
			}
			break;
		case AUTO_YELLOW:
			Display_Led_Yellow2();
			if(flag_pad==1) Display_P_Led_Red1();
			Buzzer_Off();
			//chuyen trang thai co dk
			if(timerRow_flag==1){
				status_row=AUTO_RED;
				setTimerRow(Time_Auto_Red);
				set_time_value(Time_Auto_Red);
			}
			break;
		default:
			break;
	}

	///////////////////////////////////////////////////////////////////


}

