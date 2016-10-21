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

int indegree[n_];
int parent[n_];
vi graph[n_];

void func(int n)
{
	queue<int> q;
	for(int i=1; i<=n; i++)
	{
		// cout<<indegree[i]<<endl;
		if(indegree[i] == 0)
		{
			parent[i] = 0;
			q.push(i);
			break;
		}
	}
	// cout<<q.front();

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		for(int i=0; i<graph[curr].size(); i++)
		{
			indegree[graph[curr][i]]--;
			if(indegree[graph[curr][i]] == 0)
			{
				parent[graph[curr][i]] = curr;
				q.push(graph[curr][i]);
			}
		}
	}

	for(int i=1; i<=n; i++)
	{
		cout<<parent[i]<<endl;
	}

	return;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,k;
	int w,y;
	cin>>n>>k;

	for(int i=1; i<=k; i++)
	{
		cin>>w;
		for(int j=0; j<w; j++)
		{
			cin>>y;
			graph[i].pb(y);
			indegree[y]++;
			// rev[i].pb(x);
		}
	}

	func(n);

	return 0;
}