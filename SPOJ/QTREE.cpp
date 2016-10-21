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
const int n_ = 1e4+1000;
const long double PI = acos(-1.0);

LL gcd (LL a, LL b) {return ( a ? gcd(b%a, a) : b );}
LL power(LL a, LL n) {LL p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
LL power(LL a, LL n, LL mod) {LL p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

vector<pii> graph[n_];
int subtree_size[n_];
bool visited[n_];
int parent[n_];
int edges[n_];

void dfs(int node)//populates the subtree sizes and parents arrays
{
	visited[node] = true;
	int n = graph[node].size();

	if(n==1 && visited[graph[node][0].X])
		subtree_size[node] = 1;

	int ct = 1;
	for(int i=0; i<n; i++)
	{
		int next = graph[node][i].X;
		if(!visited[next])
		{
			parent[next] = node;
			dfs(next);
			ct += subtree_size[next];
		}
	}
	subtree_size[node] = ct;
	return;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t,a,b,c;
	cin>>t;

	while(t--)	
	{
		int n;
		cin>>n;

		for(int i=1; i<=n-1; i++)
		{
			cin>>a>>b>>c;
			edges[i] = c;
			graph[a].pb(mp(b,i));
			graph[b].pb(mp(a,i));
		}
		dfs(1);
		for(int i=1; i<=n; i++)
			cout<<subtree_size[i]<<endl;
	}
	
	return 0;
}