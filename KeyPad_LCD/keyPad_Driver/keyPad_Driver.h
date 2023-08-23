/*
 * keyPad_Driver.h
 *
 *  Created on: Aug 18, 2023
 *      Author: hanyt
 */

#ifndef KEYPAD_DRIVER_KEYPAD_DRIVER_H_
#define KEYPAD_DRIVER_KEYPAD_DRIVER_H_

#include "Tiva_DIO/Tiva_DIO.h"

#define R_PORT    PORTE
#define C_PORT    PORTB

#define KP_R1     PIN0
#define KP_R2     PIN1
#define KP_R3     PIN2
#define KP_R4     PIN3

#define KP_C1     PIN0
#define KP_C2     PIN1
#define KP_C3     PIN2
#define KP_C4     PIN3

#define DEFAULT_K 'H'


extern unsigned  char symbol[4][4];

void KeyPad_Init_NoINT(void);
char KeyPad_Read_NoINT(void);

void KeyPad_Init_INT(void);
void KeyPad_Read_INT(void);

#endif /* KEYPAD_DRIVER_KEYPAD_DRIVER_H_ */
