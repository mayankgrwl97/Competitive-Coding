#include <bits/stdc++.h>
using namespace std;

char str[1000100];
int dp[1000100];

int wt(char a)
{
	return (a=='K' ? 1 : -1);
}

int max(int a, int b)
{
	return (a>b ? a : b);
}

int sum(int n)
{
	int a = 0;
	for(int i=0; i<n; i++)
	{
		if(str[i] == 'R')
			a++;	
	}
	return a;
}

int func(int n)
{
	int max_ending_here=0, max;
	for(int i=0; i<n; i++)
	{
		max_ending_here += wt(str[i]);
		if(max_ending_here<0)
			max_ending_here = 0;
		if(max < max_ending_here)
			max = max_ending_here;
	}
	int m = sum(n);
	if(m == n)
		return m-1;
	return max+m;
}

int main()
{
	freopen("input.txt","r",stdin);
	int t;
	cin>>t;

	while(t--)
	{
		scanf("%s",str);
		printf("%d\n",func(strlen(str)));
	}
	return 0;
}