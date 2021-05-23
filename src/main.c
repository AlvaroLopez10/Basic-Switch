/*
 * main implementation: use this 'C' sample to create your own application
 *
 */


#include "S32K142.h" /* include peripheral declarations S32K142 */

void delay (unsigned short tiempo)
{
    LPTMR0->PSR=0x00000005; //Bypass y 1 KHz clock
    LPTMR0->CMR=tiempo-1;
    LPTMR0->CSR=0x00000001;
    do{}while (((LPTMR0->CSR)&0x00000080)==0);
    LPTMR0->CSR=0x00000080;
}

int main(void)
{
    PCC-> PCCn[PCC_PORTC_INDEX] = (1<<30);
    PCC-> PCCn[PCC_PORTD_INDEX] = (1<<30);
    PCC-> PCCn[PCC_LPTMR0_INDEX] = (1<<30);

    PORTC->PCR[12] = 0x00000100;

    PTD->PDDR = 1;
    PORTD->PCR[0] = 0x00000100;

    for(;;)
    {
      if (PTC->PDIR & (1<<12))
          {
           PTD-> PDOR = 0;
           delay(500);
           PTD-> PDOR = 1;
           delay (500);
          }
    }
return 0;
}
