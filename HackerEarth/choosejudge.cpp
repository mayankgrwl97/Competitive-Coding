#include <bits/stdc++.h>
#define LL long long int

using namespace std;

int score[10010];

LL max(LL a, LL b)
{
	return (a>b ? a : b);
}

LL dp[10010];

/*LL func(int a, int b)
{
	if(a>b)
		return 0;
	if(a==b)
	{

	}
		return score[a];
	
	LL x = score[a] + func(a+2,b);
	LL y = score[a+1] + func(a+3,b);

	return max(x,y);
}
*/
LL func(int l, int n)
{
	if(l>n-1)
		return 0;
	if(l == n-1)
	{
		dp[l] = score[l];
	}

	if(dp[l] == -1)
	{
		LL x = score[l] + func(l+2,n);
		LL y = score[l+1] + func(l+3,n);
		dp[l] = max(x,y);
	}
	return dp[l];
}

int main()
{
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	int t,n,ct=0;
	// LL max1,max2;
	cin>>t;
	while(t--)
	{
		// ct++;
		cin>>n;
		// max2 = max1 = 0;
		for(int i=0; i<n; i++)
		{
			scanf("%d",score+i);
			dp[i] = -1;
			/*if(i%2 == 0)
				max1 += score[i];
			else
				max2 += score[i];*/
		}
		printf("Case %d: %lld\n",++ct,func(0,n));
	}	
	return 0;
}