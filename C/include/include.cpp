#include <stdio.h>
#include <iostream>
using namespace std;
#include <time.h>
#include <stdlib.h>

int main()
{
	int a=1;
	int *p=&a;
	p=200;
	cout<<(*p);
	return 0;
}
