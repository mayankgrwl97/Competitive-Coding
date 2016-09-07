#include <bits/stdc++.h>
using namespace std;

int arr[100100];

/*bool binary_search(int a, int n)
{
	int lo = 0;
	int hi = n-1;
	int mid = (lo+hi)/2;

	while(lo<hi)
	{
		if(arr[mid] == a)
			return true
		if(arr[mid] < a)
		{

		}
	}
}
*/
void func(int n, int t, int min ,int max)
{
	if(n==1 && arr[0] != t)
	{
		printf("No\n");
		return;
	}
	if(n==1)
	{
		printf("Yes\n");
		return;
	}
	// sort(arr, arr+n);
	if(min <= t && max >= t)
	{
		printf("Yes\n");
		return;
	}
	else
	{
		printf("No\n");
		return;
	}
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	int n,q,t,min=2000000000,max = -1;
	cin>>n>>q;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d",arr+i);
		if(min>arr[i])
			min = arr[i];
		if(max<arr[i])
			max = arr[i];
	}

	for (int i = 0; i < q; ++i)
	{
		scanf("%d",&t);
		func(n,t,min,max);
	}

	return 0;
}