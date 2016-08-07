#include <bits/stdc++.h>
using namespace std;

bool a[10010];//a[i] = 0 for prime and even nos.(!=2); a[i] = 1 for not prime 

int pow(int a, int b)
{
	int p = pow(a,b/2) * pow(a,b-b/2);
	return p;
}

void sieve()
{
	int k;

	a[0]=1; a[1]=1;

	for (int i=3; i<10010; i=i+2)
	{
		if(a[i] == 0)
		{
			for(int j=i*i; j<=10010; j=j+2*i)
				a[j]=1;
		}
	}
	a[4] = 0;
	for(int i=3; i<10010; i++)
	{
		if(a[i] == 0)
		{
			k = pow(i,i);
			if(k<=10000)
				a[k] = 0;
			else
				break;
		}
	}
}

int dp[10010];

void populate()
{
	
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{

	}
	return 0;
}