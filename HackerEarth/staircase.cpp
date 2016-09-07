#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	int n;
	cin>>n;
	if(n<=0)
	{
		cout<<"ERROR";
		return 0;
	}
	int dp1[n+1];
	int dp2[n+1];

	dp1[1] = 1;
	dp1[2] = 2;
	dp1[3] = 4;
	dp2[1] = 1;
	dp2[2] = 2;
	for(int i=4; i<=n; i++)
	{
		dp1[i] = dp1[i-1] + dp1[i-2] + dp1[i-3];
	}
	for(int i=3; i<=n; i++)
	{
		dp2[i] = dp2[i-1] + dp2[i-2];
	}
	cout<<"Jack-"<<dp1[n]<<"\n";
	cout<<"Jill-"<<dp2[n];
	return 0;

}