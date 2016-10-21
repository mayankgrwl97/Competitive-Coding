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

int h,a,c,k,e,r,t;

/*hackert
ha  er */
int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	string str;
	int n;
	cin>>n;
	cin>>str;
	for(int i=0; i<n; i++)
	{
		// cout<<str[i];
		/*if(str[i] == 'h')
			h++;*/
		switch(str[i])
		{
			case 'h':
			h++;
			break;
			case 'a':
			a++;
			break;
			case 'c':
			c++;
			break;
			case 'k':
			k++;
			break;
			case 'e':
			e++;
			break;
			case 'r':
			r++;
			break;
			case 't':
			t++;
			break;
		}
	}
	h=h/2;
	a=a/2;
	e=e/2;
	r=r/2;
	// cout<<h;
		cout<<min( min(h,min(a,c)), min(min(k,e),min(r,t)) );
	
	return 0;
}