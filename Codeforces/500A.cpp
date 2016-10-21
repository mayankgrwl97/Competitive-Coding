#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,t;
	cin>>n>>t;

	int a[n];
	for(int i=0; i<n-1; i++)
	{
		cin>>a[i+1];
		// cout<<a[i+1];
	}
	// int curr = 1;
	int next = 1+a[1];
	// cout<<a[2];
	if(t==1 || next == t)
	{
		cout<<"YES";
		return 0;
	}
	while(next < n)
	{
		next = next + a[next];
		if(next == t)
		{
			cout<<"YES";
			return 0;
		}
	}
	cout<<"NO";
	return 0;
}