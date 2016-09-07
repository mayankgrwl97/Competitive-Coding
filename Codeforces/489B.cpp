#include <bits/stdc++.h>
using namespace std;

int boys[110];
int girls[110];
int a[110];
int b[110];

int dp[]

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	int n,m;
	cin>>n;
	for(int i=0;i<n; i++)
	{
		scanf("%d",boys+i);
		a[boys[i]]++;
	}
	cin>>m;
	for(int i=0;i<m; i++)
	{
		scanf("%d",girls+i);
		b[girls[i]]++;
	}

	return 0;
}