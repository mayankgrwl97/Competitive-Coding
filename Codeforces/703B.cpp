#include <bits/stdc++.h>
#define LL long long int
using namespace std;

int nxt(int i, int n)
{
	return (i%n) + 1;
}

int prev(int i, int n)
{
	return (i==1 ? n : i-1);
}

LL func(int n, int k, int beauty[], int indices[], int iscapital[])
{
	LL sum = 0, temp_sum = 0, temp_sum2;
	for(int i=1; i<=n-1; i++)
		sum += (LL)(beauty[i] * beauty[i+1]);
	sum += (LL)(beauty[1] * beauty[n]);

	// cout<<sum<<'\n';

	for(int i=0; i<k; i++)
	{
		temp_sum += (LL)beauty[indices[i]];
	}

	// cout<<temp_sum<<'\n';

	temp_sum2 = temp_sum;

	for(int i=1; i<=n; i++)
	{
		if(!iscapital[i])
		{
			sum += (LL)(beauty[i] * temp_sum);
			if(iscapital[nxt(i,n)])
				sum -= (LL)(beauty[i] * beauty[nxt(i,n)]);
		// cout<<"i="<<i<<' '<<"sum="<<sum<<'\n';
			if(iscapital[prev(i,n)])
				sum -= (LL)(beauty[i] * beauty[prev(i,n)]);
		}
		else
		{
			temp_sum2 -= beauty[i];
			sum += (LL)(beauty[i] * temp_sum2);
			if(iscapital[nxt(i,n)] && nxt(i,n) > i)
				sum -= (LL)(beauty[i] * beauty[nxt(i,n)]);
			if(iscapital[prev(i,n)] && prev(i,n) > i)
				sum -= (LL)(beauty[i] * beauty[prev(i,n)]);
		}
	}

	return sum;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n, k;
	cin>>n>>k;

	int beauty[n+1];
	int indices[k];
	int iscapital[n+1];

	for(int i=1; i<=n; i++)
	{
		cin>>beauty[i];
		iscapital[i] = 0;
	}

	for(int i=0; i<k; i++)
	{
		cin>>indices[i];
		iscapital[indices[i]] = 1;
	}
	
	LL ans = func(n,k,beauty,indices,iscapital);
	cout<<ans<<'\n';
	// cout<<iscapital[prev(1,4)];
	return 0;
}