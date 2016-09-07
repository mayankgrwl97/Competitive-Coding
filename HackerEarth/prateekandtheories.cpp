#include <bits/stdc++.h>
using namespace std;

vetor< pair<int,int> > v;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	int a,b,n;

	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cin>>a>>b;
			v.push_back(make_pair(a,b));
		}
	}
	
	return 0;
}