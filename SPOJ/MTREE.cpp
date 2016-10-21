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

LL sum = 0;
vector<pii > tree[n_];
bool visited[n_];

LL dfs(int node)
{
	visited[node] = true;
	int l = tree[node].size();
	if(l==1 && visited[tree[node][0].X])//leafnode
		return 0;
	LL temp1 = 0;
	LL temp2 = 0;

	for(int i=0; i<l; i++)
	{
		int nextnode = tree[node][i].X;
		LL nextweight = tree[node][i].Y;
		if(!visited[nextnode])
		{
			LL temp3 = dfs(nextnode);
			LL temp4 = (nextweight*(1+temp3))%MOD;
			temp2 = temp2 + (temp1 * temp4)%MOD;
			temp1 = (temp1 + temp4)%MOD;
		}
	}

	sum = (sum+temp2)%MOD;
	sum = (sum+temp1)%MOD;

	return temp1;
}

void func(int n)
{
	if(n==1)
	{
		cout<<0;
		return;
	}

	dfs(1);
	cout<<sum;

	return ;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,a,b,w;
	cin>>n;

	for(int i=1; i<n; i++)	
	{
		cin>>a>>b>>w;
		tree[a].pb(mp(b,w));
		tree[b].pb(mp(a,w));
	}
	
	func(n);

	return 0;
}