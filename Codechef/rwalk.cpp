#include <bits/stdc++.h>
using namespace std;

int arr1[260];
int arr2[260];

int dp[260][130000];

int func(int n, int s, int arr[])
{
	/*for(int i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}*/
	int temp;
	int min = 90000000;
	sort(arr,arr+n);
	dp[0][0] = 1;
	for(int i=1; i<=s; i++)
	{
		dp[0][i] = 0;
	}
	dp[0][arr[0]] = 1;

	for(int i=1; i<n; i++)
	{
		for(int j=0; j<arr[i]; j++)
		{
			dp[i][j] = dp[i-1][j];
		}
		for(int j=arr[i]; j<=s; j++)
		{
			if(dp[i-1][j] == 1)
				dp[i][j] = 1;
			else if(dp[i-1][j-arr[i]] == 1)
				dp[i][j] = 1;
			else
				dp[i][j] = 0;
		}
	}
	for(int i=1; i<=s; i++)
	{
		if(dp[n-1][i])
		{
			temp = abs(s-2*i);
			if(min>temp)
				min = temp;
		}
	}
	return min;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	int t,n,n1,n2,s1,s2,sum;
	char ch;
	cin>>t;

	while(t--)
	{
		scanf("%d",&n);
		n1 = n2 = s1 = s2 = 0;
		scanf("%d ",arr1+n1);
		s1 += arr1[0];
		// cout<<arr1[0];
		n1++;

		for(int i=1; i<=n; i++)
		{
			scanf("%c ",&ch);
			if(i%2)//i is odd
			{
				scanf("%d ",arr2+n2);
				// cout<<arr2[n2];
				s2+=arr2[n2];
				n2++;
			}
			else
			{
				scanf("%d ",arr1+n1);
				// cout<<arr1[n1];
				s1+=arr1[n1];
				n1++;
			}
		}
		if(n1 == 1 || n2 == 1)
			printf("NO\n");
		else
		{
			sum = func(n1,s1,arr1) + func(n2,s2,arr2);
			printf("%d\n", sum);
		}
	}
	return 0;
}