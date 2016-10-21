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

vi graph[110];
vi rev[110];
bool visited[110];
stack<int> st;

void clean(int n)
{
	for(int i=0; i<n; i++)
	{
		graph[i].clear();
		rev[i].clear();
		visited[i] = false;
	}
	return ;
}

void dfs1(int node)
{
	visited[node] = true;
	int l = graph[node].size();

	for(int i=0; i<l; i++)
	{
		if(!visited[graph[node][i]])
			dfs1(graph[node][i]);
	}
	st.push(node);
	return;
}

void dfs2(int node)
{
	visited[node] = true;
	int l = rev[node].size();

	for(int i=0; i<l; i++)
	{
		if(!visited[rev[node][i]])
			dfs2(rev[node][i]);
	}

	return;
}

int scc(int n)
{
	for(int i=0; i<n; i++)
	{
		if(!visited[i])
			dfs1(i);
	}
	for(int i=0; i<n; i++)
		visited[i] = false;

	int ct = 0;
	while(!st.empty())
	{
		int curr = st.top();
		st.pop();

		if(visited[curr])
			continue;

		dfs2(curr);
		ct++;
	}
	return ct;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t;
	string str;
	cin>>t;

	while(t--)	
	{
		int n;
		cin>>n;
		clean(n);
		for(int i=0; i<n; i++)
		{
			cin>>str;
			for(int j=0; j<n; j++)
				if(str[j] == 'Y')
				{
					graph[i].pb(j);
					rev[j].pb(i);
				}
		}
		cout<<scc(n)<<endl;
	}
	
	return 0;
}