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

pair<LL,int> a[100100];
LL segtree[400400];
LL dp[400400];

// bool cmp(pair<LL,int> &a, pair<LL,int> &b)
// {
// 	if(a.first != b.first)
// 		return a.first<b.first;
// 	return a.second>b.second;
// }

bool cmp(pair<long long,int>& a,pair<long long,int>& b){
    if(a.first != b.first)
        return (a.first < b.first) ;
    return (a.second > b.second) ;
}

LL query(int node, int start, int end, int li, int ri)
{
	if(start>end || start>ri || end<li)
		return 0;

	if(li<=start && ri>=end)
		return segtree[node];

	int mid = (start+end)/2;
	LL left = query(node<<1, start, mid, li, ri);
	LL right = query(node<<1|1, mid+1, end, li, ri);
	return max(left,right);
}

void update(int node, int start, int end, int index, LL val)
{
	if(start>end || index<start || index > end)
		return ;
	if(index<start || index > end)//index not in start...end
		return ;
	if(start == end)//leaf node update
	{
		segtree[node] = val;
		return ;
	}
	//inner node update
	int mid = (start+end)/2;
	update(node<<1, start, mid, index, val);
	update(node<<1|1, mid+1, end, index, val);
	segtree[node] = max(segtree[node<<1] , segtree[node<<1|1]);
	return ;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	LL r,h;

	for(int i=0; i<n; i++)
	{
		cin>>r>>h;
		a[i].X = r*r*h;
		a[i].Y = -i;
	}

	// for(int i=0; i<n; i++)
	// 	cout<<a[i].X<<'\t';
	// cout<<endl;

	sort(a,a+n); //increasing order in X and decreasing order in Y


	LL ans = 0;
	for(int i=0; i<n; i++)
	{
		int idx = -(a[i].Y);
		LL tmp = query(1,0,n-1,0,idx) + a[i].X;
		update(1,0,n-1,idx,tmp);
		dp[idx] = tmp;
		if(dp[idx] > ans)
			ans = dp[idx];
	}

	// for(int i=0; i<n; i++)
	// 	cout<<dp[i]<<'\n';

	double answer = PI * (double)ans;
	printf("%0.9lf\n", answer);
	return 0;
}