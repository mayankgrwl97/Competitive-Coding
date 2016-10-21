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

vi graph[n_];
int indegree[n_];
bool vis[n_];
bool track[n_];

void clean(int n)
{
	for(int i=1; i<=n; i++)
	{
		graph[i].clear();
		indegree[i] = 0;
		vis[i] = false;
		track[i] = false;
	}
	return ;
}


bool dfs(int node)
{
	vis[node] = true;
	track[node] = true;

	for(int i=0; i<graph[node].size(); i++)
	{
		if(track[graph[node][i]])
			return false;
		if(!vis[graph[node][i]])
		{
			bool a = dfs(graph[node][i]);
			if(!a)
				return false;
		}
	}
	track[node] = false;
	return true;
}

bool checkcycle(int n)
{
	for(int i=1; i<=n; i++)
	{
		if(!vis[i])
		{
			bool a = dfs(i);
			if(!a)
				return true;
		}
	}
	return false;
}

void func(int n)
{
	if(checkcycle(n))
	{
		cout<<"recheck hints\n";
		return ;
	}

	queue<int> q;
	queue<int> ans;
	for(int i=1; i<=n; i++)
	{
		if(indegree[i] == 0)
			q.push(i);
	}

	int visited = 0;
	while(!q.empty())
	{
		if(q.size()>1)
		{
			cout<<"missing hints\n";
			return ;
		}
		int curr = q.front();
		q.pop();
		ans.push(curr);
		visited++;
		for(int i=0; i<graph[curr].size(); i++)
		{
			indegree[graph[curr][i]]--;
			if(indegree[graph[curr][i]] == 0)
				q.push(graph[curr][i]);
		}
	}

	if(visited != n)
	{
		cout<<"recheck hints\n";
		return ;
	}

	while(!ans.empty())
	{
		cout<<ans.front()<<' ';
		ans.pop();
	}
	cout<<endl;
	return ;

}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t,n,h,a,b;
	cin>>t;

	while(t--)	
	{
		cin>>n>>h;
		clean(n);
		for(int i=0; i<h; i++)
		{
			cin>>a>>b;
			graph[a].pb(b);
			indegree[b]++;
		}
		func(n);
	}
	
	return 0;
}