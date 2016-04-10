#include <msp430g2553.h>
#include <math.h>
double temp=1,temp1=1,a,k,d;
int f=0;
double c;
void main()
{
	WDTCTL=WDTPW+WDTHOLD; 	//关看门狗

	TACTL=TASSEL_2+MC_2;  //选择子系统时钟
	TACCTL1=CM_2+CCIS_1+CAP+CCIE+SCS;//捕获比较器设置

    CACTL1 = CARSEL + CAREF_1 + CAON + CAIES;//比较器设置
    CACTL2 = P2CA0 + CAF;
    CAPD = CAPD0;


    P1IES = 0;   //io口 设置
    P1IFG = 0;
    P2SEL = BIT2 + BIT6 + BIT7;
    P2IES = 0;
    P2IFG = 0;

	P1DIR |= BIT5;                            //充电
	P1OUT=BIT5;
	__delay_cycles(10000);                     //延时，保证充电

	__bis_SR_register(GIE);                    //开总中断

	temp=TAR;                                 //存初值
	P1DIR =BIT5;
	P1OUT &=~BIT5;                            //放电
	while(f==0);                               //直至捕获
	temp=a-temp;
//	TACCTL1=0X00;
//	TACCTL1=CM_2+CCIS_1+CAP+CCIE+SCS;           //捕获器开始
	f=0;


	P1DIR |=BIT5;                              //充电
	P1OUT =BIT5;
	__delay_cycles(10000);

	temp1=TAR;                                   //第二次存数
	P1DIR=BIT4;
//	P1OUT &=~BIT4;
	while(f==0);
	temp1=a-temp1;                               //计算测量电阻对应周期
	TACCTL1=0X00;
	c=temp1/temp;
//	k=1000*c*(1.2152+0.0172*c);
	if(c<2)
		k=81.69*c*c+1021*c-90.93;
	else
		k=15.38*c*c+1276*c-256.2;
//	k=1000*k;
//	d=0.01412*c+0.1949;
//	k=k*exp(d);
	                         //计算



	for(;;);
}

#pragma vector=TIMER0_A1_VECTOR     //比较器中断CCR1=TAR
__interrupt void Timer_A (void)
{
	switch(TAIV)
	{
	case 2:
		a=CCR1;     // CCR1中断
		f=1;      //改变比较条件
		break;
	case 4: break; 		// CCR2中断未用
	case 6: break; 		// CCR3中断未用
	case 8: break; 		// CCR4中断未用
	case 10: break; 		// 保留未用
	case 12: break; 		// 保留未用
	case 14: break;
	default: break;
	}
}




