#include"tm4c123gh6pm.h"
#include"PwmTimerMode.h"
#include"Port_INIT.h"
int main(void)
{
    PORTF_init();
    PwmTimer1Init();
    PwmControl();
	return 0;
}
