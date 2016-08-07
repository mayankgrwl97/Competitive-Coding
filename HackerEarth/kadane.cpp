#include <bits/stdc++.h>
using namespace std;

int arr[200];

int main()
{
	freopen("input.txt","r",stdin);
	int t,n;
	cin>>t;
	int max_ending_here, max;
	while(t--)
	{
		scanf("%d",&n);
		scanf("%d",arr+0);
		max_ending_here = arr[0];
		if(max_ending_here<0)
			max_ending_here = 0;
		if(max<max_ending_here)
			max = max_ending_here;
		for(int i=1; i<n; i++)
		{
			scanf("%d",arr+i);
			max_ending_here += arr[i];
			if(max_ending_here<0)
				max_ending_here = 0;
			if(max<max_ending_here)
				max = max_ending_here;
		}
		printf("%d\n", max);
	}
	return 0;
}