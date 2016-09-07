#include <bits/stdc++.h>
using namespace std;

int coins[50];
bool dp[1000100];

void func(int k, int l, int v)
{
	dp[1] = true;

	if(k<l)
	{
		for(int i=2; i<k; i++)
		{
			dp[i] = !dp[i-1];
		}
		dp[k] = true;
		for(int i=k+1; i<l; i++)
		{
			if(!dp[i-k] || !dp[i-1])
				dp[i] = true;
			else
				dp[i] = false;
		}
		dp[l] = false;
	}

	return ;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int k,l,m;
	cin>>k>>l>>m;

	for(int i=0; i<m; i++)
	{
		cin>>coins[i];
	}
	
	return 0;
}