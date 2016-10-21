#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define scani(n) scanf("%d",&n);
#define MOD (ll)1000000007
#define endl '\n'
#define EPS 1e-9
#define FOR(i,n) for(int i=0; i<n; i++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int ht[100100];
int height[100100];
vi graph[100100];

void dfsUtil(int i)
{
	static int max = INT_MIN;

	if(ht[i] == -1)
	{
		if(max<ht[i])
			max = ht[i];
		return ;
	}

	for(int j=0; j<graph[i].size(); j++)
		dfsUtil(graph[i][j]);

	if(max<height[i])
		max = height[i];
	if(ht[i] < max)
		ht[i] = max;
	return ;
}

void dfs(int n)
{
	for(int i=1; i<=n; i++)
		ht[i] = -1;
	for(int i=1; i<=n; i++)
		dfsUtil(i);
	for(int i=1; i<=n; i++)
		cout<<ht[i]<<'\t';
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t,a,b;
	cin>>t;

	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i=1; i<=n; i++)
			graph[i].clear();
		for(int i=0; i<n; i++)
			cin>>height[i];
		for(int i=0; i<m; i++)
			cin>>a>>b,graph[a].pb(b);
		dfs(n);
	}
	
	return 0;
}