#include <bits/stdc++.h>
using namespace std;

int p[2001];

int dfs(int i)
{
	int ht = 1;
	while(p[i] != -1)
	{
		i = p[i];
		ht++;
	}
	return ht;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;


	for(int i=0; i<n; i++)
	{
		cin>>p[i+1];
	}
	int l;
	int max = 1;
	for(int i=1; i<=n; i++)
	{
		l = dfs(i);
		if(l>max)
			max = l;
	}
	cout<<max;
	return 0;
}