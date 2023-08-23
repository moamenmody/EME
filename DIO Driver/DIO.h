/*
 * DIO.h
 *
 *  Created on: Aug 13, 2023
 *      Author: EUI-Support
 */

#ifndef DIO_H_
#define DIO_H_
#include <stdio.h>

/***********************************
 *          Data Types
 ***********************************/
typedef enum{
    PORTA = 1 , PORTB = 2 , PORTC = 3 , PORTD = 4,
    PORTE = 5 , PORTF = 6
}Ports;


typedef enum {
    LOW = 0,
    HIGH = 1
}State;





/***********************************
         Function Prototypes
 **********************************/
void DIO_Init(Ports ports,int outPins , int inputPins);
void DIO_WritePin();
void DIO_WritePort();




#endif /* DIO_H_ */
