/*
 * main.c
 *
 *  Created on: Mar 26, 2019
 *      Author: Yasmeen
 */
#include"stdtypes.h"
#include"utilss.h"
#include"dio.h"
#include"keypad.h"
#include"LCD.h"

#include "stepper.h"
/********************************************


*********************************************/

int main(void){


STEPPER_vidInit();


while(1){
u8 i;
for(i=0;i<254;i++){
	STEPPER_vidCW();
}


for(i=0;i<254;i++){
	STEPPER_vidCCW();
}

}
return 0;
}

