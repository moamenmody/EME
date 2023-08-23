/*
 * Tiva_DIO.c
 *
 *  Created on: Aug 13, 2023
 *      Author: hanyt
 */

#include "Tiva_DIO.h"


///////////////// DATA_BITS REGISTER /////////////////////

void WriteDataBIT(PORT_Name_Type port, unsigned char bit)
{
    switch (port) {
        case PORTA:
            GPIO_PORTA_DATA_BITS_R[1<<bit] = 1<<bit;
            break;
        case PORTB:
            GPIO_PORTB_DATA_BITS_R[1<<bit] = 1<<bit;
            break;
        case PORTC:
            GPIO_PORTC_DATA_BITS_R[1<<bit] = 1<<bit;
            break;
        case PORTD:
            GPIO_PORTD_DATA_BITS_R[1<<bit] = 1<<bit;
            break;
        case PORTE:
            GPIO_PORTE_DATA_BITS_R[1<<bit] = 1<<bit;
            break;
        case PORTF:
            GPIO_PORTF_DATA_BITS_R[1<<bit] = 1<<bit;
            break;
        default:
            break;
    }
}


void WriteDataBITS(PORT_Name_Type port, unsigned char bits, unsigned char value)
{
    switch (port) {
        case PORTA:
            GPIO_PORTA_DATA_BITS_R[bits] = value;
            break;
        case PORTB:
            GPIO_PORTB_DATA_BITS_R[bits] = value;
            break;
        case PORTC:
            GPIO_PORTC_DATA_BITS_R[bits] = value;
            break;
        case PORTD:
            GPIO_PORTD_DATA_BITS_R[bits] = value;
            break;
        case PORTE:
            GPIO_PORTE_DATA_BITS_R[bits] = value;
            break;
        case PORTF:
            GPIO_PORTF_DATA_BITS_R[bits] = value;
            break;
        default:
            break;
    }
}

void ClearDataBIT(PORT_Name_Type port, unsigned char bit)
{
    switch (port) {
        case PORTA:
            GPIO_PORTA_DATA_BITS_R[1<<bit] = 0;
            break;
        case PORTB:
            GPIO_PORTB_DATA_BITS_R[1<<bit] = 0;
            break;
        case PORTC:
            GPIO_PORTC_DATA_BITS_R[1<<bit] = 0;
            break;
        case PORTD:
            GPIO_PORTD_DATA_BITS_R[1<<bit] = 0;
            break;
        case PORTE:
            GPIO_PORTE_DATA_BITS_R[1<<bit] = 0;
            break;
        case PORTF:
            GPIO_PORTF_DATA_BITS_R[1<<bit] = 0;
            break;
        default:
            break;
    }
}

unsigned char ReadDataBIT(PORT_Name_Type port, unsigned char bit)
{
    unsigned char readBit = 0;
    switch (port) {
        case PORTA:
            readBit = GPIO_PORTA_DATA_BITS_R[1<<bit];
            break;
        case PORTB:
            readBit = GPIO_PORTB_DATA_BITS_R[1<<bit];
            break;
        case PORTC:
            readBit = GPIO_PORTC_DATA_BITS_R[1<<bit];
            break;
        case PORTD:
            readBit = GPIO_PORTD_DATA_BITS_R[1<<bit];
            break;
        case PORTE:
            readBit = GPIO_PORTE_DATA_BITS_R[1<<bit];
            break;
        case PORTF:
            readBit = GPIO_PORTF_DATA_BITS_R[1<<bit];
            break;
        default:
            break;
    }
    return readBit;
}


///////////////////// GPIO_PORTS /////////////////////////
void PORT_Init(PORT_Name_Type port)
{
    switch (port) {
        case PORTA:
            SYSCTL_RCGCGPIO_R |= 0x00000001;
            while(SYSCTL_RCGCGPIO_R & 0x00000001 == 0);
            GPIO_PORTA_LOCK_R = 0x4C4F434B;
            GPIO_PORTA_CR_R = 0xFF;
            break;
        case PORTB:
            SYSCTL_RCGCGPIO_R |= 0x00000002;
            while(SYSCTL_RCGCGPIO_R & 0x00000002 == 0);
            GPIO_PORTB_LOCK_R = 0x4C4F434B;
            GPIO_PORTB_CR_R = 0xFF;
            break;
        case PORTC:
            SYSCTL_RCGCGPIO_R |= 0x00000004;
            while(SYSCTL_RCGCGPIO_R & 0x00000004 == 0);
            GPIO_PORTC_LOCK_R = 0x4C4F434B;
            GPIO_PORTC_CR_R = 0xFF;
            break;
        case PORTD:
            SYSCTL_RCGCGPIO_R |= 0x00000008;
            while(SYSCTL_RCGCGPIO_R & 0x00000008 == 0);
            GPIO_PORTD_LOCK_R = 0x4C4F434B;
            GPIO_PORTD_CR_R = 0xFF;
            break;
        case PORTE:
            SYSCTL_RCGCGPIO_R |= 0x00000010;
            while(SYSCTL_RCGCGPIO_R & 0x00000010 == 0);
            GPIO_PORTE_LOCK_R = 0x4C4F434B;
            GPIO_PORTE_CR_R = 0xFF;
            break;
        case PORTF:
            SYSCTL_RCGCGPIO_R |= 0x00000020;
            while(SYSCTL_RCGCGPIO_R & 0x00000020 == 0);
            GPIO_PORTF_LOCK_R = 0x4C4F434B;
            GPIO_PORTF_CR_R = 0xFF;
            break;
        default:
            break;
    }
}

//////////////////
void DIO_InitPin(PORT_Name_Type Port, DIO_Pin_type pin_num ,DIO_PinStatus_type status)
{
    switch (status)
    {
        case OUTPUT:
        switch (Port)
        {
            case PORTA:
                INSERT_BIT(GPIO_PORTA_DIR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTA_DEN_R, pin_num, 1);
                break;
            case PORTB:
                INSERT_BIT(GPIO_PORTB_DIR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTB_DEN_R, pin_num, 1);
                break;
            case PORTC:
                INSERT_BIT(GPIO_PORTC_DIR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTC_DEN_R, pin_num, 1);
                break;
            case PORTD:
                INSERT_BIT(GPIO_PORTD_DIR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTD_DEN_R, pin_num, 1);
                break;
            case PORTE:
                INSERT_BIT(GPIO_PORTE_DIR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTE_DEN_R, pin_num, 1);
                break;
            case PORTF:
                INSERT_BIT(GPIO_PORTF_DIR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTF_DEN_R, pin_num, 1);
                break;
        }
        break;
        case INFREE:
        switch (Port)
        {
            case PORTA:
                INSERT_BIT(GPIO_PORTA_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTA_DEN_R, pin_num, 1);
                break;
            case PORTB:
                INSERT_BIT(GPIO_PORTB_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTB_DEN_R, pin_num, 1);
                break;
            case PORTC:
                INSERT_BIT(GPIO_PORTC_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTC_DEN_R, pin_num, 1);
                break;
            case PORTD:
                INSERT_BIT(GPIO_PORTD_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTD_DEN_R, pin_num, 1);
                break;
            case PORTE:
                INSERT_BIT(GPIO_PORTE_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTE_DEN_R, pin_num, 1);
                break;
            case PORTF:
                INSERT_BIT(GPIO_PORTF_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTF_DEN_R, pin_num, 1);
                break;
        }
        break;
        case INLLUP:
        switch (Port)
        {
            case PORTA:
                INSERT_BIT(GPIO_PORTA_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTA_PUR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTA_DEN_R, pin_num, 1);
                break;
            case PORTB:
                INSERT_BIT(GPIO_PORTB_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTB_PUR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTB_DEN_R, pin_num, 1);
                break;
            case PORTC:
                INSERT_BIT(GPIO_PORTC_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTC_PUR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTC_DEN_R, pin_num, 1);
                break;
            case PORTD:
                INSERT_BIT(GPIO_PORTD_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTD_PUR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTD_DEN_R, pin_num, 1);
                break;
            case PORTE:
                INSERT_BIT(GPIO_PORTE_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTE_PUR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTE_DEN_R, pin_num, 1);
                break;
            case PORTF:
                INSERT_BIT(GPIO_PORTF_DIR_R, pin_num, 0);
                INSERT_BIT(GPIO_PORTF_PUR_R, pin_num, 1);
                INSERT_BIT(GPIO_PORTF_DEN_R, pin_num, 1);
                break;
        }
        break;
    }

}


void DIO_WritePin(PORT_Name_Type Port, DIO_Pin_type pin_num, Output_Value_Type value)
{

    switch (Port)
    {
        case PORTA:
            INSERT_BIT(GPIO_PORTA_DATA_R, pin_num, value);
            break;
        case PORTB:
            INSERT_BIT(GPIO_PORTB_DATA_R, pin_num, value);
            break;
        case PORTC:
            INSERT_BIT(GPIO_PORTC_DATA_R, pin_num, value);
            break;
        case PORTD:
            INSERT_BIT(GPIO_PORTD_DATA_R, pin_num, value);
            break;
        case PORTE:
            INSERT_BIT(GPIO_PORTE_DATA_R, pin_num, value);
            break;
        case PORTF:
            INSERT_BIT(GPIO_PORTF_DATA_R, pin_num, value);
            break;
    }
}

Output_Value_Type DIO_ReadPin(PORT_Name_Type Port, DIO_Pin_type pin_num)
{
    switch (Port)
    {
        case PORTA:
            return READ_BIT(GPIO_PORTA_DATA_R, pin_num);
            break;
        case PORTB:
            return READ_BIT(GPIO_PORTB_DATA_R, pin_num);
            break;
        case PORTC:
            return READ_BIT(GPIO_PORTC_DATA_R, pin_num);
            break;
        case PORTD:
            return READ_BIT(GPIO_PORTD_DATA_R, pin_num);
            break;
        case PORTE:
            return READ_BIT(GPIO_PORTE_DATA_R, pin_num);
            break;
        case PORTF:
            return READ_BIT(GPIO_PORTF_DATA_R, pin_num);
            break;
        default:
            return 0x00;
            break;
    }
}

void DIO_TogglePin(PORT_Name_Type Port, DIO_Pin_type pin_num)
{

    switch(Port)
    {
        case PORTA:
            TOGGLE_BIT(GPIO_PORTA_DATA_R, pin_num);
            break;

    }


}

void DIO_WritePort(PORT_Name_Type Port, unsigned char value)
{
    switch (Port)
    {
        case PORTA:
            GPIO_PORTA_DATA_R = value;
            break;
        case PORTB:
            GPIO_PORTB_DATA_R = value;
            break;
        case PORTC:
            GPIO_PORTC_DATA_R = value;
            break;
        case PORTD:
            GPIO_PORTD_DATA_R = value;
            break;
        case PORTE:
            GPIO_PORTE_DATA_R = value;
            break;
        case PORTF:
            GPIO_PORTF_DATA_R = value;
            break;
    }
}

//void DIO_Init(void)
//{
//    DIO_Pin_type i;
//    for (i=PINA0;i<TOTAL_PINS;i++)
//    {
//        DIO_InitPin(i,PinsStatusArray[i]);
//    }
//}


/************************************* INTERRUTPS **************************************/


void Inteupt_Edge_InitPin(PORT_Name_Type Port, DIO_Pin_type pin_num, Int_Edge_Type edge)
{
    switch (Port)
    {
        case PORTA:
            INSERT_BIT(NVIC_EN0_R, 0, 1);    // enable interrupt for port f (0 -> EN0)
            INSERT_BIT(GPIO_PORTA_IS_R, pin_num, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTA_IBE_R, pin_num, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTA_IEV_R, pin_num, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTA_ICR_R, pin_num, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTA_IM_R, pin_num, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case PORTB:
            INSERT_BIT(NVIC_EN0_R, 1, 1);    // enable interrupt for port f (1 -> EN0)
            INSERT_BIT(GPIO_PORTB_IS_R, pin_num, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTB_IBE_R, pin_num, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTB_IEV_R, pin_num, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTB_ICR_R, pin_num, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTB_IM_R, pin_num, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case PORTC:
            INSERT_BIT(NVIC_EN0_R, 2, 1);    // enable interrupt for port f (2 -> EN0)
            INSERT_BIT(GPIO_PORTC_IS_R, pin_num, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTC_IBE_R, pin_num, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTC_IEV_R, pin_num, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTC_ICR_R, pin_num, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTC_IM_R, pin_num, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case PORTD:
            INSERT_BIT(NVIC_EN0_R, 3, 1);    // enable interrupt for port f (3 -> EN0)
            INSERT_BIT(GPIO_PORTD_IS_R, pin_num, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTD_IBE_R, pin_num, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTD_IEV_R, pin_num, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTD_ICR_R, pin_num, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTD_IM_R, pin_num, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case PORTE:
            INSERT_BIT(NVIC_EN0_R, 4, 1);    // enable interrupt for port f (4 -> EN0)
            INSERT_BIT(GPIO_PORTE_IS_R, pin_num, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTE_IBE_R, pin_num, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTE_IEV_R, pin_num, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTE_ICR_R, pin_num, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTE_IM_R, pin_num, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
        case PORTF:
            INSERT_BIT(NVIC_EN0_R, 30, 1);    // enable interrupt for port f (30 -> EN0)
            INSERT_BIT(GPIO_PORTF_IS_R, pin_num, 0);   // interrupt sense (edge | level)
            INSERT_BIT(GPIO_PORTF_IBE_R, pin_num, 0);    // Interrupt (one Edge | Both Edges)

            INSERT_BIT(GPIO_PORTF_IEV_R, pin_num, edge);   // Interrupt Event (GPIOIEV) (LOW edge | HIGH edge)

            INSERT_BIT(GPIO_PORTF_ICR_R, pin_num, 1);    // 1: The corresponding interrupt is cleared (interrupt flag)
            INSERT_BIT(GPIO_PORTF_IM_R, pin_num, 1);    // 1: The interrupt is sent to the interrupt controller.
            break;
    }

}






