#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#define LED_RED (1<<1U)
#define LED_BLUE (1<<2U)
#define LED_GREEN (1<<3U)
#define SW1 0
#define SW2 4
/**
 * main.c
 */

void hamada(void){
        if(Get_Bit(GPIO_PORTF_RIS_R,0)){// check if interrupt causes by SW1
            if(Get_Bit(GPIO_PORTF_DATA_R,3)){
                GPIO_PORTF_DATA_BITS_R[LED_GREEN]=0;
                }
            GPIO_PORTF_DATA_BITS_R[LED_RED]=LED_RED;
            volatile  int var1;
            for(var1=0;var1<10;var1++){};
            Set_Bit(GPIO_PORTF_ICR_R,0);
        }
        else if(Get_Bit(GPIO_PORTF_RIS_R,4))
        {// check if interrupt causes by SW2
           if(Get_Bit(GPIO_PORTF_DATA_R,1))
           {
               GPIO_PORTF_DATA_BITS_R[LED_RED]=0;
           }

            GPIO_PORTF_DATA_BITS_R[LED_GREEN]=LED_GREEN;
           volatile  int var;
            for(var=0;var<10;var++){};
            Set_Bit(GPIO_PORTF_ICR_R,4);
        }

}

int main(void)
{
        SYSCTL_RCGCGPIO_R |=0x00000020; // Enabling Clock for PORTf
        while((SYSCTL_RCGCGPIO_R & 0x00000020 ) == 0){}; // waiting till the clock is activated
        GPIO_PORTF_LOCK_R = 0x4C4F434B; //
        GPIO_PORTF_CR_R = 0x1F; // Make Portf Configuerable
        GPIO_PORTF_DIR_R = 0x0E; // make the three leds outputs
        GPIO_PORTF_PUR_R = 0x11; // PULL UP ENABLED
        GPIO_PORTF_DEN_R = 0x1F; // Enable the Switches and the leds in PORTF


         NVIC_EN0_R |=(1<<30); // enable interrupt in vector table
        GPIO_PORTF_IS_R  &= ~(1<<0) | ~(1<<4); // configure the interrupt for SW1 & SW2 to be EDGE
        GPIO_PORTF_IBE_R &= ~(1<<0) | ~(1<<4); //Interrupt generation is controlled by the GPIO Interrupt Event

        GPIO_PORTF_IEV_R &= ~(1<<0) | ~(1<<4); //SW1 & SW2 pins generate interrupt with the falling edge
        GPIO_PORTF_IM_R  |=  (1<<0) | (1<<4); //The interrupt from the corresponding pin is sent to the interrupt controller.





        while(1){

        }

	return 0;
}
