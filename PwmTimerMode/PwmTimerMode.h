/*
 * PwmTimerMode.h
 *
 *  Created on: Aug 26, 2023
 *      Author: khali
 */

#ifndef PWMTIMERMODE_H_
#define PWMTIMERMODE_H_

#include"tm4c123gh6pm.h"

#define TAEN_Enable |=0x1
#define TAEN_Disable &=~0x1
#define IndividualTimer |=0x4
#define ConcatinatedTimer &=~0x1
#define TAAMS_Enable |=0x1
#define TACMR_Enable &=~0x1
#define TAMR_Enable |=0x2
#define InvertedMode |=0x40
#define UnaffectedMode &=~0x40
#define ZeroPreScalar &=~0xFF
#define _8BitPreScalar |=0xFF
#define TAPWMIE_Enable |=0x200
#define TAPWMIE_Disable &=~0x200
#define Timer1SysClkOpen |=0x2
#define TAWOT_Disable &=~0x40
#define PF2_AlternativeFuncEnable |=0x4
#define _1Ms 0x3E80


void PwmTimer1Init(void)
void PwmControl(void)


#endif /* PWMTIMERMODE_H_ */
