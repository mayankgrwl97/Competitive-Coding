#include <bits/stdc++.h>
using namespace std;

string s;
int dp[6200][6200];

void func()
{
	int n = s.length();
	for(int i=0; i<n; i++)
	{
		dp[i][i] = 0;
	}

	int a,b,c;
	for(int i=n-2; i>=0; i--)
	{
		for(int j=i+1; j<n; j++)
		{
			a = dp[i][j-1] + 1;
			b = dp[i+1][j] + 1;
			c = INT_MAX;
			if(i+1 <= j-1)
			{
				if(s[i] == s[j])
					c = dp[i+1][j-1];
				else
					c = dp[i+1][j-1] + 2;
			}
			else if(s[i] == s[j])
			{
				c = 0;
			}
			dp[i][j] = min(a,min(b,c));
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

	int t;
	cin>>t;

	while(t--)
	{
		cin>>s;
		func();
	}
	
	return 0;
}