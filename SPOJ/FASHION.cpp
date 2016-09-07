#include <bits/stdc++.h>
using namespace std;

int men[1010];
int women[1010];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t,n,sum;
	cin>>t;

	while(t--)
	{
		sum = 0;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cin>>men[i];
		}
		for(int i=0; i<n; i++)
		{
			cin>>women[i];
		}
		sort(men,men+n);
		sort(women,women+n);
		// cout<<n;
		for(int i=0; i<n; i++)
		{
			sum = sum + (men[i] * women[i]);
			// cout<<men[i]<<' '<<women[i]<<'\n';
		}
		cout<<sum<<'\n';
	}
	
	return 0;
}