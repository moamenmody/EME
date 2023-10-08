

#ifndef DIO_REGS_H
#define DIO_REGS_H

#include "Std_Types.h"

/* Definition for PORTA Registers */
#define PORTA_REG	(*((volatile uint32 *)0x400043FC))
#define DDRA_REG	(*((volatile uint32 *)0x40004400))
#define PINA_REG 	(*((volatile uint32 *)0x400043FC))

/* Definition for PORTB Registers */
#define PORTB_REG	(*((volatile uint32 *)0x400053FC))
#define DDRB_REG	(*((volatile uint32 *)0x40005400))
#define PINB_REG 	(*((volatile uint32 *)0x400053FC))

/* Definition for PORTC Registers */
#define PORTC_REG	(*((volatile uint32 *)0x400063FC))
#define DDRC_REG	(*((volatile uint32 *)0x40006400))
#define PINC_REG 	(*((volatile uint32 *)0x400063FC))

/* Definition for PORTD Registers */
#define PORTD_REG	(*((volatile uint32 *)0x400073FC))
#define DDRD_REG	((*((volatile uint32 *)0x40007400))
#define PIND_REG 	(*((volatile uint32 *)0x400073FC))

#endif /* DIO_REGS_H */
