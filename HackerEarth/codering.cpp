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

bool a[100];//a[i] = 0 for prime and even nos.(!=2); a[i] = 1 for not prime 
vector<int> p;

void sieve()//p is the vector which stores the primes starting from p[1] = 2.
{
	p.push_back(0);
	a[0]=1; a[1]=1;
	p.push_back(2);//p[1] = 2; => 1st prime

	for (long long i=3; i<100; i=i+2)
	{
		if(a[i] == 0)
		{
			p.push_back(i);
			for(long long j=i*i; j<=100; j=j+2*i)
				a[j]=1;
		}
	}
	return ;
}

bool isprime[10][10];

bool prime(int n)
{
	if(n==2)
		return true;
	if(n<2)
		return false;
	if(n%2 == 0)
		return false;
	return !a[n];
}

LL dp[10][100100];

void pre(int n)
{
	for(int i=0; i<10; i++)
	{
		for(int j=0; j<10; j++)
		{
			if(prime(i+j))
			{
				isprime[i][j] = true;
			}
		}
	}

	for(int i=0; i<10; i++)
		dp[i][0] = 0;
	dp[0][1] = 1;
	for(int i=1; i<10; i++)
		dp[i][1] = 1;
	for(int i=2; i<=n; i++)
	{
		for(int j=0; j<10; j++)
		{
			for(int k=0; k<10; k++)
			{
				if(!isprime[j][k])
				{
					dp[j][i] = (dp[j][i] + dp[k][i-1])%MOD;

				}
			}
			// cout<<dp[j][i]<<'\t';
		}
		// cout<<endl;
	}
	LL ans = 0;
	for(int i=0; i<10; i++)
	{
		ans = (ans + dp[i][n])%MOD;
	}
	cout<<ans;
	return ;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	sieve();
	int n;
	cin>>n;
	pre(n);
	
	return 0;
}