#include <bits/stdc++.h>
using namespace std;

int treat[2000];
int dp[2000][2000];

void func(int n)
{
	int start = 0;
	int end = n-1;

	for(int i=0; i<n; i++)
	{
		dp[i][i] = treat[i] * n;
	}

	int t;
	int age;
	for(int i=1; i<n; i++)
	{
		t = n-i;
		for(int j=0; j<t; j++)
		{
			age = n-i;
			dp[j][j+i] = max(treat[j] * age + dp[j+1][j+i], treat[j+i] * age + dp[j][j+i-1]);
		}
	}

	cout<<dp[0][n-1];
//dp[0][1] = 0..1

}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n; cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>treat[i];
	}
	
	func(n);

	return 0;
}