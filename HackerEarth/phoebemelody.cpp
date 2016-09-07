#include <bits/stdc++.h>
using namespace std;

int arr[200100];
int left[200100];
int right[200100];

void func(int n, int k)
{
	left[0] = -1;
	for(int i=1; i<n; i++)
	{
		if(left[])
	}
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	int t,n,k;
	cin>>t;

	while(t--)
	{
		scanf("%d %d",&n, &k);
		for(int i=0; i<n; i++)
		{
			scanf("%d",arr+i);
		}
		func(n,k);
	}

	return 0;
}

/*

v1 v2 v3 v4 ... vn
i1 i2 i3 i4 ... in

*/