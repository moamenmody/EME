#include "tm4c123gh6pm.h"
#include "Port_INIT.h"

void PORTA_init (){

	// keypad columns pa2-pa5
	unsigned int delay;
	SYSCTL_RCGC2_R |= (1U << 0);
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTA_LOCK_R = 0x4c4f434b;
	GPIO_PORTA_CR_R = 0x1f;
	GPIO_PORTA_PUR_R |= 0x3c;
	GPIO_PORTA_DIR_R &= ~0x3c;
	GPIO_PORTA_DEN_R |= 0x3c;
	
}

void PORTB_init (){
	
	// lcd data PB0-7
	unsigned int delay;
	SYSCTL_RCGC2_R |= (1U << 1);
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTB_LOCK_R = 0x4c4f434b;
	GPIO_PORTB_CR_R = 0xff;
	GPIO_PORTB_DIR_R |= 0xff;
	GPIO_PORTB_DEN_R |= 0xff;
	
}

void PORTC_init (){
	
	// lcd ctrl PC4 -> EN, PC5 -> RS
	unsigned int delay;
	SYSCTL_RCGC2_R |= (1U << 2);
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTC_LOCK_R = 0x4c4f434b;
	GPIO_PORTC_CR_R |= 0x3f;
	GPIO_PORTC_DIR_R |= 0x30;
	GPIO_PORTC_DEN_R |= 0x30;
	
}

void PORTE_init (){
	
	// keypad rows PE0-3
	unsigned int delay;
	SYSCTL_RCGC2_R |= (1U << 4);
	delay = SYSCTL_RCGCGPIO_R;
	GPIO_PORTE_LOCK_R = 0x4c4f434b;
	GPIO_PORTE_CR_R = 0x1f;
	GPIO_PORTE_PCTL_R &= ~0x000000FF;
	GPIO_PORTE_DIR_R |= 0x0f;
	GPIO_PORTE_DEN_R |= 0x0f;
	
}

void PORTF_init (){
	
	// sw1 & sw2
	SYSCTL_RCGC2_R |= (1 << 5);
	GPIO_PORTF_LOCK_R = 0x4c4f434b;
	GPIO_PORTF_DIR_R = 1<<2;
	GPIO_PORTF_DEN_R |= 0xFF;
	GPIO_PORTF_ODR_R|=0x00;
	GPIO_PORTF_PCTL_R= (7<<8);

	 
}





