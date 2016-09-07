#include <bits/stdc++.h>
using namespace std;

int ht[20000];

void func(int n, int k)
{
	int min = INT_MAX;

	sort(ht, ht+n);

	for(int i=0; i<=n-k; i++)
	{
		if((ht[i+k-1] - ht[i]) < min)
			min = ht[i+k-1] - ht[i];
		// cout<<min<<'\n';
	}

	cout<<min<<'\n';

	return;
}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	
	int t,n,k;
	scanf("%d",&t);
	
	while(t--)
	{
		cin>>n>>k;
		for(int i=0; i<n; i++)
		{
			cin>>ht[i];
		}
		func(n,k);
	}
	
	return 0;
}