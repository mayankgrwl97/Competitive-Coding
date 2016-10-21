#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define scani(n) scanf("%d",&n);
#define MOD (ll)1000000007
#define endl '\n'
#define EPS 1e-9
#define FOR(i,n) for(int i=0; i<n; i++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

LL a[100100];
LL dp1[100100][2];//dp1[i][0] sum from left to i excluding i //dp1[i][1] sum from left to i including i
LL dp2[100100][2];//dp2[i][0] sum from right to i excluding i //dp2[i][1] sum from right to i including i

void func(LL n)
{
	if(n==1)
	{
		cout<<a[1];
		return ;
	}

	dp1[1][0] = 0;
	dp1[1][1] = a[1];

	dp1[2][0] = dp1[1][1];
	dp1[2][1] = 2*a[2];

	for(LL i=3; i<=n; i++)
	{
		dp1[i][0] = max(dp1[i-1][0], dp1[i-1][1]);
		dp1[i][1] = max(dp1[i-2][0], dp1[i-2][1]) + i*a[i];
	}

	dp2[n][0] = 0;
	dp2[n][1] = n*a[n];

	dp2[n-1][0] = dp2[n][1];
	dp2[n-1][1] = (n-1)*a[n-1];

	for(LL i=n-2; i>0; i--)
	{
		dp2[i][0] = max(dp2[i+1][0], dp2[i+1][1]);
		dp2[i][1] = max(dp2[i+2][0], dp2[i+2][1]) + i*a[i];
	}

	LL ans = -1;

	for(LL i=1; i<=n; i++)
	{
		ans = max(ans, max(dp1[i][0] + dp2[i][0] , dp1[i][1] + dp2[i][1] - i*a[i]));
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

	int n;
	cin>>n;
	LL b,mx = -1;	
	for(int i=0; i<n; i++)
	{
		cin>>b,a[b]++;
		if(mx<b)
			mx = b;
	}
	func(mx);
	return 0;
}