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

pii times[1010];

pii start[1010];
pii end[1010];
int st[1010];
int en[1010];
int dp[1010];
// int bonus[1010];

int count(int n)
{
	return (n>2 ? n : 0);
}

void func(int n)
{
	sort(times, times + n);
	/*for(int i=0; i<n; i++)
	{
		cout<<times[i].X<<' '<<times[i].Y<<endl;
	}*/
	dp[0] = 0;
	int ct,mx;
	int a,b;

	for(int i=1; i<n; i++)
	{
		mx = 0;
		ct = 1;
		for(int j=i-1; j>=0; j--)
		{
			if(times[j].X == times[i].X)
				dp[j] = INT_MIN;
			mx = max(mx, dp[j]+count(ct));
			if(times[j].Y >= times[i].X)
				ct++;
		}
		mx = max(count(ct), mx);
		dp[i] = mx;
		// cout<<dp[i]<<endl;
	}

	cout<<dp[n-1]<<endl;

	// for(int i=1; i<n; i++)
	// {
	// 	mx = dp[i-1];
	// 	ct = 1;
	// 	for(int j=i-1; j>=0; j--)
	// 	{
	// 		if(times[j].Y >= times[i].X)
	// 			ct++;
	// 		if(dp[j]>0)
	// 		{
	// 			if(times[j].Y >= times[i].X)

	// 			else

	// 		}
	// 		else
	// 		{
	// 			mx = max(mx,ct);
	// 		}


	// 		if(dp[j]>0 && times[j].Y >= times[i].X && ct>3)
	// 			mx = max(mx,ct+dp[j]-1);
	// 		else if(ct>2)
	// 			mx = max(mx,ct+dp[j]);
	// 		/*if(ct>2)
	// 		{
	// 			if(dp[j]>0 && times[j].Y >= times[i].X)
	// 				mx = max(mx, ct+dp[j]-1);
	// 			else
	// 				mx = max(mx, ct + dp[j]);
	// 		}*/
	// 	}
	// 	dp[i] = mx;
	// }
	// for(int i=0; i<n; i++)
	// {
	// 	cout<<dp[i]<<endl;
	// }
	// cout<<dp[n-1]<<endl;
	return ;
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

	for(int j=1; j<=t; j++)
	{
		int n;
		cin>>n;

		for(int i=0; i<n; i++)
		{
			cin>>times[i].X>>times[i].Y;
		}
		cout<<"Case #"<<j<<": ";
		func(n);
	}
	
	return 0;
}