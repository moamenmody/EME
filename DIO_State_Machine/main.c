#include "bitwise_operation.h"
#include "tm4c123gh6pm.h"
#define LED_RED (1<<1U)
#define LED_BLUE (1<<2U)
#define LED_GREEN (1<<3U)
#define SW1 0
#define SW2 4


volatile int state1=0;

void state(){
    int i;
    for(i=0;i<10000;i++);//Debouncing delay
    if(Get_Bit(GPIO_PORTF_RIS_R,SW1))
    {
        state1 = 1;
    }
    else if (Get_Bit(GPIO_PORTF_RIS_R,SW2))
    {
        state1 = 2;
    }
    GPIO_PORTF_ICR_R|=0X11;//CLEARS BOTH FLAGS OF SW1 & SW2
}
void Interrupt_Init(){

            NVIC_EN0_R |=(1<<30); // enable interrupt in vector table
            GPIO_PORTF_IS_R  &= ~(1<<0) | ~(1<<4); // configure the interrupt for SW1 & SW2 to be EDGE
            GPIO_PORTF_IBE_R &= ~(1<<0) | ~(1<<4); //Interrupt generation is controlled by the GPIO Interrupt Event

            GPIO_PORTF_IEV_R &= ~(1<<0) | ~(1<<4); //SW1 & SW2 pins generate interrupt with the falling edge
            GPIO_PORTF_IM_R  |=  (1<<0) | (1<<4); //The interrupt from the corresponding pin is sent to the interrupt controller.

}
void PortF_Init(){
                SYSCTL_RCGCGPIO_R |=0x00000020; // Enabling Clock for PORTf
                while((SYSCTL_RCGCGPIO_R & 0x00000020 ) == 0){}; // waiting till the clock is activated
                GPIO_PORTF_LOCK_R = 0x4C4F434B; //
                GPIO_PORTF_CR_R = 0x1F; // Make Portf Configuerable
                GPIO_PORTF_DIR_R = 0x0E; // make the three leds outputs
                GPIO_PORTF_PUR_R = 0x11; // PULL UP ENABLED
                GPIO_PORTF_DEN_R = 0x1F; // Enable the Switches and the leds in PORTF

}
int main(void)
{
            int currentLedState = 1 ;
            PortF_Init();
            Interrupt_Init();
            Set_Bit(GPIO_PORTF_DATA_R,1);
            while(1){
                 if(state1==1){
                     if(currentLedState==1){
                         state1=0;
                         Clear_Bit(GPIO_PORTF_DATA_R,1); // Led red is off
                         Set_Bit(GPIO_PORTF_DATA_R,2); // led blue is on
                         currentLedState=2;
                     }

                     else if(currentLedState==2){

                         state1=0;
                         Clear_Bit(GPIO_PORTF_DATA_R,2); // Led blue is off
                         Set_Bit(GPIO_PORTF_DATA_R,3); // led Green is on
                         currentLedState=3;
                     }
                     else if (currentLedState==3){
                          state1=0;
                          Clear_Bit(GPIO_PORTF_DATA_R,3); // Led Green is off
                          Set_Bit(GPIO_PORTF_DATA_R,1); // led Red is on
                          currentLedState=1;
                      }
                 }
                 else if(state1==2){
                     if(currentLedState==1){
                         state1=0;
                         Clear_Bit(GPIO_PORTF_DATA_R,1); // Led red is off
                         Set_Bit(GPIO_PORTF_DATA_R,3); // led Green is on
                         currentLedState=3;
                     }
                     else if (currentLedState==3){
                         state1=0;
                         Clear_Bit(GPIO_PORTF_DATA_R,3); // Led Green is off
                         Set_Bit(GPIO_PORTF_DATA_R,2); // led BLue is on
                         currentLedState=2;
                     }
                     else if (currentLedState==2){
                          state1=0;
                          Clear_Bit(GPIO_PORTF_DATA_R,2); // Led Blue is off
                          Set_Bit(GPIO_PORTF_DATA_R,1); // led Red is on
                          currentLedState=1;
                      }
                 }


                 return 0;


}




