#include<stdio.h>
int main()
{
	int a[100][100];
	a[0][0]=1;
	a[0][1]=2;
	a[1][0]=2;
	a[1][1]=1;
	int k,i=2;
	scanf("%d",&k);
	int m,n;
	while(i<k)
	{
		for(m=0;m<i;m++)
		{
			for(n=0;n<i;n++)
			{
				a[i+m][n]=a[m][n]+i;
				a[m][i+n]=a[i+m][n];
				a[i+m][i+n]=a[m][n];
			
			}
		}
		i*=2;
	}
	for(m=0;m<i;m++)
	{
		for(n=0;n<i;n++) 
			printf("%d ",a[m][n]);
		printf("\n");
	}
	return 0;
}