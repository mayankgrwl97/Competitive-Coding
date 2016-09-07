#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int arr[100100];

void func(int n)
{
	LL sum = 0;
	LL temp;
	for(int i=0; i<n;)
	{
		temp = 1;
		for(int j=i+1;(j<n && arr[j]>=arr[j-1]); j++,i++)
		{
			temp++;
		}
		i++;
		sum += LL(temp)*(temp+1)/2;
	}
	printf("%lld\n", sum);
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
			scanf("%d ",arr+i);
		}
		func(n);
	}
	return 0;
}