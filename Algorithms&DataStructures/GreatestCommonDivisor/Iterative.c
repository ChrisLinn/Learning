#include <stdio.h>
//#include <math.h>

int gcd(int m,int n)
{	
	int r;
	while(n!=0){
		r = m%n;
		m = n;
		n = r;
	}
	return m;
}

int main(void) {
	// your code goes here
	int result = gcd(12,8);
	printf("%d",result);
	return 0;
}
