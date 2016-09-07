#include <bits/stdc++.h>
using namespace std;

int arr[100100];

void func(int n)
{
	double sum = 0; 
	for(int i=0; i<n; i++)
	{
		sum += double(arr[i]);
	}
	sum = sum/n;
	// printf("%lf\n",sum);
	if(sum >= 4.0)
		printf("Yes\n");
	else
		printf("No\n");
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	int t,n,fail,full;
	cin>>t;

	while(t--)
	{
		cin>>n;
		fail = full = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d",arr+i);
			if(arr[i] == 2)
				fail = 1;
			else if(arr[i] == 5)
				full = 1;
		}
		if(fail == 1 || full == 0)
			printf("No\n");
		else
			func(n);
	}

	return 0;
}