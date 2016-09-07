#include <bits/stdc++.h>
#define LL long long int
using namespace std;

LL arr[500100];

int func(int n)
{
	LL sum;
	int count = 0;
	for(int i=n-2; i>=0; i--)
		arr[i] += arr[i+1];

	for(int i=1; i<=n-2; i++)
	{
		sum = arr[i-1] - arr[i];
		
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	int n;
	cin>>n;

	for(int i=0; i<n; i++)	
	{
		scanf("%lld ",arr+i);
	}
}