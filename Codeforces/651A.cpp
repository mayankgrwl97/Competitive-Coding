#include <bits/stdc++.h>
using namespace std;

int dp[1000][1000];

int func(int a1,int a2)
{
	if(a1 == 0 || a2 == 0)
		return 0;
	if(a1 == 1 && a2 == 1)
		return 0;
	if(a1 == 1)
	{
		if(!dp[a1+1][a2-2])
			dp[a1+1][a2-2] = func(a1+1,a2-2);
		return 1 + dp[a1+1][a2-2];
	}
	if(a2 == 1)
	{
		if(!dp[a1-2][a2+1])
			dp[a1-2][a2+1] = func(a1-2,a2+1);
		return 1 + dp[a1-2][a2+1];
	}
	else
	{
		if(!dp[a1+1][a2-2])
			dp[a1+1][a2-2] = func(a1+1,a2-2);
		if(!dp[a1-2][a2+1])
			dp[a1-2][a2+1] = func(a1-2,a2+1);
		return 1 + max(dp[a1+1][a2-2], dp[a1-2][a2+1]);
	}
}

/*int func(int a1, int a2)
{
	for(int i=0; i<1000; i++)
		dp[0][i] = dp[i][0] = 0;
	dp[1][1] = 0;

}*/

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	int a1,a2;
	cin>>a1>>a2;
	int n = func(a1,a2);
	cout<<n;
}