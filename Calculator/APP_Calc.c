#include "Std_Types.h"
#include "STK_Interface.h"
#include "KPD_Interface.h"
#include "LCD_Interface.h"
#include "APP_Calc.h"

u8 App_XPositon=0;
u8 App_YPosition=0;

KPD_Config_t KPDCon={.ColumnPinsPorts={GPIO_PORTB,GPIO_PORTB,GPIO_PORTB,GPIO_PORTB},.RowPinsPorts={GPIO_PORTB,GPIO_PORTB,GPIO_PORTB,GPIO_PORTB},
                     .RowPins={GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN3},.ColumnPins={GPIO_PIN4,GPIO_PIN5,GPIO_PIN6,GPIO_PIN7},.RawsNum=4,.ColumnsNum=4};
LCD_Config_t LCD_Con={.ControlPinsPorts={GPIO_PORTA,GPIO_PORTA,GPIO_PORTA},.ControlPins={GPIO_PIN2, GPIO_PIN3, GPIO_PIN4},
                      .DataPinsPorts={GPIO_PORTE,GPIO_PORTE,GPIO_PORTE,GPIO_PORTE},
                      .DataPins={GPIO_PIN0,GPIO_PIN1,GPIO_PIN2,GPIO_PIN3},.XPosition=&App_XPositon,.Yposition=&App_YPosition,
                      .Cursor=LCD_CURSORBLINK,.Font=LCD_5_8_FONT,.Mode=LCD_4BIT_MODE,.LinesNum=LCD_TWO_LINES};
/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static u8 Local_NegativeFlag=0;
static u8 Local_PressedKey=0xff;
static s64 Local_operandArr[APP_ORERAND_NUM]={0};
static u8 Local_NumArr[5]={0};
static char Local_operationArr[APP_OPERATION_NUM]={0};
static u8 Local_NumIndex=0;
static u8 Local_NumNumber=0;
static u8 Local_OperationIndex=0;
static u8 Local_Counter=0;
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
void System_Init(void)
{
    /*Initialize LCD*/
    LCD_Init(&LCD_Con);
    /*Initialize Keypad*/
    KPD_Init(&KPDCon);
}

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
void APP_Welcome(void)
{
    LCD_SendString(&LCD_Con, "Welcome to      Badr Calculator");
    STK_Delyms(4000);
    LCD_Clear(&LCD_Con);
    LCD_SendString(&LCD_Con, "we have up to 10operations");
    STK_Delyms(4000);
    LCD_Clear(&LCD_Con);
    LCD_SendString(&LCD_Con, "your operand is up to 5 digits");
    STK_Delyms(4000);
    LCD_Clear(&LCD_Con);
    LCD_SendString(&LCD_Con, "you can start   calculating Now");
    STK_Delyms(4000);
    LCD_Clear(&LCD_Con);
}

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
ErrorState_t APP_PerformOperation(s64* Copy_OperandArr,char *Copy_OperationArr,char Copy_Operation)
{
    u8 Local_Counter=0,Local_IntCounter=0,Local_FoundFlag=0;
    ErrorState_t Local_ErrorState=E_OK;
    for(Local_Counter=0;Local_Counter<(APP_OPERATION_NUM-1);Local_Counter++)
    {
        if(Copy_OperationArr[Local_Counter]==0)
        {
            break;
        }
        if(Copy_OperationArr[Local_Counter]==Copy_Operation)
        {
            Local_FoundFlag=1;
            /*Get the operation and perform it*/
            switch(Copy_Operation)
            {
            case '*': Copy_OperandArr[Local_Counter]*=Copy_OperandArr[Local_Counter+1]; break;
            case '/':
                /*Handle devision by zero*/
                if(Copy_OperandArr[Local_Counter+1]==0)
                {
                    Local_ErrorState=E_DIV_BY_ZERO;
                }
                Copy_OperandArr[Local_Counter]/=Copy_OperandArr[Local_Counter+1]; break;
            case '+': Copy_OperandArr[Local_Counter]+=Copy_OperandArr[Local_Counter+1]; break;
            case '-': Copy_OperandArr[Local_Counter]-=Copy_OperandArr[Local_Counter+1]; break;
            }
            if(Local_ErrorState != E_DIV_BY_ZERO)
            {
                for(Local_IntCounter=Local_Counter+1;Local_IntCounter<(APP_OPERATION_NUM-1);Local_IntCounter++)
                {
                    if(Copy_OperationArr[Local_IntCounter]==0)
                    {
                        break;
                    }
                    /*pop the operation after implementing it*/
                    Copy_OperationArr[Local_IntCounter-1]=Copy_OperationArr[Local_IntCounter];
                    if(Local_IntCounter<(APP_OPERATION_NUM-1))
                    {
                        Copy_OperandArr[Local_IntCounter]=Copy_OperandArr[Local_IntCounter+1];
                    }
                }
            }
            /*Make the last operation and operand zero*/
            Copy_OperationArr[Local_IntCounter-1]=0;
            Copy_OperandArr[Local_IntCounter]=0;
        }
        /*search for more operation*/
        if(Local_FoundFlag==1)
        {
            Local_Counter--;
            Local_FoundFlag=0;
        }
    }
    return Local_ErrorState;
}

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
void App_ClacResult(s64* Copy_OperandArr,char *Copy_OperationArr)
{
    ErrorState_t Local_ErrorState=E_OK;
    LCD_GoToXY(&LCD_Con, 0, 1);
    LCD_SendString(&LCD_Con, "                ");
    LCD_GoToXY(&LCD_Con, 0, 1);
    /*Perform the multiplication operation*/
    APP_PerformOperation(Copy_OperandArr, Copy_OperationArr, '*');
    /*Perform the division operation and make sure it's not devision by zero*/
    Local_ErrorState=APP_PerformOperation(Copy_OperandArr, Copy_OperationArr, '/');
    if(Local_ErrorState !=E_DIV_BY_ZERO)
    {
        /*Perform the subtraction operation*/
        APP_PerformOperation(Copy_OperandArr, Copy_OperationArr, '-');
        /*Perform the summation operation*/
        APP_PerformOperation(Copy_OperandArr, Copy_OperationArr, '+');
        LCD_SendChar(&LCD_Con, '=');
        /*send the final result to LCD*/
        LCD_WriteNumber(&LCD_Con, Copy_OperandArr[0]);
    }
    else
    {
        LCD_SendString(&LCD_Con, "Infinity");
    }

}

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
void App_GetNum(s64* Copy_OperandArr,u8 *Copy_NumArr,u8 Copy_NumIndex,u8 Copy_NumNumber)
{
    u16 Local_Mul=1,Local_Counter=0,Local_IntCounter=0;
    for(Local_Counter=0;Local_Counter<(Copy_NumIndex+1);Local_Counter++)
    {
        Local_Mul=1;
        /*Get the power of 10 to the number place*/
        for(Local_IntCounter=0;Local_IntCounter<(Copy_NumIndex-Local_Counter);Local_IntCounter++)
        {
            Local_Mul*=10;
        }
        Copy_OperandArr[Copy_NumNumber]+=(Local_Mul*Copy_NumArr[Local_Counter]);
    }
}

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
void APP_ClaculatorWork(void)
{
    /*Get the first digit of number or the negative*/
    do{
        KPD_GetPressedKey(&KPDCon, &Local_PressedKey);
    }while(((Local_PressedKey<'0') || (Local_PressedKey>'9')) && (Local_PressedKey!='-') && (Local_PressedKey!='c'));
    /*if enter c go to clean*/
    if(Local_PressedKey!='c')
    {
        /*if - is entered the number is negative*/
        if(Local_PressedKey == '-')
        {
            Local_NegativeFlag=1;
            LCD_SendChar(&LCD_Con, Local_PressedKey);
            /*Get the first digit of number if negative*/
            do{
                KPD_GetPressedKey(&KPDCon, &Local_PressedKey);
            }while(((Local_PressedKey<'0') || (Local_PressedKey>'9')) && (Local_PressedKey!='c'));
        }
        if(Local_PressedKey!='c')
        {
            Local_NumIndex=0;
            Local_NumArr[Local_NumIndex]=Local_PressedKey-'0';
            LCD_SendChar(&LCD_Con, Local_PressedKey);
            do
            {
                Local_NumIndex=0;
                do{
                    /*Get the rest of the number*/
                    do{
                        KPD_GetPressedKey(&KPDCon, &Local_PressedKey);
                    }while((Local_PressedKey==0xff) && (Local_PressedKey!='c'));
                    /*if clean break the loop and go to clean section*/
                    if(Local_PressedKey=='C')
                    {
                        break;
                    }
                    if((Local_PressedKey>='0') && (Local_PressedKey<='9'))
                    {
                        Local_NumIndex++;
                        Local_NumArr[Local_NumIndex]=Local_PressedKey-'0';
                        LCD_SendChar(&LCD_Con, Local_PressedKey);
                    }
                }while((Local_PressedKey>='0') && (Local_PressedKey<='9') && (Local_NumIndex<4));
                /*make the digits as one number*/
                App_GetNum(Local_operandArr, Local_NumArr, Local_NumIndex, Local_NumNumber);
                if(Local_NegativeFlag==1)
                {
                    Local_operandArr[Local_NumNumber]*=-1;
                    Local_NegativeFlag=0;
                }
                Local_NumNumber++;
                /*Get the operation user want*/
                if((Local_PressedKey=='+') || (Local_PressedKey=='-') || (Local_PressedKey=='*') || (Local_PressedKey=='/'))
                {
                    Local_operationArr[Local_OperationIndex++]=Local_PressedKey;
                    LCD_SendChar(&LCD_Con, Local_PressedKey);
                }
                else if((Local_PressedKey>='0') && (Local_PressedKey<='9'))
                {
                    /*Make sure user enter the operation not a number*/
                    do{
                        KPD_GetPressedKey(&KPDCon, &Local_PressedKey);
                    }while((Local_PressedKey==0xff) || ((Local_PressedKey>='0') && (Local_PressedKey<='9')));
                    Local_operationArr[Local_OperationIndex++]=Local_PressedKey;
                    LCD_SendChar(&LCD_Con, Local_PressedKey);
                }
            }while((Local_PressedKey==0xff)&&(Local_PressedKey!='=') && (Local_PressedKey!='c'));
        }
        if(Local_PressedKey=='=')
        {
            /*calculate the result*/
            App_ClacResult(Local_operandArr, Local_operationArr);
            do{
                KPD_GetPressedKey(&KPDCon, &Local_PressedKey);
            }while(Local_PressedKey!='c');
        }
    }
    if(Local_PressedKey=='c')
    {
        /*Implement the clean sequence*/
        for(Local_Counter=0;Local_Counter<5;Local_Counter++)
        {
            Local_operandArr[Local_Counter]=0;
            Local_operationArr[Local_Counter]=0;
            Local_NumArr[Local_Counter]=0;
        }
        Local_NumNumber=0;
        Local_OperationIndex=0;
        Local_NegativeFlag=0;
        LCD_Clear(&LCD_Con);
    }
}
/**********************************************************************************************************************
 *  END OF FILE: APP_Clac.c
 *********************************************************************************************************************/
