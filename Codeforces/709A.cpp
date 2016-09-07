#include <bits/stdc++.h>
using namespace std;

int a[100100];

void func(int n, int b, int d)
{
	int count = 0;
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		if(a[i]>b)
			continue;
		else
		{
			sum += a[i];
			if(sum>d)
			{
				sum = 0;
				count++;
			}
		}
	}
	cout<<count;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n, b,d;
	cin>>n>>b>>d;

	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	func(n,b,d);	
	return 0;
}