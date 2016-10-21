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

string str;
int dp[5100][5100];

void func()
{
	int l = str.length();

	for(int i=0; i<l; i++)
	{
		dp[i][i] = 0;
	}

	for(int i=l-2; i>=0; i--)
	{
		for(int j=i+1; j<l; j++)
		{
			int a = dp[i+1][j] + 1;
			int b = dp[i][j-1] + 1;
			int c = INT_MAX;
			if(2<=j-i)
			{
				if(str[i] == str[j])
					c = dp[i+1][j-1];
				else
					c = dp[i+1][j-1] + 2;
			}
			else if(str[i] == str[j])
				c = 0;
			dp[i][j] = min(a,min(b,c));
		}
	}
	cout<<dp[0][l-1]<<endl;
	return;
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
	cin>>str;

	func();
	
	return 0;
}