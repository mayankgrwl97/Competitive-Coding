#include <bits/stdc++.h>
#define inf 100000
using namespace std;

int dp[120];

int min(int a, int b)
{
	return (a<b ? a : b);
}

void populate()
{
	int m,n;

	for(int i=0; i<10; i++)
	{
		dp[i] = -1;
	}
	dp[10] = 1;
	dp[11] = -1;
	dp[12] = 1;

	for(int i=13; i<=120; i++)
	{
		if(dp[i-10] != -1)
			m = dp[i-10] + 1;
		else
			m = inf;
		if(dp[i-12] != -1)
			n = dp[i-12] + 1;
		else
			n = inf;
		if(dp[i-10] == -1 && dp[i-12] == -1)
			dp[i] = -1;
		else
			dp[i] = min(m,n);
	}
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t,n;
	cin>>t;
	populate();
	while(t--)
	{
		cin>>n;
		printf("%d\n", dp[n]);
	}
	return 0;
}