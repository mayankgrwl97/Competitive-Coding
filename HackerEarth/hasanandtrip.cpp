#include <bits/stdc++.h>
using namespace std;

double x[3000];
double y[3000];
double f[3000];
double dp[3000];
double dis[3000][3000];

void compute(int n)
{
	for(int i=n-1; i>=0; i--)
	{
		for(int j=i+1; j<n; j++)
		{
			dis[i][j] = sqrt((x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i]));
		}
	}
}

void func(int n)
{
	compute(n);
	dp[n-1] = f[n-1];

	double mx;
	for(int i=n-2; i>=0; i--)
	{
		mx = INT_MIN;
		for(int j=i+1; j<n; j++)
		{
			dp[i] = dp[j] + f[i] - dis[i][j];
			// cout<<"dp "<<dp[i]<<'\n';
			if(mx<dp[i])
				mx = dp[i];
			// cout<<"mx "<<mx<<'\n';
		}
		dp[i] = mx;
		// cout<<mx<<'\n';
	}
	printf("%0.6lf",dp[0]);
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>x[i]>>y[i]>>f[i];
	}

	func(n);

	
	return 0;
}