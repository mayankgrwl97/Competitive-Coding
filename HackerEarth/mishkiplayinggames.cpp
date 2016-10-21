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
const int n_ = 1e6+10;
const long double PI = acos(-1.0);

LL gcd (LL a, LL b) {return ( a ? gcd(b%a, a) : b );}
LL power(LL a, LL n) {LL p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
LL power(LL a, LL n, LL mod) {LL p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

int a[n_];
int dp[n_];

void func(int n)
{
	dp[0] = log2(a[0]) + 1;
	for(int i=1; i<n; i++)
		dp[i] = dp[i-1] + log2(a[i]) + 1;
	return;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,q;
	cin>>n>>q;
	for(int i=0; i<n; i++)
		cin>>a[i];
	func(n);
	for(int i=0; i<q; i++)
	{
		int l,r,ct;
		cin>>l>>r;
		l--;
		r--;
		if(l==0)
			ct = dp[r];
		else
			ct = dp[r] - dp[l-1];
		if(ct%2)
			cout<<"Mishki"<<endl;
		else
			cout<<"Hacker"<<endl;
	}
	
	return 0;
}