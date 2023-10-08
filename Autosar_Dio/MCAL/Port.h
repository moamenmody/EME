

#ifndef PORT_H
#define PORT_H

#include "Common_Macros.h"

#include "Std_Types.h"

#define INPUT     (0U)
#define OUTPUT    (1U)

/****************************************************************************************************************/
/* Description: Structure to describe each individual PIN contains:
 *	1. the PORT Which the pin belongs to. 0, 1, 2 or 3
 *	2. the number of the pin in the PORT.
 *  3. the direction of pin --> INPUT or OUTPUT
 */
typedef struct
{
	uint32 port;
	uint32 pin_num;
	uint32 direction;
}Port_Config;
/***************************************************************************************************************/

/* configure the PIN to input or output pin */
void Port_SetDirection(const Port_Config *s_Config_Msg );

#endif /* PORT_H */
