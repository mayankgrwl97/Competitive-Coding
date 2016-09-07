#include <bits/stdc++.h>
using namespace std;

vector<int> graph[10010];
int visited[10010];

void dfsUtil(int a)
{
	visited[a] = 1;
	int l = graph[a].size();

	for(int i=0; i<l; i++)
	{
		if(!visited[graph[a][i]])
			dfsUtil(graph[a][i]);
	}

	return ;
}

int dfs(int start, int n)
{
	for(int i=1; i<=n; i++)
	{
		visited[i] = 0;
	}
	dfsUtil(start);
	for(int i=1; i<=n; i++)
	{
		if(!visited[i])
			return 0;
	}
	return 1;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,m,u,v;
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	if(m != n-1)
	{
		cout<<"NO\n";
		return 0;
	}

	int flag = dfs(1,n);
	if(flag)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}