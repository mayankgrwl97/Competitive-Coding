#include <bits/stdc++.h>
#define pii pair<int,int>
#define LL long long
#define vi vector<int>
#define mp make_pair
#define pb push_back
using namespace std;

vector<pair<int,int> > graph[1010];

void func(int n, int m, int p)
{
	set<int> myset;
	set<pii > vertices;
	set<pii >::iterator it;
	pii temp;

	for(int i=1; i<=n; i++)
	{
		vertices.insert(mp(INT_MAX,i));
	}

	it = vertices.begin();
	temp = *it;
	vertices.erase(it);
	temp.first = 0;

	vertices.insert(temp);
	it = vertices.begin();

	while(myset.size() != n)
	{
		it = vertices.begin();
		temp = *it;

		if(temp.second)
	}

	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;
	int a,b,c,p,n,m;

	while(t--)
	{
		cin>>p>>n>>m;
		for(int i=1; i<=m; i++)
		{
			cin>>a>>b>>c;
			graph[a].push_back(make_pair(b,c));
			graph[b].push_back(make_pair(a,c));
		}
		func(n,m,p);
	}
	
	return 0;
}