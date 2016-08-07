#include <bits/stdc++.h>
#define LL long long int
using namespace std;

int ip[100100];
LL dp[100100];

void populate(int n, int k)
{
	LL max;
	if(ip[1] <= k)
		dp[1] = max = (LL)ip[1];
	else
		dp[1] = max = 0;
	for(int i=2; i<=n; i++)
	{
		if(ip[i] <= k)
			dp[i] = dp[i-1] + (LL)ip[i];
		else
			dp[i] = 0;
		if(dp[i] > max)
			max = dp[i];
	}
	printf("%lld\n", max);
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",ip+i);
		}
		populate(n,k);
	}
	return 0;
}