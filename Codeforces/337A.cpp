#include <bits/stdc++.h>
using namespace std;

int arr[1010];

int main()
{
	// freopen("input.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	for(int i=0; i<m; i++)
	{
		scanf("%d",arr+i);
	}
	sort(arr,arr+m);
	int min = 200000;
	for(int i=0;i<=m-n; i++)
	{
		if(min>arr[i+n-1]-arr[i])
			min = arr[i+n-1] - arr[i];
	}
	printf("%d\n", min);
	return 0;
}