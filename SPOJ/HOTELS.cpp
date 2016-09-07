#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL cost[300001];

void func(int n, LL m)
{
	LL max = LLONG_MIN;

	int st = 0;

	for(int i=1; i<=n; i++)
	{
		if(cost[i] - cost[st] > m)
		{
			while(cost[i] - cost[st] > m)
				st++;
		}
		if(max<(cost[i] - cost[st]))
			max = (cost[i] - cost[st]);
	}
	cout<<max;
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

	cost[0] = 0;
	cin>>cost[1];

	for(int i=2; i<=n; i++)
	{
		cin>>cost[i];
		cost[i]+=cost[i-1];
	}
	func(n,m);
	return 0;
}