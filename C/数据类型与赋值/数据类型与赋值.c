#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
	float r,s,v;
	const double pi=3.14;
	cin>>r;;
	v=4/3.0*pi*r*r*r;
	cout<<srtprecision(2);
	cout<<setw(10)<<srtiosflags(ios:fixed)<<v;
	return 0;
}
