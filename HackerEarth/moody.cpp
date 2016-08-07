#include <bits/stdc++.h>
#define LL long long int
using namespace std;

LL sq(LL n)
{
	LL a=0;
	n = n*n;
	while(n>0)
	{
		a += n%10;
		n=n/10;
	}
	return a;
}

void func(LL n)
{
	if(n==1 || n==4)
	{
		printf("YES\n");
		return;
	}

	LL m = sq(n);

	if(n == m)
	{
		printf("NO\n");
		return;
	}

	func(m);
	
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	LL n;
	cin>>t;

	while(t--)
	{
		scanf("%lld",&n);
		func(n);
	}
	return 0;
}