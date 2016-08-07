#include <bits/stdc++.h>
using namespace std;

int arr[100100];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t,n;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%d ",arr+i);
		}
	}
	
	
	return 0;
}