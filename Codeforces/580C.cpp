#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int a[100100];
vector<int> graph[100100];
int visited[100100];
int previous[100100];
int ms[100100];

int ans = 0;
int m = 0;
int up;
void dfs(int root)
{
	int l = graph[root].size();
	ms[root] = a[root] + ms[previous[root]] * a[root];
	if(ms[root]>up)
		return ;
	visited[root] = 1;
	if(l==1 && visited[graph[root][0]])//leaf node
	{
		ans++;
	}
	else
	{
		for(int i=0; i<l; i++)
		{
			if(!visited[graph[root][i]])
			{
				previous[graph[root][i]] = root;
				dfs(graph[root][i]);
			}	
		}
	}
	return ;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n>>up;

	for(int i=1; i<=n; i++)
		cin>>a[i];
	a[0] = 1;
	previous[1] = 0;
	ms[0] = 0;

	int x,y;
	for(int i=0; i<n-1; i++)
	{
		cin>>x>>y;
		graph[x].pb(y);
		graph[y].pb(x);
	}

	dfs(1);
	cout<<ans;

	// for(int i=1; i<=n; i++)
	// 	cout<<i<<' '<<ms[i]<<'\n';

	return 0;
}