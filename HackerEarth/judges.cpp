#include <bits/stdc++.h>
#define LL long long int
using namespace std;

LL score[10100];
LL dp[10100];

LL max(LL a, LL b)
{
	return (a>b ? a : b);
}

LL populate(int n)
{
	dp[1] = score[1];
	// dp[2] = max(score[1],score[2]);

	for(int i=2; i<=n; i++)
	{
		dp[i] = max(score[i] + dp[i-2], dp[i-1]);
	}
	return;
}

int main()
{
	int t,n;
	cin>>t;
	for(i=1; i<=t; i++)
	{
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			cin>>score[i];
		}
	}
	return 0;
}