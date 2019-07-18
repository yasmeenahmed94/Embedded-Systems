/*
 * main.c
 *
 *  Created on: Jul 17, 2019
 *      Author: Yasmeen
 * ***Design a system with these constrains:
1. RED LED blinks every 1ms.
2. Yellow LED blinks every 2ms.
3. Green LED blinks every 5ms.

 */
#include"registers.h"
#include"stdtypes.h"
#include"utilss.h"
#include"timer.h"
#include"dio.h"

//************************************
#define no_tasks 3
#define no_tasks 3
extern u32 count_tick;
typedef struct{
	u8 periodic;
	void(*fptr)(void);

}task;
task arr[no_tasks] ;
//---------------------------------------
void create_task(void(*fptr)(void),u8 periodic,u8 piriority){
arr[piriority].periodic=periodic;
arr[piriority].fptr=fptr;
}
//=**********************************
void scheduler(void){
	u8 i;
	for(i=0;i<no_tasks;i++){
		if(count_tick %(arr[i].periodic)==0){
			arr[i].fptr();

		}


	}

}
//======================================
void task1 (void){
	toggle_bit(PORTA,0);
}
//--------------------------------------
void task2(void){
	toggle_bit(PORTA,1);
}
//----------------------------------------
void task3(void){
	toggle_bit(PORTA,2);
}
//=======================================


int main(void){
	DIO_vidSetPinDirection(A,0,Output);
	DIO_vidSetPinDirection(A,1,Output);
	DIO_vidSetPinDirection(A,2,Output);

	//DIO_vidSetPinValue(A,0,High);
	//DIO_vidSetPinValue(A,1,High);
	//DIO_vidSetPinValue(A,2,High);

	Timer_Init();
	set_scheduler_callback(scheduler);

	create_task(task1,1,0);
	create_task(task2,2,1);
	create_task(task3,5,2);



while(1){


}






return 0;
}
