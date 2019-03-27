/*
 * seven_seg.c
 *
 *  Created on: Mar 26, 2019
 *      Author: Yasmeen
 */
#include"stdtypes.h"
#include"seven_seg_cfg.h"
#include"seven_seg.h"
#include"avr/delay.h"
#include"dio.h"
//==================================================
extern void SEG_vidInit(void){
#if num_seven_seg==1
	DIO_vidSetPortDirection(port1,0xff);
#endif
#if num_seven_seg==2
	DIO_vidSetPortDirection(port1,0xff);
	DIO_vidSetPortDirection(port2,0xff);

#endif

}
//======================================================
extern void SEG_vidDisplayNumZeroNine(u8 port,u8 num){
	u8 arr[10]={0b0111111,0b0000110,0b1011011,0b1001111,0b1100110,0b1101101,0b1111101,
	0b0000111,0b1111111,0b1101111};


if( port==port1){
DIO_vidSetPortValue(port1,arr[num]);
}
#if num_seven_seg==2
if(port==port2){
	DIO_vidSetPortValue(port2,arr[num]);
}
#endif


}
//===============================================================
extern void SEG_vidDisplayNum(u8 num){
	SEG_vidDisplayNumZeroNine(port1,num%10);
#if num_seven_seg==2
	SEG_vidDisplayNumZeroNine(port2,num/10);
#endif

}
//=========================================================
extern void SEG_vidCountUp(u8 num){
	u8 i;
	for(i=0;i<=num;i++){
     SEG_vidDisplayNum(i);
	_delay_ms(1000);
}}
//===========================================================
extern void SEG_vidCountDown(u8 num){
	s8 i;
	for(i=num;i>=0;i--){
     SEG_vidDisplayNum(i);
	_delay_ms(1000);
}}
//============================================
