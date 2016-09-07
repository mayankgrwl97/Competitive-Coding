#include <bits/stdc++.h>
using namespace std;

int arr[100][100];
int dp[100][100];

void func(int n, int m)
{
	int ans=0;
	if(m<2)
	{
		for(int i=0; i<n; i++)
			ans += arr[i][0];
			cout<<ans<<'\n';
		return ;
	}
	for(int i=0; i<m; i++)
	{
		dp[n-1][i] = arr[n-1][i];
	}

	for(int i=n-2; i>=0; i--)
	{
		dp[i][0] = min(dp[i+1][0] ,dp[i+1][1]) + arr[i][0];
		dp[i][m-1] = min(dp[i+1][m-2], dp[i+1][m-1]) + arr[i][m-1];
		for(int j=1; j<m-1; j++)
		{
			dp[i][j] = arr[i][j] + min(dp[i+1][j], min(dp[i+1][j-1], dp[i+1][j+1]));
		}
	}
	ans = INT_MAX;
	for(int i=0; i<m; i++)
	{
		if(ans>dp[0][i])
			ans = dp[0][i];
	}

	cout<<ans<<'\n';
	return ;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>arr[i][j];
		}
	}

	func(n,m);
	
	return 0;
}