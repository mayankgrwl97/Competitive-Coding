#include <bits/stdc++.h>
using namespace std;

char str[100100];
int dp[100100];

void func()
{
	int l = strlen(str);
	dp[l-1] = 0;
	for(int i=l-2; i>=0; i--)
	{
		if(str[i] == str[i+1])
			dp[i] = dp[i+1] + 1;
		else
			dp[i] = dp[i+1];
	}
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	scanf("%s",str);
	func();
	int q,l,r;
	cin>>q;

	while(q--)
	{
		scanf("%d %d",&l, &r);
		printf("%d\n",dp[l-1] - dp[r-1]);
	}

	return 0;
}