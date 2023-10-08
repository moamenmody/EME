
#include "Port.h"

void Port_SetDirection(const Port_Config * ConfigPtr )
{
	uint8 * DDR_Ptr = NULL_PTR;
	/* point to the required DDR Register */
	switch(ConfigPtr->port)
	{
		case  0: DDR_Ptr = &DDRA;
				 break;
		case  1: DDR_Ptr = &DDRB;
				 break;
		case  2: DDR_Ptr = &DDRC;
				 break;
		case  3: DDR_Ptr = &DDRD;
				 break;
	}
	if(ConfigPtr->direction == OUTPUT)
	{
		SET_BIT(*DDR_Ptr,ConfigPtr->pin_num); // set the corresponding bit in the DDR register to configure it as output pin
	}
	else if(ConfigPtr->direction == INPUT)
	{
		CLEAR_BIT(*DDR_Ptr,ConfigPtr->pin_num); // clear the corresponding bit in the DDR register to configure it as input pin
	}				
}
