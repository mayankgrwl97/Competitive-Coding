#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL dp1[10001]; //including element at i
LL dp2[10001]; //excluding element at i
LL coins[10001];

void func(int n)
{
	if(n==1)
	{
		cout<<coins[0]<<'\n';
		return;
	}

	dp1[0] = coins[0];
	dp2[0] = 0;

	dp1[1] = coins[1];
	dp2[1] = coins[0];

	for(int i=2; i<n; i++)
	{
		dp1[i] = coins[i] + max(dp1[i-2], dp2[i-2]);
		dp2[i] = max(dp1[i-1], dp2[i-1]);
	}
	cout<<max(dp1[n-1], dp2[n-1])<<'\n';
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	
	int n,t;
	scanf("%d",&t);
	int c=1;
	while(t--)
	{
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cin>>coins[i];
		}
		cout<<"Case "<<c++<<": ";
		func(n);
	}
	
	
	return 0;
}