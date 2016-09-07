#include <bits/stdc++.h>
using namespace std;

int dp[5000];

int min3(int a, int b, int c)
{
	return min(min(a,b),c);
}

int max3(int a, int b, int c)
{
	return max(max(a,b),c);
}

int func(int a, int b, int c, int n)
{
	if(n==0)
		return 0;
	if(n<0)
		return -1;
	if(dp[n] != 0)//dp[n] has not been calculated yet
		return dp[n];
	int m1 = func(a,b,c,n-a);
	int m2 = func(a,b,c,n-b);
	int m3 = func(a,b,c,n-c);
	dp[n] = max3(m1,m2,m3);
	if(dp[n]>=0)
		dp[n]++;
	return dp[n];
}
/*
int func(int a, int b, int c, int n, int minimum)
{
	if(n==0)
		return 0;
	else if(n<0)
		return -1;
	
	int m1,m2,m3;

	if(dp[n-a] == 0)
		dp[n-a] = func(a,b,c,n-a);
	m1 = func(a,b,c,n-a);
	if(m1 >= 0)
		m1++;
	if(dp[n-b] == 0)
		dp[n-b] = func(a,b,c,n-b);
	m2 = func(a,b,c,n-b);
	if(m2>=0)
		m2++;
	if(dp[n-c] == 0)
		dp[n-c] = func(a,b,c,n-c);
	m3 = func(a,b,c,n-c);
	if(m3>=0)
		m3++;
	return max3(m1,m2,m3);
}*/

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	int n,a,b,c;
	cin>>n>>a>>b>>c;
	// int minimum = min3(a,b,c);
	cout<<func(a,b,c,n);
	return 0;
}

/*n = n1*a + n2*b + n3*c*/
