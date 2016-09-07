#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll arr[1000];

void func(ll k)
{
	k--;
	int i=0;
	if(k==0)
	{
		arr[0] = 0;
		i = 1;
	}
	while(k>0)
	{
		// sum = sum*10;
		// printf("%lld",(k%5));
		arr[i] = k%5;
		k = k/5;
		i++;
	}
	for(int j=i-1; j>=0; j--)
	{
		printf("%lld",arr[j]*2);
	}
	printf("\n");
	// printf("%lld\n", sum);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif
	int t;
	cin>>t;
	ll k;

	/*for (int i = 1; i < 30; ++i)
	{
		func(ll(i));
	}*/

	while(t--)
	{
		scanf("%lld",&k);
		func(k);
	}
	return 0;
}

/*
25 5 1
1  0 2
*/