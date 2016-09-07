#include <bits/stdc++.h>
using namespace std;

char str[100100];
int arr[100100];

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
		scanf("%s",str);
		for(int i=0; i<n; i++)
		{
			scanf("%d ",arr+i);
		}
	}

	return 0;
}