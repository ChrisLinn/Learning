#include <msp430g2553.h>
#include <math.h>
double temp=1,temp1=1,a,k,d;
int f=0;
double c;
void main()
{
	WDTCTL=WDTPW+WDTHOLD; 	//�ؿ��Ź�

	TACTL=TASSEL_2+MC_2;  //ѡ����ϵͳʱ��
	TACCTL1=CM_2+CCIS_1+CAP+CCIE+SCS;//����Ƚ�������

    CACTL1 = CARSEL + CAREF_1 + CAON + CAIES;//�Ƚ�������
    CACTL2 = P2CA0 + CAF;
    CAPD = CAPD0;


    P1IES = 0;   //io�� ����
    P1IFG = 0;
    P2SEL = BIT2 + BIT6 + BIT7;
    P2IES = 0;
    P2IFG = 0;

	P1DIR |= BIT5;                            //���
	P1OUT=BIT5;
	__delay_cycles(10000);                     //��ʱ����֤���

	__bis_SR_register(GIE);                    //�����ж�

	temp=TAR;                                 //���ֵ
	P1DIR =BIT5;
	P1OUT &=~BIT5;                            //�ŵ�
	while(f==0);                               //ֱ������
	temp=a-temp;
//	TACCTL1=0X00;
//	TACCTL1=CM_2+CCIS_1+CAP+CCIE+SCS;           //��������ʼ
	f=0;


	P1DIR |=BIT5;                              //���
	P1OUT =BIT5;
	__delay_cycles(10000);

	temp1=TAR;                                   //�ڶ��δ���
	P1DIR=BIT4;
//	P1OUT &=~BIT4;
	while(f==0);
	temp1=a-temp1;                               //������������Ӧ����
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
	                         //����



	for(;;);
}

#pragma vector=TIMER0_A1_VECTOR     //�Ƚ����ж�CCR1=TAR
__interrupt void Timer_A (void)
{
	switch(TAIV)
	{
	case 2:
		a=CCR1;     // CCR1�ж�
		f=1;      //�ı�Ƚ�����
		break;
	case 4: break; 		// CCR2�ж�δ��
	case 6: break; 		// CCR3�ж�δ��
	case 8: break; 		// CCR4�ж�δ��
	case 10: break; 		// ����δ��
	case 12: break; 		// ����δ��
	case 14: break;
	default: break;
	}
}




