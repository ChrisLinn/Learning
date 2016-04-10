#include <stdio.h>
//#include <math.h>

int gcd(int m,int n)
{	
	if(n==0)
		return m;
	else
		return gcd(n,m%n);
}

int main(void) {
	// your code goes here
	int result = gcd(36,24);
	printf("%d",result);
	return 0;
}
