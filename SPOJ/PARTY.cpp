#include <bits/stdc++.h>
using namespace std;

int dp[100][501];
int fee[100];
int fun[100];

int func(int budg, int n)
{
	for(int i=0; i<=budg; i++)
	{
		if(i<fee[0])
			dp[0][i] = 0;
		else
			dp[0][i] = fun[0];
	}

	for(int i=1; i<n; i++)
	{
		for(int j=0; j<=budg; j++)
		{
			if(j<fee[i])
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j-fee[i]] + fun[i], dp[i-1][j]);
		}
	}
/*
	int ans = 0;
	int j = budg;
	for(int i=n-1; i>=1; i--)
	{
		if(dp[i][j] != dp[i-1][j])
		{
			ans += fee[i];
			j = j - fee[i];
		}
	}

	if(dp[0][j] != 0)
		ans += fee[0];
*/

	int ans;
	for(int i=0; i<=budg; i++)
	{
		if(dp[n-1][i] == dp[n-1][budg])
		{
			ans = i;
			break;
		}
	}
	cout<<ans<<' '<<dp[n-1][budg]<<'\n';
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int budg,n;
	cin>>budg>>n;

	while(budg != 0 || n != 0)
	{
		for(int i=0; i<n; i++)
		{
			cin>>fee[i]>>fun[i];
		}

		func(budg,n);
		cin>>budg>>n;
	}

	
	return 0;
}