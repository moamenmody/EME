//#include "./Tiva_DIO/Tiva_DIO.h"
//#include "./LCD_Driver/LCD_Driver.h"
//#include "./keyPad_Driver/keyPad_Driver.h"
#include "Tiva_DIO/Tiva_DIO.h"
#include "LCD_Driver/LCD_Driver.h"
#include "keyPad_Driver/keyPad_Driver.h"


char volatile key = DEFAULT_K;

// GPIOB Interrupt handler
void GPIOB_Handler(void)
{
    for (int r= 0; r < 4; r++) {
        if(!DIO_ReadPin(R_PORT, KP_R1+r))
        {
            if (GPIO_PORTB_MIS_R & 0x01) /* check if interrupt caused by PB0 */
            {
                key = symbol[r][0];
                GPIO_PORTB_ICR_R |=(0x01);
            }
            else if (GPIO_PORTB_MIS_R & 0x02) /* check if interrupt caused by PB1 */
            {
                key = symbol[r][1];
                GPIO_PORTB_ICR_R |=(0x02);
            }
            else if (GPIO_PORTB_MIS_R & 0x04) /* check if interrupt caused by PB2 */
            {
                key = symbol[r][2];
                GPIO_PORTB_ICR_R |=(0x04);
            }
            else if (GPIO_PORTB_MIS_R & 0x08) /* check if interrupt caused by PB3 */
            {
                key = symbol[r][3];
                GPIO_PORTB_ICR_R |=(0x08);
            }
        }
        DIO_WritePin(R_PORT, KP_R1+r, HIGH);
    }
}



/**
 * main.c
 */
void main(void)
{
    PORT_Init(PORTA);
    PORT_Init(PORTB);
//    PORT_Init(PORTD);
    PORT_Init(PORTE);
    PORT_Init(PORTF);

//    DIO_InitPin(PORTF, PIN0, INLLUP);
//    DIO_InitPin(PORTF, PIN4, INLLUP);

    DIO_InitPin(RS, OUTPUT);
    DIO_InitPin(RW, OUTPUT);
    DIO_InitPin(EN, OUTPUT);
    DIO_InitPin(D7, OUTPUT);
    DIO_InitPin(D6, OUTPUT);
    DIO_InitPin(D5, OUTPUT);
    DIO_InitPin(D4, OUTPUT);
    DIO_InitPin(D3, OUTPUT);
    DIO_InitPin(D2, OUTPUT);
    DIO_InitPin(D1, OUTPUT);
    DIO_InitPin(D0, OUTPUT);

    LCD_Init();

    int num1 = 0, num2 = 0;
    int result = 0;
    int operator = '\0';




    LCD_SetCursor(0, 1);
    LCD_WriteString("HELLO...");
    int num =0;
    KeyPad_Init_INT();
    int flag =0;
    __asm(" CPSIE  I");
    LCD_Clear();
//    while(1){
//
//        KeyPad_Read_INT();
//        if(key!=DEFAULT_K)
//        {
//
//            int count =0; while(count<1000000){count++;}
//
//            if(key>='0'&&key<='9')
//            {
//                if(flag == 0)
//                {
//                    LCD_SetCursor(0, 0);
//                    LCD_WriteString("                 ");
//                    LCD_SetCursor(0, 0);
//                    flag = 1;
//                }
//                LCD_WriteChar(key);
//             num = num*10+key-'0';
//            }
//             if(key== '=')
//            {
//                LCD_SetCursor(1, 0);
//                LCD_WriteData(num);
//                LCD_WriteString("             ");
//                num =0;
//                flag =0;
//            }
//             if(key == 'c')
//             {
//                 LCD_Clear();
//                 LCD_SetCursor(0, 0);
//             }
//            key = DEFAULT_K;
//        }
//
////        LCD_SetCursor(0, 1);
////        LCD_WriteString("HELLO...");
////        int count =0; while(count<1000000){count++;}
////        LCD_Clear();
////        count =0; while(count<100000){count++;}
//
//    }
//}



    while (1) {
            KeyPad_Read_INT();
            if (key != DEFAULT_K) {
                int count = 0;
                while (count < 1000000) {
                    count++;
                }

                if (key >= '0' && key <= '9') {
                    if (flag == 0) {
                        LCD_SetCursor(0, 0);
                        LCD_WriteString("                ");
                        LCD_SetCursor(0, 0);
                        flag = 1;
                    }
                    LCD_WriteChar(key);
                    if (operator == '\0') {
                        num1 = num1 * 10 + key - '0';
                    } else {
                        count = 0;
                                        while (count < 1000000) {
                                            count++;
                                        }
                        num2 = num2 * 10 + key - '0';

                    }
                } else if (key == '=') {
                    if (operator == '+') {
                        result = num1 + num2;
                    } else if (operator == '-') {
                        result = num1 - num2;
                    } else if (operator == '*') {
                        result = num1 * num2;
                    } else if (operator == '/') {
                        if (num2 != 0) {
                            result = num1 / num2;
                        } else {
                            // Handle division by zero error
                        }
                    }
                    LCD_SetCursor(1, 0);
                    LCD_WriteString("Result: ");
                    LCD_WriteData(result);
                    LCD_WriteString("       ");
                    num1 = result;
                    num2 = 0;
                    operator = '\0';
                    flag = 0;
                } else if (key == 'c') {
                    LCD_Clear();
                    LCD_SetCursor(0, 0);
                    num1 = 0;
                    num2 = 0;
                    operator = '\0';
                    flag = 0;
                } else if (key == '+' || key == '-' || key == '*' || key == '/') {
                    operator = key;
                    LCD_SetCursor(0, 15);
                    LCD_WriteChar(key);
                    flag = 0;
                }
                key = DEFAULT_K;

            }
        }
    }

    /*
    while (1) {
        KeyPad_Read_INT();
        if (key != DEFAULT_K) {
            int count = 0;
            while (count < 1000000) {
                count++;
            }

            if (key >= '0' && key <= '9') {
                if (flag == 0) {
                    LCD_SetCursor(0, 0);
                    LCD_WriteString("                ");
                    LCD_SetCursor(0, 0);
                    flag = 1;
                }
                LCD_WriteChar(key);
                if (operator == '\0') {
                    num1 = num1 * 10 + key - '0';
                } else {
                    num2 = num2 * 10 + key - '0';
                }
            } else if (key == '=') {
                if (operator == '+') {
                    result = num1 + num2;
                } else if (operator == '-') {
                    result = num1 - num2;
                } else if (operator == '*') {
                    result = num1 * num2;
                } else if (operator == '/') {
                    if (num2 != 0) {
                        result = num1 / num2;
                    } else {
                        // Handle division by zero error
                    }
                }
                LCD_SetCursor(1, 0);
                LCD_WriteString("Result: ");
                LCD_WriteData(result);
                LCD_WriteString("       ");
                num1 = result;
                num2 = 0;
                operator = '\0';
                flag = 0;
            } else if (key == 'c') {
                LCD_Clear();
                LCD_SetCursor(0, 0);
                num1 = 0;
                num2 = 0;
                operator = '\0';
                flag = 0;
            } else if (key == '+' || key == '-' || key == '*' || key == '/') {
                operator = key;
                LCD_SetCursor(0, 15);
                LCD_WriteChar(key);
                flag = 0;
            }
            key = DEFAULT_K;
        }
    }
}
*/
//    while (1) {
//          KeyPad_Read_INT();
//          if (key != DEFAULT_K) {
//              int count = 0;
//              while (count < 1000000) {
//                  count++;
//              }
//
//              if (key >= '0' && key <= '9') {
//                  if (flag == 0) {
//                      LCD_SetCursor(0, 0);
//                      LCD_WriteString("                ");
//                      LCD_SetCursor(0, 0);
//                      flag = 1;
//                  }
//                  LCD_WriteChar(key);
//                  if (operator == '\0') {
//                      num1 = num1 * 10 + key - '0';
//                  } else {
//                      num2 = num2 * 10 + key - '0';
//                  }
//              } else if (key == '=') {
//                  if (operator != '\0') {
//                      if (operator == '+') {
//                          result = num1 + num2;
//                      } else if (operator == '-') {
//                          result = num1 - num2;
//                      } else if (operator == '*') {
//                          result = num1 * num2;
//                      } else if (operator == '/') {
//                          if (num2 != 0) {
//                              result = num1 / num2;
//                          } else {
//                              // Handle division by zero error
//                          }
//                      }
//                      LCD_SetCursor(1, 0);
//                      LCD_WriteString("Result: ");
//                      LCD_WriteData(result);
//                      LCD_WriteString("       ");
//                      num1 = result;
//                      num2 = 0;
//                      operator = '\0';
//                      flag = 0;
//                  }
//              } else if (key == 'c') {
//                  LCD_Clear();
//                  LCD_SetCursor(0, 0);
//                  num1 = 0;
//                  num2 = 0;
//                  operator = '\0';
//                  flag = 0;
//              } else if (key == '+' || key == '-' || key == '*' || key == '/') {
//                  operator = key;
//                  LCD_SetCursor(0, 15);
//                  LCD_WriteChar(key);
//                  flag = 0;
//              }
//              key = DEFAULT_K;
//          }
//      }





