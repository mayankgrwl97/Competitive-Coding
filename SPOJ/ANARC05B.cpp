#include <bits/stdc++.h>
using namespace std;

int arr1[10000];
int arr2[10000];
int sum1[10000];
int sum2[10000];

int bin_search(int a, int n)
{
	int lo = 0;
	int hi = n-1;
	int mid;

	while(lo<=hi)
	{
		mid = (lo+hi)/2;
		// cout<<mid<<'\n';
		if(arr1[mid] == a)
			return mid;
		if(arr1[mid] < a)
			lo = mid+1;
		else
			hi = mid-1;
	}
	return -1;
}

int func(int n1, int n2)
{
	queue<pair<int, int> > myqueue;

	sum1[0] = arr1[0];
	sum2[0] = arr2[0];

	for(int i=1; i<n1; i++)
		sum1[i] = sum1[i-1] + arr1[i];
	for(int i=1; i<n2; i++)
		sum2[i] = sum2[i-1] + arr2[i];

	int t;

	for(int i=0; i<n2; i++)
	{
		t = bin_search(arr2[i],n1);
		if(t!=-1)
		{
			myqueue.push(make_pair(i,t));
		}
	}

	pair<int,int> temp;

	if(myqueue.empty())
	{
		return max(sum1[n1-1],sum2[n2-1]);
	}
	temp = myqueue.front();
	myqueue.pop();
	int l1 = temp.second;
	int l2 = temp.first;

	int sum = max(sum1[l1], sum2[l2]);
	// cout<<sum<<'\n';
	// for(int i=0; i<n1; i++)
	// {
	// 	cout<<sum1[i]<<' ';
	// }
	while(!myqueue.empty())
	{
		temp = myqueue.front();
		myqueue.pop();
		sum += max(sum1[temp.second] - sum1[l1], sum2[temp.first] - sum2[l2]);
		l1 = temp.second;
		l2 = temp.first;
	}

	sum += max(sum1[n1-1] - sum1[l1], sum2[n2-1] - sum2[l2]);
	// cout<<sum;

	return sum;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n1,n2;

	cin>>n1;
	while(n1 != 0)
	{
		for(int i=0; i<n1; i++)
			cin>>arr1[i];
		cin>>n2;
		for(int i=0; i<n2; i++)
			cin>>arr2[i];
		cout<< func(n1, n2)<<'\n';
		// cout<<bin_search(57,n1);
		cin>>n1;
	}

	// cout<<n1;
	// for(int i=0; i<n1; i++)
	// {
	// 	cout<<arr1[i]<<'\t';
	// }

	return 0;
}