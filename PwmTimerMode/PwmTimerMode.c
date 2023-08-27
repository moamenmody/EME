
#include "PwmTimerMode.h"



void PwmTimer1Init(void)

{
    SYSCTL_RCGCTIMER_R Timer1SysClkOpen;
    GPIO_PORTF_AFSEL_R PF2_AlternativeFuncEnable;
    TIMER1_CTL_R TAEN_Disable;
    TIMER1_CFG_R IndividualTimer;
    TIMER1_TAMR_R TAAMS_Enable;
    TIMER1_TAMR_R TACMR_Enable;
    TIMER1_TAMR_R TAMR_Enable;
    TIMER1_TAMR_R TAWOT_Disable;
    TIMER1_CTL_R InvertedMode;
    //TIMER1_TAPR_R ZeroPreScalar;
    TIMER1_TAMR_R TAPWMIE_Disable;
    TIMER1_TAILR_R = _1Ms;


}

void PwmControl(void)
{
    int MatchValue=0x00;
    TIMER1_TAMATCHR_R = MatchValue;
    TIMER1_CTL_R TAEN_Enable;
    while(1)
    {

        MatchValue+=10;
        TIMER1_TAMATCHR_R = MatchValue;




    }

}



