/*
 * Tiva_DIO.h
 *
 *  Created on: Aug 13, 2023
 *      Author: hanyt
 */

#ifndef TIVA_DIO_TIVA_DIO_H_
#define TIVA_DIO_TIVA_DIO_H_

#include "bitwseOperations.h"
#include "tm4c123gh6pm.h"


typedef enum
{
    PORTA=1,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF,
    PORTS_NUM
}PORT_Name_Type;

typedef enum{
    OUTPUT,
    INFREE,
    INLLUP
}DIO_PinStatus_type;

typedef enum
{
    LOW =0,
    HIGH
}Output_Value_Type;


typedef enum{
    PIN0=0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    TOTAL_PINS
}DIO_Pin_type;

typedef enum
{
    LOW_EDGE =0,
    HIGH_EDGE
}Int_Edge_Type;




///////////////// DATA_BITS REGISTER /////////////////////

void WriteDataBIT(PORT_Name_Type port, unsigned char bit);

void WriteDataBITS(PORT_Name_Type port, unsigned char bits, unsigned char value);

void ClearDataBIT(PORT_Name_Type port, unsigned char bit);

unsigned char ReadDataBIT(PORT_Name_Type port, unsigned char bit);



///////////////////// GPIO_PORTS /////////////////////////

void DIO_InitPin(PORT_Name_Type Port, DIO_Pin_type pin_num ,DIO_PinStatus_type status);

void DIO_WritePin(PORT_Name_Type Port, DIO_Pin_type pin_num, Output_Value_Type value);
Output_Value_Type DIO_ReadPin(PORT_Name_Type Port, DIO_Pin_type pin_num);
void DIO_TogglePin(PORT_Name_Type Port, DIO_Pin_type pin_num);
void PORT_Init(PORT_Name_Type port);
void DIO_WritePort(PORT_Name_Type Port, unsigned char value);
unsigned char DIO_ReadPort(PORT_Name_Type port);

//void DIO_Init(void);
//extern const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS];

/////////////////// INTERRUPT_PORTS ///////////////////////

void Inteupt_Edge_InitPin(PORT_Name_Type Port, DIO_Pin_type pin_num, Int_Edge_Type edge);



#endif /* TIVA_DIO_TIVA_DIO_H_ */
