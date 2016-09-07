#include <bits/stdc++.h>
using namespace std;

int min5(int a, int b, int c, int d, int e)
{
	return min(e,min(min(a,b),min(c,d)));
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int x;
	cin>>x;

	int	dp[x+10];

	for(int i=1; i<=5; i++)
	{
		dp[i] = 1;
	}

	for(int i=6; i<=x; i++)
	{
		dp[i] = min5(dp[i-1],dp[i-2],dp[i-3],dp[i-4],dp[i-5]) + 1;
	}

	cout<<dp[x];

	return 0;
}