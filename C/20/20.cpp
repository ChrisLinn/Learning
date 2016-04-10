#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int main()
{
int CreatNum();
return 0;
}
CreatNum()
{
	int a;
	FILE *fp;
	if ((fp=fopen("C:\\temp1.txt","r+"))==NULL)
		{fp=fopen("C:\\temp1.txt","w+");}	
    a=rand()%20+1;
	fprintf(fp,"%d",a);
	fclose(fp);
    return 0;
} 
