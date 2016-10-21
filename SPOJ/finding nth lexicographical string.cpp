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

int arr[1000];

LL fact[21];


void pre()
{
	fact[0] = 1;
	LL ans = 1;
	for(int i=1; i<=20; i++)
	{
		ans = ans * i;
		fact[i] = ans;
	}
	return ;
}

void func(int n, int k)
{
	set<int> st;
	for(int i=0; i<n; i++)
		st.insert(arr[i]);
	set<int>::iterator it;
	// int curr_n = n;
	int curr_k = k;
	int temp;
	int ct = 0;

	while(n>0)
	{
		// cout<<k;
		it = st.begin();
		temp = fact[n-1];
		for(int i=0; i<n; i++)
		{
			if(temp>=k)
			{
				cout<<*it<<' ';
				st.erase(*it);
				break;
			}
			else
			{
				temp = temp+fact[n-1];
				curr_k -= fact[n-1];
			}
			it++;
		}
		k = curr_k;
		n--;
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

	int n,k;
	cin>>n>>k;

	for(int i=0; i<n; i++)	
	{
		cin>>arr[i];
		// st.insert(arr[i]);
	}

	pre();
	// func(n,k);
	for(int i=1; i<=fact[n]; i++)
		func(n,i),cout<<endl;
	// sort(arr,arr+n);

	
	return 0;
}