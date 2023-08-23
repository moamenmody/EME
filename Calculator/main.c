#include "Std_Types.h"
#include "APP_Calc.h"

void main(void)
{
    System_Init();
    APP_Welcome();
    while(1)
    {
        APP_ClaculatorWork();
    }
}
