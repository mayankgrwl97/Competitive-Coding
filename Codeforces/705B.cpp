#include <bits/stdc++.h>
#define LL long long
using namespace std;

vector<LL> v;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,a;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>a;
		v.push_back(a);
	}
	if((v[0]-1)%2)
		cout<<1<<"\n";
	else
		cout<<2<<"\n";
	v[0]--;

	for(int i=1; i<n; i++)
	{
		v[i] += v[i-1] - 1;
		if(v[i]%2)
			cout<<1<<"\n";
		else
			cout<<2<<"\n";
	}
	
	return 0;
}