#include <bits/stdc++.h>
using namespace std;

int arr[100100];
int dp[100100];

bool isposs(int a, int b)
{
	if((a>0 && b>0) || (a<0 && b<0))
		return false;
	return true;
}

void func(int n)
{
	dp[n-1] = 1;
	for(int i=n-2; i>=0; i--)
	{
		if(isposs(arr[i+1],arr[i]))
			dp[i] = dp[i+1]+1;
		else
			dp[i] = 1;
	}
	for(int i=0; i<n; i++)
		printf("%d ",dp[i]);
	printf("\n");
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	int t,n;
	cin>>t;

	while(t--)
	{
		cin>>n;
		for (int i = 0; i < n; ++i)
		{
			scanf("%d",arr+i);
		}
		func(n);
	}

	return 0;
}