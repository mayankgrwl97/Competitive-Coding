#include <bits/stdc++.h>
using namespace std;

int stones[101][101];
int dp[101][101];

void compute(int h,int w)
{
	for(int i=0; i<w; i++)
	{
		dp[h-1][i] = stones[h-1][i];
	}

	for(int i=h-2; i>=0; i--)
	{
		dp[i][0] = stones[i][0] + max(dp[i+1][0], dp[i+1][1]);
		if(w>=2)
			dp[i][w-1] = stones[i][w-1] + max(dp[i+1][w-1], dp[i+1][w-2]);
		for(int j=1; j<=w-2; j++)
		{
			dp[i][j] = stones[i][j] + max(max(dp[i+1][j], dp[i+1][j-1]), dp[i+1][j+1]);
		}
	}

	int max = INT_MIN;

	for(int i=0; i<w; i++)
	{
		if(max<dp[0][i])
			max = dp[0][i];
	}

	cout<<max<<'\n';
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t,h,w;
	cin>>t;

	//h rows
	//w columns

	while(t--)
	{
		cin>>h>>w;
		for(int i=0; i<h; i++)
		{
			for(int j=0; j<w; j++)
			{
				cin>>stones[i][j];
			}
		}
		compute(h,w);
	}
	
	return 0;
}