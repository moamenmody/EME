/*
 * keyPad_Driver.c
 *
 *  Created on: Aug 18, 2023
 *      Author: hanyt
 */


#include "keyPad_Driver.h"



/* Array of 4x4 to define characters which will be print on specific key pressed */
unsigned  char symbol[4][4] = {{ '1', '2',  '3', '+'},
                               { '4', '5',  '6', '-'},
                               { '7', '8',  '9', '*'},
                               { 'c', '0',  '=', '/'}};


/*
 * Function KeyPad_Init (void) (void)
 * Initialize the key pad 4*4
 */
void KeyPad_Init_NoINT(void)
{
    // input pins to read data from
    DIO_InitPin(C_PORT, KP_C1, INLLUP);
    DIO_InitPin(C_PORT, KP_C2, INLLUP);
    DIO_InitPin(C_PORT, KP_C3, INLLUP);
    DIO_InitPin(C_PORT, KP_C4, INLLUP);

    // output pins to apply voltage to read it from inputs
    DIO_InitPin(R_PORT, KP_R1, OUTPUT);
    DIO_InitPin(R_PORT, KP_R2, OUTPUT);
    DIO_InitPin(R_PORT, KP_R3, OUTPUT);
    DIO_InitPin(R_PORT, KP_R4, OUTPUT);
}

/*
 * Function KeyPad_Read (unsigned  char) (void)
 * Return: read char if found else return DEFAULT_K
 */
char KeyPad_Read_NoINT(void)
{
    char key = DEFAULT_K;

    DIO_WritePin(R_PORT, KP_R1, HIGH);
    DIO_WritePin(R_PORT, KP_R2, HIGH);
    DIO_WritePin(R_PORT, KP_R3, HIGH);
    DIO_WritePin(R_PORT, KP_R4, HIGH);

    for (int r= 0; r < 4; r++) {
        DIO_WritePin(R_PORT, KP_R1+r, LOW);
        for (int c= 0; c < 4; c++) {
            if(!DIO_ReadPin(C_PORT, KP_C1+c))
            {
                key = symbol[r][c];
                while(!DIO_ReadPin(C_PORT, KP_C1+c));
            }
        }
        DIO_WritePin(R_PORT, KP_R1+r, HIGH);
    }

    return key;
}


/*
 * Function KeyPad_Init (void) (void)
 * Initialize the key pad 4*4
 * Using interrupt
 */
void KeyPad_Init_INT(void)
{
    // input pins to read data from and using interrupt to read
    DIO_InitPin(C_PORT, KP_C1, INLLUP);
    Inteupt_Edge_InitPin(C_PORT, KP_C1, LOW_EDGE);
    DIO_InitPin(C_PORT, KP_C2, INLLUP);
    Inteupt_Edge_InitPin(C_PORT, KP_C2, LOW_EDGE);
    DIO_InitPin(C_PORT, KP_C3, INLLUP);
    Inteupt_Edge_InitPin(C_PORT, KP_C3, LOW_EDGE);
    DIO_InitPin(C_PORT, KP_C4, INLLUP);
    Inteupt_Edge_InitPin(C_PORT, KP_C4, LOW_EDGE);

    // output pins to apply voltage to read it from inputs
    DIO_InitPin(R_PORT, KP_R1, OUTPUT);
    DIO_InitPin(R_PORT, KP_R2, OUTPUT);
    DIO_InitPin(R_PORT, KP_R3, OUTPUT);
    DIO_InitPin(R_PORT, KP_R4, OUTPUT);

    DIO_WritePin(R_PORT, KP_R1, HIGH);
    DIO_WritePin(R_PORT, KP_R2, HIGH);
    DIO_WritePin(R_PORT, KP_R3, HIGH);
    DIO_WritePin(R_PORT, KP_R4, HIGH);
}

/*
 * Function KeyPad_Read (unsigned  char) (void)
 * Return: read char if found else return DEFAULT_K
 * Using interrupt
 */
void KeyPad_Read_INT(void)
{
    for (int r= 0; r < 4; r++) {
        DIO_WritePin(R_PORT, KP_R1+r, LOW);
//        int count =0; while(count<100){count++;}
        DIO_WritePin(R_PORT, KP_R1+r, HIGH);
    }

}

