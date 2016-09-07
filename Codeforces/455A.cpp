#include <bits/stdc++.h>
using namespace std;

int arr[100100];
int dp1[100100];
int dp2[100100];

void populate(int n)
{
	int max = -1;
	sort(arr,arr+n);
	for(int i=0; i<n; i++)
	{
		cout<<arr[i]<<"\t";
	}
	dp1[0] = arr[0];
	int j;
	for(int i=1; i<n; i++)
	{
		j=i-1;
		while((arr[j] == (arr[i]-1)) && (j>=0))
			j--;
		if(j<0)
			dp1[i] = arr[i];
		else
			dp1[i] = dp1[j] + arr[i];
	}

cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<dp1[i]<<"\t";
	}

	dp2[n-1] = arr[n-1];
	for(int i=n-2; i>=0; i--)
	{
		j=i+1;
		while((arr[j] == (arr[i]+1)) && (j<n))
			j++;
		if(j>=n)
			dp2[i] = arr[i];
		else
			dp2[i] = dp2[j] + arr[i];
	}

	cout<<endl;

for (int i = 0; i < n; ++i)
	{
		cout<<dp2[i]<<"\t";
	}

	for(int i=0; i<n; i++)
	{
		dp1[i] = dp1[i] + dp2[i] - arr[i];
		if(max<dp1[i])
			max = dp1[i];
	}
	printf("%d\n",max);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	int n,tmp;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		scanf("%d",arr+i);
	}

	populate(n);

	return 0;
}

/*1 1 2 2 2 2 2 3 3

1 2 1 3 2 2 2 2 3*/