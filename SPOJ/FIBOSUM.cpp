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

void square(LL A[2][2])
{
	LL a00 = A[0][0];
	LL a01 = A[0][1];
	LL a10 = A[1][0];
	LL a11 = A[1][1];

	A[0][0] = (a00*a00 + a01*a10)%MOD;
	A[0][1] = (a00*a01 + a01*a11)%MOD;
	A[1][0] = (a10*a00 + a11*a10)%MOD;
	A[1][1] = (a10*a01 + a11*a11)%MOD;

	return ;
}

void multiply(LL A[2][2], LL B[2][2])
{
	LL x = (A[0][0]*B[0][0] + A[0][1]*B[1][0])%MOD;
	LL y = (A[0][0]*B[0][1] + A[0][1]*B[1][1])%MOD;
	LL z = (A[1][0]*B[0][0] + A[1][1]*B[1][0])%MOD;
	LL w = (A[1][0]*B[0][1] + A[1][1]*B[1][1])%MOD;

	A[0][0] = x;
	A[0][1] = y;
	A[1][0] = z;
	A[1][1] = w;

	return ;
}

void mult(LL A[2][2], int n)
{
	if(n==0 || n==1)
		return ;

	mult(A,n/2);
	square(A);

	LL B[2][2];
	B[0][0] = 1;
	B[0][1] = 1;
	B[1][0] = 1;
	B[1][1] = 0;


	if(n%2)
		multiply(A,B);
}

LL fib(int n)
{
	if(n==0)
		return 0;
	LL A[2][2];
	A[0][0] = 1;
	A[0][1] = 1;
	A[1][0] = 1;
	A[1][1] = 0;

	mult(A,n);
	return A[0][1];
	// cout<<A[0][1]<<endl;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t;cin>>t;

	while(t--)
	{
		LL n,m;
		cin>>n>>m;
		LL sum = 0;
		sum = (fib(m+1)+fib(m)-fib(n+1)+MOD)%MOD;
		cout<<sum<<endl;
	}

	
	return 0;
}