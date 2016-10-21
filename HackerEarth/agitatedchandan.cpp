#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int> > graph[100100];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--)
	{
		cin>>n;
		cin>>a>>b>>c;
		graph[a].push_back(c);
		graph[b].push_back(c);
	}
	
	return 0;
}