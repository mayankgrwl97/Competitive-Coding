#include <bits/stdc++.h>
#define size 1000100
using namespace std;

char B[size];
int dp[size];

int main()
{
	freopen("input.txt","r",stdin);
	int t,n,max;
	cin>>t;
	while(t--)
	{
		max = 0;
		scanf("%s",B);
		n = strlen(B);
		
		if(n<3)
			printf("%d\n", n);
		else
		{
			dp[0] = dp[1] = 0;
			if(B[0] == B[1] && B[1] == B[2])
				dp[2] = 0;
			else
				dp[2] = 1;

			for(int i=3; i<n; i++)
			{
				if(B[i] == B[i-1] && B[i-1] == B[i-2])
					dp[i] = 0;
				else
					dp[i] = 1;

				if(dp[i]>0)
					dp[i] += dp[i-3];
				if(max<dp[i])
					max = dp[i];
			}
			
			if(max<dp[2])
				max = dp[2];
			printf("%d\n", n-(3*max));
		}
	}
	return 0;
}