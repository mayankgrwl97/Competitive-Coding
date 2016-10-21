#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define scani(n) scanf("%d",&n);
#define endl '\n'
#define EPS 1e-9
#define FOR(i,n) for(int i=0; i<n; i++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define X first
#define Y second
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define forr(i,n) for(int i=n-1; i>=0; i--)

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int MOD = 1e9+7;
const int n_ = 1e5+1000;
const long double PI = acos(-1.0);

LL gcd (LL a, LL b) {return ( a ? gcd(b%a, a) : b );}
LL power(LL a, LL n) {LL p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
LL power(LL a, LL n, LL mod) {LL p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

vi graph[n_];//stores original graph
vi rev[n_];//stores reversed graph
bool visited[n_];
stack<int> st;
int component[n_];//stores component no of each vertex
set<pii > mst;//stores set of edges in compressed graph
vi comp[n_];//compressed graph
int outdegree[n_];//indegree of nodes in compressed graph

void clean(int n)
{
	for(int i=1; i<=n; i++)
	{
		graph[i].clear();
		rev[i].clear();
		visited[i] = false;
		comp[i].clear();
		outdegree[i] = 0;
	}
	mst.clear();
	return;
}

void dfs1(int i)
{
	visited[i] = true;
	int l=graph[i].size();

	for(int j=0; j<l; j++)
	{
		if(!visited[graph[i][j]])
			dfs1(graph[i][j]);
	}

	st.push(i);
	return ;
}

void dfs2(int i, int ct)
{
	visited[i] = true;
	component[i] = ct;
	int l = rev[i].size();

	for(int j=0; j<l; j++)
	{
		if(!visited[rev[i][j]])
			dfs2(rev[i][j],ct);
	}
	return ;
}

int scc(int n)
{
	for(int i=1; i<=n; i++)
	{
		if(!visited[i])
			dfs1(i);
	}

	for(int i=1; i<=n; i++)
		visited[i] = false;

	int ct = 1;
	while(!st.empty())
	{
		int curr = st.top();
		st.pop();
		if(visited[curr])
			continue;
		dfs2(curr,ct);
		ct++;
	}

	return ct-1;
}

void compress(int n)
{
	int a,b;
	for(int i=1; i<=n; i++)
	{
		for(int j=0; j<graph[i].size(); j++)
		{
			a = component[i];
			b = component[graph[i][j]];
			if( (a != b) && !mst.count(mp(a,b)))
			{
				mst.insert(mp(a,b));
				comp[a].pb(b);
				outdegree[a]++;
			}
		}
	}
	return ;
}


int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,m,a,b;
	cin>>n;
	while(n!=0)
	{
		cin>>m;
	
		clean(n);
		for(int i=0; i<m; i++)	
		{
			cin>>a>>b;
			graph[a].pb(b);
			rev[b].pb(a);
		}
		
		scc(n);
		compress(n);

		for(int i=1; i<=n; i++)
		{
			if(outdegree[component[i]] == 0)
				cout<<i<<' ';
		}
		cout<<endl;

		cin>>n;		
	}
	return 0;
}