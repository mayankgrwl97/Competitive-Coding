#include <bits/stdc++.h>
using namespace std;

int a[1000];
int b[1000];
int c[1000];

void func(int n, int k)
{
	int temp;
	int minimum = INT_MAX;
	for(int i=0; i<n; i++)
	{
		temp = b[i] / a[i];
		if(temp < minimum)
			minimum = temp;
	}
	for(int i=0; i<n; i++)
	{
		
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,k;
	cin>>n>>k;

	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	for(int i=0; i<n; i++)
	{
		cin>>b[i];
	}
	func(n,k);
	return 0;
}