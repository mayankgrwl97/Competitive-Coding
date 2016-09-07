#include <bits/stdc++.h>
#define LL long long
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;

	LL n, sum, a;

	while(t--)
	{
		sum = 0;
		cin>>n;
		for(LL i=0; i<n; i++)
		{
			cin>>a;
			sum += a;
			if(sum>=n)
				sum = sum%n;
		}
		if(sum>0)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
		}
	}
	
	return 0;
}