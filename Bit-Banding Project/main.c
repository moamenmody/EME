#include "tm4c123gh6pm.h"
#define LED_RED (1<<1U)
#define LED_BLUE (1<<2U)
#define LED_GREEN (1<<3U)
void delay ();

void delay (){
    int counter = 0;
    int i ;
    for(i = 0 ; i<1000000; i++){
        counter++;
    }
}


int main(void)
{
    SYSCTL_RCGCGPIO_R |=0x00000020; // Enabling Clock for PORTf
    while((SYSCTL_RCGCGPIO_R & 0x00000020 ) == 0){}; // waiting till the clock is activated
    GPIO_PORTF_DIR_R = 0x0E; // make the three leds outputs
    GPIO_PORTF_DEN_R = 0x1F; // Enable the Switches and the leds in PORTF
    while(1){
        GPIO_PORTF_DATA_BITS_R[LED_RED]=LED_RED;
        delay();
        GPIO_PORTF_DATA_BITS_R[LED_RED]=0<<1U;

        GPIO_PORTF_DATA_BITS_R[LED_BLUE]=LED_BLUE;
        delay();
        GPIO_PORTF_DATA_BITS_R[LED_BLUE]=0<<2U;


        GPIO_PORTF_DATA_BITS_R[LED_GREEN]=LED_GREEN;
        delay();
        GPIO_PORTF_DATA_BITS_R[LED_GREEN]=0<<3U;

        GPIO_PORTF_DATA_BITS_R[LED_RED | LED_BLUE | LED_GREEN]=LED_RED | LED_BLUE | LED_GREEN;
        delay();
    }
	return 0;
}
