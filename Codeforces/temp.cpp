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
	cin>>n;

	bool a[n];

	for(int i=0; i<n; i++)
	{
		cin>>a[i];
		// cout<<a[i];
	}
	
	LL count = 1;
	int ft = -1;
	for(int i=0; i<n; i++)
	{
		if(a[i])
		{
			ft = i;
			break;
		}
	}

	if(ft == -1)
	{
		cout<<0;
		return 0;
	}

	for(int i=ft+1; i<n; i++)
	{
		if(a[i])
		{
			count = count * (i-ft);
			ft = i;
		}
	}
	cout<<count;
	return 0;
}