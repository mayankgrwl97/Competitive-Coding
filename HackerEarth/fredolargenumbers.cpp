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
const int n_ = 1e6+1000;
const long double PI = acos(-1.0);

LL gcd (LL a, LL b) {return ( a ? gcd(b%a, a) : b );}
LL power(LL a, LL n) {LL p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
LL power(LL a, LL n, LL mod) {LL p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

LL a[n_];
set<LL> visited;
map<LL,int> freq;
int type0[n_];
int type1[n_];

void pre(int n)
{
	for(int i=0; i<n; i++)
	{
		if(visited.count(a[i]))
			freq[a[i]]++;
		else
		{
			visited.insert(a[i]);
			freq[a[i]] = 1;
		}
	}

	for(int i=0; i<=n; i++)
		type0[i] = type1[i] = INT_MAX;

	for(int i=n-1; i>=0; i--)
	{
		type0[freq[a[i]]] = i;
	}

	type1[n] = type0[n];

	for(int i=n-1; i>=0; i--)
	{
		type1[i] = min(type1[i+1], type0[i]);
	}
	return ;
}

void func(LL f, int n, int type)
{
	if(f>n)
	{
		cout<<0<<endl;
		return ;
	}
	if(type == 0)
	{
		if(type1[f] == INT_MAX)
			cout<<0<<endl;
		else
			cout<<a[type1[f]]<<endl;
	}
	else
	{
		if(type0[f] == INT_MAX)
			cout<<0<<endl;
		else
			cout<<a[type0[f]]<<endl;
	}
	return ;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int type,n,q;
	LL f;
	cin>>n;

	for(int i=0; i<n; i++)
		cin>>a[i];

	pre(n);
	cin>>q;
	while(q--)
	{
		cin>>type>>f;
		func(f,n,type);
	}

	return 0;
}