/*
 * LCD.c

 *
 *  Created on: Mar 27, 2019
 *      Author: Yasmeen
 */
#include"avr/delay.h"
#include"stdtypes.h"
#include"utilss.h"
#include"dio.h"
#include"LCD_M.h"
#include"LCD.h"



//=========================================================
extern void LCD_vidInit(void){
#if eight_bit ==Enable
	DIO_vidSetPinDirection(control_port,RSpin,Output);
	DIO_vidSetPinDirection(control_port,RWpin,Output);
	DIO_vidSetPinDirection(control_port,ENpin,Output);
	DIO_vidSetPortDirection(data_port,0xff);
	_delay_ms(35);
	LCD_SendCommand(func_set);
	_delay_ms(2);
	LCD_SendCommand(display);
	_delay_ms(2);
	LCD_SendCommand(clear);
	_delay_ms(2);
	LCD_SendCommand(entrymode);
		_delay_ms(2);


#endif
//------------------------------------------------------------
#if four_bit==Enable
 DIO_vidSetPinDirection(D7,Output);
 DIO_vidSetPinDirection(D6,Output);
 DIO_vidSetPinDirection(D5,Output);
 DIO_vidSetPinDirection(D4,Output);
 DIO_vidSetPinDirection(RS,Output);
 DIO_vidSetPinDirection(EN,Output);
 //--------------------------------------------------------------
    _delay_ms(35);
    LCD_vidSendCommand(0x33);

	LCD_vidSendCommand(0x32);

	LCD_vidSendCommand(0x28);//two line

	LCD_vidSendCommand(0x0e);

	LCD_vidSendCommand(0x01);

	LCD_vidSendCommand(0x06);

#endif

}

//=========================================================
extern void LCD_vidSendCommand(u8 command){// send command to LCD
#if eight_bit==Enable
	//clear RSpin
	DIO_vidSetPinValue(control_port,RSpin,Low);
	//clear RWpin
	DIO_vidSetPinValue(control_port,RWpin,Low);
	//send command
	DIO_vidSetPortValue(data_port,command);
	//set ENpin
	DIO_vidSetPinValue(control_port,ENpin,High);
	_delay_ms(5);
	//clear ENpin
	DIO_vidSetPinValue(control_port,ENpin,Low);
#endif
	//----------------------------------------------
#if four_bit==Enable
	u8 high_command=get_high_nibble(command);
	u8 low_command=get_low_nibble(command);

	   //clear RSpin
		DIO_vidSetPinValue(RS,Low);
		//send high nibble of command first
		DIO_vidSetPinValue(D4,high_command%2);
		high_command>>=1;
		DIO_vidSetPinValue(D5,high_command%2);
		high_command>>=1;
		DIO_vidSetPinValue(D6,high_command%2);
		high_command>>=1;
		DIO_vidSetPinValue(D7,high_command%2);

		//set ENpin
		DIO_vidSetPinValue(EN,High);
		_delay_ms(5);
		//clear ENpin
		DIO_vidSetPinValue(EN,Low);
//-----------------------------------------------------

		//clear RSpin
		DIO_vidSetPinValue(RS,Low);
		// send low nibble of command
		DIO_vidSetPinValue(D4,low_command%2);
		low_command>>=1;
		DIO_vidSetPinValue(D5,low_command%2);
		low_command>>=1;
		DIO_vidSetPinValue(D6,low_command%2);
		low_command>>=1;
		DIO_vidSetPinValue(D7,low_command%2);

		//set ENpin
		DIO_vidSetPinValue(EN,High);
		_delay_ms(5);
		//clear ENpin
		DIO_vidSetPinValue(EN,Low);

#endif
}
//=========================================================
extern void LCD_vidSendData(u8 character){//write data on LCD
#if eight_bit==Enable
	// set RSpin
	DIO_vidSetPinValue(control_port,RSpin,High);
	//clear RWpin
	DIO_vidSetPinValue(control_port,RWpin,Low);
	//send data
	DIO_vidSetPortValue(data_port,character);
	//set ENpin
	DIO_vidSetPinValue(control_port,ENpin,High);
	_delay_ms(5);
	//clear ENpin
	DIO_vidSetPinValue(control_port,ENpin,Low);
#endif
	//----------------------------------------------
	//----------------------------------------------
#if four_bit==Enable
	u8 low_char=get_low_nibble(character);
	u8 high_char=get_high_nibble(character);
	    // set RSpin
		DIO_vidSetPinValue(RS,High);
		//send high nibble of data first
		DIO_vidSetPinValue(D4,high_char%2);
		high_char>>=1;
		DIO_vidSetPinValue(D5,high_char%2);
		high_char>>=1;
		DIO_vidSetPinValue(D6,high_char%2);
		high_char>>=1;
		DIO_vidSetPinValue(D7,high_char%2);
		//set ENpin
		DIO_vidSetPinValue(EN,High);
		_delay_ms(5);
		//clear ENpin
		DIO_vidSetPinValue(EN,Low);

//----------------------------------------------------
       // set RSpin
		DIO_vidSetPinValue(RS,High);
		//send low nibble of data
		DIO_vidSetPinValue(D4,low_char%2);
		low_char>>=1;
		DIO_vidSetPinValue(D5,low_char%2);
		low_char>>=1;
		DIO_vidSetPinValue(D6,low_char%2);
		low_char>>=1;
		DIO_vidSetPinValue(D7,low_char%2);
		//set ENpin
		DIO_vidSetPinValue(EN,High);
		_delay_ms(5);
		//clear ENpin
		DIO_vidSetPinValue(EN,Low);

#endif

}
//=========================================================
extern void LCD_vidWriteString(u8 *str){
u8 i=0;
while(*(str+i)!='\0'){
	LCD_vidSendData(*(str+i));
	i++;

}
}
//=========================================================
extern void LCD_vidDisplayNum(s32 num){
	if (num<0){
		LCD_vidSendData('-');
		num=num*(-1);
	}
	if (num==0){
			LCD_vidSendData('0');
		}

	u32 reverse=0;
	u8 flag=0,counter=0;
	while((num!=0)){
		if(flag==0 && num%10==0){
			counter++;
			num=num/10;
		}

	else{
		flag=1;
		reverse=reverse*10;
		reverse=reverse+num%10;
		num=num/10;

	}
	}
	while((reverse!=0)){
		LCD_vidSendData((reverse%10)+48);
			reverse=reverse/10;
	}
		while(counter>0){
			 LCD_vidSendData(48);
			 counter--;
			}

	}

//============================================
extern void LCD_vidSetCursorPosition(u8 row,u8 column){
	//DDRAM address is 0x80
	//address first char in first row 0x00
	//address first char in second row 0x40
	if(row==1){
		LCD_vidSendCommand(0x80+0x00+column);
	}
	else if(row==2){
		LCD_vidSendCommand(0x80+0x40+column);
	}
}
//============================================
//============================================

