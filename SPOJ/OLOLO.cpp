#include <bits/stdc++.h>
using namespace std;

int arr[500500];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	int ans,temp;
	scanf("%d",arr);
	ans = arr[0];

	for(int i=1; i<n; i++)
	{
		scanf("%d",arr+i);
		ans = ans^arr[i];
	}
	cout<<ans;
	return 0;
}