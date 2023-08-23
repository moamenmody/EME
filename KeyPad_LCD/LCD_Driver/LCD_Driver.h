/*
 * LCD_Driver.h
 *
 *  Created on: Aug 18, 2023
 *      Author: hanyt
 */

#ifndef LCD_DRIVER_LCD_DRIVER_H_
#define LCD_DRIVER_LCD_DRIVER_H_

#include "../Tiva_DIO/Tiva_DIO.h"

#define   _4_BIT  0
#define   _8_BIT  1


#define   LCD_MODE    _8_BIT

/*for 8 bit mode*******/
//#define   LCD_PORT     PD
/*for 4 bit mode*******/

#define   D0     PORTE, PIN4
#define   D1     PORTE, PIN5
#define   D2     PORTA, PIN2
#define   D3     PORTA, PIN3
#define   D4     PORTA, PIN4
#define   D5     PORTA, PIN5
#define   D6     PORTA, PIN6
#define   D7     PORTA, PIN7


#define   RS     PORTF, PIN4
#define   RW     PORTF, PIN2
#define   EN     PORTB, PIN4



/****************************************************/
void LCD_Init(void);
void LCD_Clear(void);
void LCD_WriteChar(unsigned char ch);
void LCD_WriteString(unsigned char*str);
void LCD_WriteNumber(long long num);
void LCD_SetCursor(unsigned char Line, unsigned char x);
void LCD_WriteNumberInBinary(unsigned char num);
void LCD_WriteNumber_4D(unsigned short int num);


#endif /* LCD_DRIVER_LCD_DRIVER_H_ */
