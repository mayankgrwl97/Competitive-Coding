#include <bits/stdc++.h>
using namespace std;

int prime[] = {2,3,5,7};

int dp[1000010];

int min1(int a, int b)
{
	return (a<b ? a : b);
}

int min(int a, int b, int c, int d)
{
	return (min1(a,b) < min1(c,d) ? min1(a,b) : min1(c,d));
}

void populate()
{
	dp[0] = dp[1] = -1;
	dp[2] = dp[3] = dp[5] = dp[7] = 1;
	dp[4] = dp[6] = dp[8] = dp[9] = 2;
	for(int i=10; i<=1000000; i++)
	{
		dp[i] = 1 + min(dp[i-2],dp[i-3], dp[i-5],dp[i-7]);
	}
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t,x;
	cin>>t;
	populate();
	while(t--)
	{
		scanf("%d",&x);
		printf("%d\n", dp[x]);
	}
	return 0;
}