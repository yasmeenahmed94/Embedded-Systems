/*
 * LCD.h
 *
 *  Created on: Mar 27, 2019
 *      Author: Yasmeen
 */

#ifndef LCD_H_
#define LCD_H_
extern void LCD_vidInit(void);
extern void LCD_vidSendData(u8 character);
extern void LCD_vidSendCommand(u8 command);
extern void LCD_vidWriteString(u8 *str);
extern void LCD_vidDisplayNum(s32 num);
extern void LCD_vidSetCursorPosition(u8 row,u8 column);



#endif /* LCD_H_ */
