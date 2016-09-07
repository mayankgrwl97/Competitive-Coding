#include <bits/stdc++.h>
using namespace std;

double pre[300];

void precompute()
{
	int i=1;
	int n = 2;
	double sum = 0;

	while(sum<5.20)
	{
		sum = sum + 1.00/(double)n;
		pre[i] = sum;
		i++;
		n++;
	}

	// for(int j=1; j<i; j++)
	// 	cout<<j<<"\t"<<pre[j]<<'\n';
	return;
}

void func(double n)
{
	int i=1;
	while(pre[i] < n)
	{
		i++;
	}
	cout<<i<<" card(s)\n";
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	double n;
	scanf("%lf",&n);
	precompute();

	while(n > 0.00)
	{
		func(n);
		scanf("%lf",&n);
	}

	return 0;
}