//Flag==0对应Rref
#include  <msp430g2553.h>
#define Rref 1000
long t=0;
long tao[2]={0};
int r=0;
int flag=0;
volatile unsigned long int i;
void main(int argc, char *argv[])
{
    WDTCTL = WDTPW + WDTHOLD;
	{
		P1OUT = 0;

		/* Port 1 Direction Register */
		P1DIR = BIT1 + BIT2; 								//p1.1--Rmeas.p1.2--Rref

		/* Port 1 Interrupt Edge Select Register */
		P1IES = 0;

		/* Port 1 Interrupt Flag Register */
		P1IFG = 0;

		/* Port 2 Interrupt Edge Select Register */
		P2IES = 0;

		/* Port 2 Interrupt Flag Register */
		P2IFG = 0;
	}
	{
		BCSCTL2 = SELM_0 + DIVM_0 + DIVS_0;


	    if (CALBC1_1MHZ != 0xFF) {
	        /* Follow recommended flow. First, clear all DCOx and MODx bits. Then
	         * apply new RSELx values. Finally, apply new DCOx and MODx bit values.
	         */
	        DCOCTL = 0x00;
	        BCSCTL1 = CALBC1_1MHZ;      /* Set DCO to 1MHz */
	        DCOCTL = CALDCO_1MHZ;
	    }

	    /*
	     * Basic Clock System Control 1
	     *
	     * XT2OFF -- Disable XT2CLK
	     * ~XTS -- Low Frequency
	     * DIVA_0 -- Divide by 1
	     *
	     * Note: ~XTS indicates that XTS has value zero
	     */
	    BCSCTL1 |= XT2OFF + DIVA_0;

	    /*
	     * Basic Clock System Control 3
	     *
	     * XT2S_0 -- 0.4 - 1 MHz
	     * LFXT1S_2 -- If XTS = 0, XT1 = VLOCLK ; If XTS = 1, XT1 = 3 - 16-MHz crystal or resonator
	     * XCAP_1 -- ~6 pF
	     */
	    BCSCTL3 = XT2S_0 + LFXT1S_2 + XCAP_1;
	}
	{
		/* CACTL1 Register */
		CACTL1 = CARSEL + CAREF_1 + CAON  + CAIES + CAIE;

		/* CACTL2 Register */
		CACTL2 = P2CA0 + CAF;

		/* CAPD, Register */
		CAPD = CAPD0;


	}
	CCTL0 = CCIE;                             // CCR0 interrupt enabled
	CCR0  = 1;
	TACTL = TASSEL_1 + MC_1;                  // ACLK, upmode
	//_BIS_SR(LPM3_bits + GIE);                 // Enter LPM3 w/ interrupt
	//Rref充电		p1.2=1	p1.1=X
	P1DIR = BIT2;
	P1OUT = BIT2;
	i = 100000;
	do i--;
	while (i != 0);
	t=0;
	while(1){

		if(!flag){//Rref放电   p1.2=0 p1.1=X
			P1DIR = BIT2;
			P1OUT = 0;
		}
		else{//Rmeas放电		p1.1=0 p1.2=x
			P1DIR = BIT1;
			P1OUT = 0;
		}
	}
}
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
	t++;
}

#pragma vector=COMPARATORA_VECTOR
__interrupt void Comp_A (void)
{
	CCTL0 = 0;
	tao[flag]=t;
	if(flag==1){	//先计Rref,再计Rmes，flag==1时正有一组
		r=Rref*tao[1]/tao[0];
	}
	flag=!flag;
	if(flag){//Rmes充电		p1.1=1	p1.2=X
		P1DIR = BIT1;
		P1OUT = BIT1;
	}
	else{//Rref充电		p1.2=1	p1.1=X
		P1DIR = BIT2;
		P1OUT = BIT2;
	}
	i = 100000;
	do i--;
	while (i != 0);
	t=0;
	CCTL0 = CCIE;

}
