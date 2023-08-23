/*
 * DIO.c
 *
 *  Created on: Aug 13, 2023
 *      Author: EUI-Support
 */
#include "DIO.h"
#include "bitwise_operation.h"
#include "tm4c123gh6pm.h"
#define  PORTA_CLOCK  0x00000001
#define  PORTB_CLOCK  0x00000002
#define  PORTC_CLOCK  0x00000004
#define  PORTD_CLOCK  0x00000008
#define  PORTE_CLOCK  0x00000010
#define  PORTF_CLOCK  0x00000020

void DIO_Init(Ports ports,int outputPin , int inputPin){
    switch(ports){
    case 1 :
        SYSCTL_RCGCGPIO_R |= PORTA_CLOCK ; /* Enable PORTA Clock*/
        while(Get_Bit(SYSCTL_RCGCGPIO_R,PORTA_CLOCK)){}; /*waiting till the clock is activated*/
        Set_Bit(GPIO_PORTA_DIR_R,outputPin); /* Set the Direction of the outputPins*/
        Set_Bit(GPIO_PORTA_DEN_R,outputPin);/* Enabling the output pin*/
        Clear_Bit(GPIO_PORTA_DIR_R,inputPin);/* Set the Direction of the InputPins*/
        Clear_Bit(GPIO_PORTA_DEN_R,inputPin);/* Set the Direction of the InputPins*/
        break;
    }
}


