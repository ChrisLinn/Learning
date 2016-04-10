#include<stdio.h>
#include<math.h>
int main()
{
	double U=12.5663706e-7,N=500,I=300,R=0.105,x,y;
	scanf("%lf",&x);
	y=U*N*I*R*R/(2*pow(R*R+x*x,1.5));
	printf("%lf",y);
	return 0;
}
