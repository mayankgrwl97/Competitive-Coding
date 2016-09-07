#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL dp[100][100];
int arr[100];
int colour[100][100];

void fillcolour(int n)
{
	for(int i=0; i<n; i++)
	{
		colour[i][i] = arr[i];
	}
	for(int i=n-2; i>=0; i--)
	{
		for(int j=i+1; j<n; j++)
		{
			colour[i][j] = (colour[i][j-1] + arr[j])%100;
		}
	}
	return;
}

void func(int n)
{
	for(int i=0; i<n; i++)
	{
		dp[i][i] = 0;
	}
	LL temp, min;
	for(int i=n-2; i>=0; i--)
	{
		for(int j=i+1; j<n; j++)
		{
			min = LLONG_MAX;
			for(int k=i; k<j; k++)
			{
				temp = dp[i][k] + dp[k+1][j] + colour[i][k] * colour[k+1][j];
				if(temp<min)
					min = temp;
			}
			dp[i][j] = min;
		}
	}

	cout<<dp[0][n-1]<<'\n';

	return ;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n;

	while(scanf("%d",&n) != EOF)
	{
		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		fillcolour(n);
		func(n);
	}

	return 0;
}