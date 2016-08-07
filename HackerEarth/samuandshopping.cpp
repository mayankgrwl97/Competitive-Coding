#include <bits/stdc++.h>
using namespace std;

int min(int a, int b)
{
	return (a>b ? b : a);
}

int min3(int a, int b, int c)
{
	return min(a,min(b,c));
}

int shirt[100100], pant[100100], shoes[100100];

void populate(int n)
{
	for(int i=2; i<=n; i++)
	{
		shirt[i] = shirt[i] + min(pant[i-1],shoes[i-1]);
		pant[i] = pant[i] + min(shirt[i-1],shoes[i-1]);
		shoes[i] = shoes[i] + min(shirt[i-1],pant[i-1]);
	}
	printf("%d\n", min3(shirt[n], pant[n], shoes[n]));
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t,n;
	cin>>t;

	while(t--)
	{
		cin>>n;
		for(int i=1; i<=n; i++)
		{
			cin>>shirt[i]>>pant[i]>>shoes[i];
		}
		populate(n);
	}
	return 0;
}