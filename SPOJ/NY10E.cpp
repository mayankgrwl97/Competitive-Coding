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

LL dp[10][100];

void pre()
{
	for(int i=0; i<10; i++)
	{
		dp[i][1] = 1;
	}
	for(int i=2; i<=64; i++)
	{
		for(int j=0; j<10; j++)
		{
			dp[j][i] = 0;
			for(int k=j; k>=0; k--)
			{
				dp[j][i] += dp[k][i-1];
			}
		}
	}
	return;
}

LL func(int n)
{
	LL sum =0;

	for(int i=0; i<10; i++)
	{
		sum += dp[i][n];
	}
	cout<<sum<<endl;
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

	pre();
	while(t--)	
	{
		int i;
		int n;
		cin>>i>>n;
		cout<<i<<' ';
		func(n);
	}
	
	return 0;
}