/*
 * APP_Calc.h
 *
 *  Created on: Aug 22, 2023
 *      Author: Mahmoud Badr
 */

#ifndef APP_CALC_H_
#define APP_CALC_H_

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define APP_ORERAND_NUM        10

#define APP_OPERATION_NUM       (APP_ORERAND_NUM-1)

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void System_Init(void)
 * \Description     : Initialize the System
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void System_Init(void);

/******************************************************************************
 * \Syntax          : void APP_Welcome(void)
 * \Description     : Display welcome Message to user
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void APP_Welcome(void);

/****************************************************************************************************************************
 * \Syntax             : ErrorState_t APP_PerformOperation(s64* Copy_OperandArr,char *Copy_OperationArr,char Copy_Operation)
 * \Description        : Calculate the result of a specific operation
 *
 * \Sync\Async         : Synchronous
 * \Reentrancy         : Non Reentrant
 * \Parameters (in)    : Copy_OperationArr     Array of Operations to be done
 *                       Copy_Operation        The specific operation to be done
 * \Parameters (in/out): Copy_OperandArr    The array of operands to take numbers from and put the result on it
 * \Return value:      : ErrorState_t
 ****************************************************************************************************************************/
ErrorState_t APP_PerformOperation(s64* Copy_OperandArr,char *Copy_OperationArr,char Copy_Operation);

/******************************************************************************************
 * \Syntax          : void App_ClacResult(s64* Copy_OperandArr,char *Copy_OperationArr)
 * \Description     : Calculate the result of total Operation
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
* \Parameters (in)  : Copy_OperationArr     Array of Operations to be done
*                     Copy_OperandArr       Take the final result from it
 * \Parameters (out): None
 * \Return value:   : void
 ******************************************************************************************/
void App_ClacResult(s64* Copy_OperandArr,char *Copy_OperationArr);

/****************************************************************************************************************
 * \Syntax          : void App_GetNum(s64* Copy_OperandArr,u8 *Copy_NumArr,u8 Copy_NumIndex,u8 Copy_NumNumber)
 * \Description     : Form a decimal value from Array of digits
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Copy_NumArr       Array of digits to form the decimal number from
 *                    Copy_NumIndex     The Index in which the decimal number will be put
 *                    Copy_NumNumber    Number of numbers to form the decimal of
 * \Parameters (out): Copy_OperandArr   Array of operands to put the number as decimal on a specific index on it
 * \Return value:   : void
 ****************************************************************************************************************/
void App_GetNum(s64* Copy_OperandArr,u8 *Copy_NumArr,u8 Copy_NumIndex,u8 Copy_NumNumber);

/******************************************************************************
 * \Syntax          : void APP_ClaculatorWork(void)
 * \Description     : Implement The logic of calculator
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : void
 *******************************************************************************/
void APP_ClaculatorWork(void);


#endif /* APP_CALC_H_ */

/**********************************************************************************************************************
 *  END OF FILE: APP_Calc.h
 *********************************************************************************************************************/
