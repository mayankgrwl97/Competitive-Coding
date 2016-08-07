#include <bits/stdc++.h>
#define mod 1000000007
#define LL long long int
using namespace std;

LL dp[10010];
LL x[10010];

/*void populate(int n, int p)
{
	if(p==1)
	{
		printf("%d\n", 1);
		return;		
	}

	p--;
	dp[1] = 1;
	 x[0] = 0;
	 x[1] = 0;
	for(int i=2; i<=p+1; i++)
	{
		dp[i] = (2*dp[i-1])%mod;
	}
	for(int i=p+2; i<=n; i++)
	{
		dp[i] = dp[i-1] + 
	}
	printf("%lld\n", dp[n]);
}
*/
void populate(int n, int p)
{
	if(p==1)
	{
		printf("%d\n", 1);
		return;
	}
	
	p--;
	dp[1] = 1;
	for(int i=2; i<=p+1; i++)
	{
		dp[i] = (2*dp[i-1])%mod;
	}
	for(int i=p+2; i<=n; i++)
	{
		dp[i] = 0;
		for(int j=1; j<=p+1; j++)
		{
			dp[i] = (dp[i] + dp[i-j])%mod;
		}
	}
	printf("%d\n", dp[n]);
}

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("res.txt","w",stdout);
	int t,n,p;
	cin>>t;

	while(t--)
	{
		cin>>n>>p;
		populate(n,p);
	}
	return 0;
}