#include <bits/stdc++.h>
using namespace std;

int arr[100];
int lhs[60100];
int rhs[100100];

int binsearch(int a, int n)
{
	int lo = 0;
	int hi = n-1;
	int mid;
	while(lo<=hi)
	{
		mid = (lo+hi)/2;
		if(lhs[mid] == a)
			return 1;
		else if(lhs[mid]<a)
			lo = mid+1;
		else
			hi = mid-1;
	}
	return 0;
}

void func(int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{	
			if(arr[i] != arr[j])
				for(int k=0; k<n; k++)
				{
					lhs[arr[i]*arr[j] + arr[k]]++;
				}
		}
	}

	int st = 0;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(arr[i] != arr[j])
				for(int k=0; k<n; k++)
				{
					if(arr[k] != 0)
						rhs[st++] = (arr[i]+arr[j]) * arr[k];
				}
		}
	}
	for(int i=0; i<n; i++)
	{
		
	}

	return ;
}







void func(int n)
{
	int st=0;
	int l,r;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i != j)
				for(int k=0; k<n; k++)
					lhs[st++] = arr[i]*arr[j] + arr[k];
		}
		for(int k=0; k<n; k++)
		{
			lhs[st++] = arr[i]*arr[i] + arr[k];
		}
	}
	l = st;
	sort(lhs,lhs+l);
	st = 0;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(i!=j)
				for(int k=0; k<n; k++)
				{
					if(arr[k] != 0)
						rhs[st++] = (arr[i]+arr[j]) * arr[k];
				}
		}
		for(int k=0; k<n; k++)
		{
			rhs[st++] = (arr[i]+arr[i]) * arr[k];
		}
	}
	r = st;
	cout<<l<<'\n';
	for(int i=0; i<l; i++)
	{
		cout<<lhs[i]<<' ';
	}
	cout<<'\n';
	sort(rhs,rhs+r);

	for(int i=0; i<r; i++)
	{
		cout<<rhs[i]<<' ';
	}
	cout<<'\n';
	int count = 0;
	for(int i=0; i<r; i++)
	{
		if(binsearch(rhs[i],n))
			count++;
	}
	cout<<count;
	return ;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	func(n);
	
	return 0;
}