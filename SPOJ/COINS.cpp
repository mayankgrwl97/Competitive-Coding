#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL dp[100000001];

void precompute() // n/2 n/3 n/4
{
	int n = 100000000;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;

	LL temp;

	for(LL i=5; i<=n; i++)
	{
		temp = dp[i/2] + dp[i/3] + dp[i/4];
		dp[i] = max(i,temp);
	}
	return;
}

LL func(LL n)
{

	if(n<=100000000)
		return dp[n];
	LL temp = func(n/2) + func(n/3) + func(n/4);
	return max(temp,n);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	LL n;

	precompute();

	while(scanf("%lld",&n) != EOF)	
	{
		cout<<func(n)<<'\n';
		// process(n);
	}
	
	return 0;
}