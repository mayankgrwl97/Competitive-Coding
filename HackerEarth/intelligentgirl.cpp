#include <bits/stdc++.h>
using namespace std;

char str[10010];
int dp[10010];

int main()
{
	freopen("input.txt","r",stdin);
	scanf("%s",str);
	int l = strlen(str);
	// cout<<l;
	for(int i=l-1; i>=0; i--)
	{
		if((str[i]-'0')%2 == 0)
			dp[i] = dp[i+1] + 1;
		else
			dp[i] = dp[i+1];
	}
	for(int i=0; i<l; i++)
	{
		printf("%d ", dp[i]);
	}
	return 0;
}