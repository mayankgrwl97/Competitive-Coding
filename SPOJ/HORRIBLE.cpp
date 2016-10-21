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
LL lazy[4*n_];

/*void build(int node, int start, int end)
{
	if(start > end)
		return;

	if(start == end)
	{
		segtree[node] = arr[start];
		return ;
	}

	int mid = (start + end)/2;
	int l = node<<1;
	int r = node<<1|1;

	build(l,start,mid);
	build(r,mid+1,end);

	segtree[node] = segtree[l] + segtree[r];

	return;
}*/

void update_lazy(LL node, LL start, LL end, LL li, LL ri, LL value)
{
	if(lazy[node] != 0)
	{
		segtree[node] += (end - start + 1)*lazy[node];
		if(start != end)
		{
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(start > end || start > ri || end < li)
		return ;

	if(start >= li && end <= ri)
	{
		segtree[node] += (end - start + 1)*value;
		if(start != end)
		{
			lazy[node<<1] += value;
			lazy[node<<1|1] += value;
		}
		return ;
	}

	LL mid = (start + end)/2;
	update_lazy(node<<1, start, mid, li, ri, value);
	update_lazy(node<<1|1, mid+1, end, li, ri, value);

	segtree[node] = segtree[node<<1] + segtree[node<<1|1];
	return ;
}

LL query_lazy(LL node, LL start, LL end, LL li, LL ri)
{
	if(start>end || start > ri || end < li)//no overlap
		return 0;

	if(lazy[node] != 0)
	{
		segtree[node] += (end - start + 1)*lazy[node];
		if(start != end)
		{
			lazy[node<<1] += lazy[node];
			lazy[node<<1|1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(start >= li && end <= ri)//partial overlap
		return segtree[node];

	//total overlap
	LL mid = (start + end)/2;
	return query_lazy(node<<1, start, mid, li, ri) + query_lazy(node<<1|1, mid+1, end, li, ri);
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--)	
	{
		LL n,c,p,q,v;
		cin>>n>>c;

		LL temp = 4*n+1000;
		for(LL i=0; i<temp; i++)
		{
			segtree[i] = 0;
			lazy[i] = 0;
		}

		while(c--)
		{
			cin>>p;
			if(p == 0)
			{
				cin>>p>>q>>v;
				// cout<<p<<q<<v<<endl;
				update_lazy(1,1,n,p,q,v);
			}
			else
			{
				cin>>p>>q;
				// cout<<p<<q<<endl;
				cout<<query_lazy(1,1,n,p,q)<<endl;
			}	
		}
	}
	return 0;
}