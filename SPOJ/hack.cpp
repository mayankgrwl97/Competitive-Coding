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

vi graph[25];
int indegree[25];

void func(int n, int m, int k)
{
	queue<pair<int,int> > q;
	set<int> sets[25];

	for(int i=1; i<=n; i++)
	{
		if(indegree[i] == 0)
			q.push(mp(i,0));
	}

	while(!q.empty())
	{
		pii curr = q.front();
		q.pop();
		sets[curr.Y].insert(curr.X);
		for(int i=0; i<graph[curr.X].size(); i++)
		{
			indegree[graph[curr.X][i]]--;
			if(indegree[graph[curr.X][i]] == 0)
			{
				q.push(mp(graph[curr.X][i],1+curr.Y));
			}
		}
	}

	set<int>::iterator it;

	int i=0;
	while(sets[i].size())
	{
		for(it=sets[i].begin(); it!=sets[i].end(); it++)
			cout<<*it<<' ';
		cout<<endl;
		i++;
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

	int n,m,k,x,y;
	cin>>n>>m>>k;

	for(int i=0; i<m; i++)
	{
		cin>>x>>y;
		graph[x].pb(y);
		indegree[y]++;
	}

	func(n,m,k);
	
	return 0;
}