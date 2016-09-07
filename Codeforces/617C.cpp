#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n;
	LL x1,x2,y1,y2,x,y;
	cin>>n>>x1>>y1>>x2>>y2;

	LL dis1[n];
	LL dis2[n];

	for(int i=0; i<n; i++)
	{
		cin>>x>>y;
		dis1[i] = (x-x1)*(x-x1) + (y-y1)*(y-y1);
		dis2[i] = (x-x2)*(x-x2) + (y-y2)*(y-y2);
	}
	
	LL r;
	LL ans = LLONG_MAX;
	LL max;

	r = 0;
	max = 0;
	for(int j=0; j<n; j++)
	{
		if(dis1[j] > r)
		{
			if(max<dis2[j])
				max = dis2[j];
		}
	}
	if(r+max<ans)
		ans = r+max;

	for(int i=0; i<n; i++)
	{
		max = 0;
		r = dis1[i];
		for(int j=0; j<n; j++)
		{
			if(dis1[j] > r)
			{
				if(max<dis2[j])
					max = dis2[j];
			}
		}
		if(r+max<ans)
			ans = r+max;
	}
	cout<<ans;
	return 0;
}