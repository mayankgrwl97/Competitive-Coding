#include <bits/stdc++.h>
using namespace std;

int arr[150];
int dp1[150];
// int dp2[150];

int pre(int n)
{
	int MAX = dp1[0] = arr[0];
	for(int i=1; i<n; i++)
	{
		dp1[i] = max(arr[i],arr[i]+dp1[i-1]);
		if(MAX < dp1[i])
			MAX = dp1[i];
	}
	return MAX;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif
		int n;
	cin>>n;
	int ct_1 = 0;

	for(int i=0; i<n; i++)
	{
		scanf("%d",arr+i);
		if(arr[i] == 1)
		{
			arr[i] = -1;
			ct_1++;
		}
		else
		{
			arr[i] = 1;
		}
	}
	printf("%d\n",pre(n)+ct_1);

	return 0;
}