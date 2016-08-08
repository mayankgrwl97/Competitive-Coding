#include <bits/stdc++.h>
#define LL long long

using namespace std;

int arr[200100];

int left(int node, int n)
{
	return node==1 ? n : node-1;
}

int right(int node, int n)
{
	return node==n ? 1 : node+1;
}

LL func(int n, int start, int end)
{
	if(n==1)
		return 0;
	if(n==2)
		return arr[start];
	LL suml,sumr,minl,minr;
	suml = sumr = 0;
	minl = minr = LONG_MAX;

	int prev = left(start,n);
	while(prev != end)
	{
		suml += arr[prev];
		if(suml<minl)
			minl = suml;
		prev = left(prev,n);
	}
	suml += arr[prev];
	if(suml<minl)
		minl = suml;

	int curr = start;
	while(curr != end)
	{
		sumr += arr[curr];
		if(sumr<minr)
			minr = sumr;
		curr = right(curr,n);
	}
	// cout<<minl<<" "<<suml<<" "<<minr<<" "<<sumr<<" ";

	return min( min(suml,sumr) , min(2*minr+suml,2*minl+sumr) );
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t,n,sum;
	scanf("%d ",&t);
	int start,end;
	LL ans;
	while(t--)
	{
		sum = 0;
		scanf("%d ",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d ",arr+i);
		}
		scanf("%d %d ",&start,&end);
		ans = min(func(n,end,start),func(n,start,end));
		printf("%lld\n", ans);
		// cout<<func(n,start,end)<<endl;
		// cout<<n;
	}
	return 0;
}