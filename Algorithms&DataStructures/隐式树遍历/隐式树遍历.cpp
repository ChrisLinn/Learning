#include<iostream>
using namespace std;
const int MAXN=1000+10;
int cur=0,end=0;
int queue[MAXN],sFA[MAXN],record[MAXN];
void ADD();
void SUB();
void MUL();
void DIV();
void DUP();
void print();
int main()
{
	queue[0]=1;
	sFA[0]=-1;
	for(;queue[end]!=2;cur++)
	{
		ADD();
		SUB();
		MUL();
		DIV();
		DUP();
	}
	print();
	return 0;
}
void ADD()
{
	if(sFA[cur]!=-1)
	{
		queue[++end]=queue[sFA[cur]]+queue[cur];
		if(queue[end]>30000||queue[end]<-30000)
		{
			sFA[end]=sFA[sFA[cur]];
			record[end]=100000*sFA[cur]+1000+cur;
		}
	}
}
void SUB()
{
	if(sFA[cur]!=-1)
	{
		queue[++end]=queue[sFA[cur]]-queue[cur];
		if(queue[end]>30000||queue[end]<-30000)
		{
			sFA[end]=sFA[sFA[cur]];
			record[end]=100000*sFA[cur]+2000+cur;
		}
	}
}
void MUL()
{
	if(sFA[cur]!=-1)
	{
		queue[++end]=queue[sFA[cur]]*queue[cur];
		if(queue[end]>30000||queue[end]<-30000)
		{
			sFA[end]=sFA[sFA[cur]];
			record[end]=100000*sFA[cur]+3000+cur;
		}
	}
}
void DIV()
{
	if(sFA[cur]!=-1&&queue[cur]!=0)
	{
		queue[++end]=queue[sFA[cur]]/queue[cur];
		if(queue[end]>30000||queue[end]<-30000)
		{
			sFA[end]=sFA[sFA[cur]];
			record[end]=100000*sFA[cur]+4000+cur;
		}
	}
}
void DUP()
{
	
	queue[++end]=queue[cur];
	sFA[end]=cur;
	record[end]=100000*cur+5000+cur;	
}
void print()
{
	int i,j,k;
	i=record[end]/100000;
	j=(record[end]%10000)/1000;
	k=record[end]%100;
	for(;k!=0;i=record[end]/100000,j=(record[end]%10000)/1000,k=record[end]%100)
	{
		if(j!=5) cout<<queue[i]<<" "<<j<<" "<<queue[k]<<"="<<queue[end]<<endl;
		else cout<<queue[i]<<" "<<j<<"-->"<<queue[end]<<endl;	
		end=k;
	}
}