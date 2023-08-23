/*
 * bitwise_operation.h
 *
 *  Created on: Aug 13, 2023
 *      Author: EUI-Support
 */

#ifndef BITWISE_OPERATION_H_
#define BITWISE_OPERATION_H_
#define Set_Bit(REG,BIT)    (REG|=(1<<BIT))
#define Clear_Bit(REG,BIT)  REG&=~(1<<BIT)
#define Get_Bit(REG,BIT)    ((REG>>BIT)&1)
#define Toggle_Bit(REG,BIT) (REG^=1)


#endif /* BITWISE_OPERATION_H_ */
