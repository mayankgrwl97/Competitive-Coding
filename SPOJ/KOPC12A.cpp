#include <bits/stdc++.h>
#define LL long long
using namespace std;

int ht[10000];
int cost[10000];

int isincreasing(int h, int n)
{
	LL cst = 0;
	for(int i=0; i<n; i++)
	{
		cst += 1LL * abs(ht[i] - h) * cost[i];
	}
	LL cst2 = 0;
	h++;
	for(int i=0; i<n; i++)
	{
		cst2 += 1LL * abs(ht[i] - h) * cost[i];
	}
	if(cst2>cst)
		return 1;
	return 0;
}

void func(int n, int min, int max)
{
	int lo = min;
	int hi = max;
	int mid,t;
	LL ans;
	while(lo<hi)
	{
		mid = (lo+hi)/2;
		t = isincreasing(mid, n);
		// cout<<mid<<' '<<t<<' '<<cst<<'\n';
		if(t)
		{
			hi = mid;
		}
		else
			lo = mid+1;
	}

	ans = 0;
	for(int i=0; i<n; i++)
	{
		ans += 1LL * abs(ht[i] - lo) * cost[i];
	}

	cout<<ans<<'\n';

	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t,n;
	cin>>t;
	int min,max;
	while(t--)
	{
		min = INT_MAX;
		max = INT_MIN;

		cin>>n;
		for(int i=0; i<n; i++)
		{
			cin>>ht[i];
			if(min>ht[i])
				min = ht[i];
			if(max<ht[i])
				max = ht[i];
		}
		for(int i=0; i<n; i++)
		{
			cin>>cost[i];
		}
		func(n,min,max);
	}
	
	return 0;
}