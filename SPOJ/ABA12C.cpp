#include <bits/stdc++.h>
using namespace std;

int prices[101];
int dp[101];

void func(int n, int k)
{
	dp[0] = 0;
	dp[1] = prices[1];
	int temp;
	for(int i=2; i<=k; i++)
	{
		dp[i] = prices[i];

		for(int j=1; j<i; j++)
		{
			if(dp[j] != INT_MAX && dp[i-j] != INT_MAX)
			{
				temp = dp[j] + dp[i-j];
				if(temp<dp[i])
					dp[i] = temp;
			}
		}
	}
	if(dp[k] == INT_MAX)
		cout<<-1<<'\n';
	else
		cout<<dp[k]<<'\n';
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	
	int t,n,k;
	scanf("%d",&t);
	
	while(t--)
	{
		cin>>n>>k;
		for(int i=1; i<=k; i++)
		{
			cin>>prices[i];
			if(prices[i] == -1)
				prices[i] = INT_MAX;
		}
		func(n,k);
	}
	
	
	return 0;
}