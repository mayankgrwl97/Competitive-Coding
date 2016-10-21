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

vi graph[n_];
bool visited[n_];
int dist[n_];

void clean(int n)
{
	for(int i=0; i<n; i++)
	{
		graph[i].clear();
	}
	return ;
}

void func(int n)
{
	for(int i=0; i<n; i++)
		visited[i] = false;

	visited[0] = true;
	queue<int> q;
	q.push(0);
	int curr,next;
	while(!q.empty())
	{
		curr = q.front();
		q.pop();
		for(int i=0; i<graph[curr].size(); i++)
		{
			next = graph[curr][i];
			if(!visited[next])
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
	for(int i=0; i<n; i++)
		visited[i] = false;

	visited[curr] = true;
	q.push(curr);
	dist[curr] = 0;

	while(!q.empty())
	{
		curr = q.front();
		q.pop();
		for(int i=0; i<graph[curr].size(); i++)
		{
			next = graph[curr][i];
			if(!visited[next])
			{
				visited[next] = true;
				dist[next] = dist[curr] + 1;
				q.push(next);
			}
		}
	}
	int ans = dist[curr];

	if(ans%2 == 0)
	{
		cout<<(ans/2)<<endl;
	}
	else
	{
		cout<<((ans/2)+1)<<endl;
	}

	// cout<<dist[curr]<<endl;
	return;
}


int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t,n,a,b;
	cin>>t;

	while(t--)
	{
		cin>>n;
		clean(n);
		for(int i=0; i<n-1; i++)
		{
			cin>>a>>b;
			graph[a].pb(b);
			graph[b].pb(a);
		}
		func(n);
	}
	
	return 0;
}