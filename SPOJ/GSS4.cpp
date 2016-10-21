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

LL segtree[4*n_];
int lazy[4*n_];
LL arr[n_];

void build(int node, int start, int end)
{
	if(start>end)
		return ;
	if(start == end)
		segtree[node] = arr[start];

	int mid = (start+end)/2;
	build(node<<1, start, mid);
	build(node<<1|1, mid+1, end);
	segtree[node] = segtree[node<<1] + segtree[node<<1|1];
		
	return ;
}

void update_lazy(int node, int start, int end, int l, int r)
{
	if(lazy[node] != 0)
	{
		for(int i=; i<n; i++)
		{

		}

		if(start!=end)
		{
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
		}
		lazy[node] = 0;
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

	
	
	return 0;
}