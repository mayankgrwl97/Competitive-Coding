#include <bits/stdc++.h>
using namespace std;

char str[110];

bool possible(int m, int s)
{
	return (s>0 && s<=9*m);
}

void max(int m, int s)
{
	int x = s/9;
	int q = s%9;
	if((x>m)||(x==m && q>0)||s==0)
	{
		printf("-1");
		return;
	}
	for(int i=0; i<x; i++)
	{
		str[i] = '9';
	}
	str[x] = '0' + q;
	for(int i=x+1; i<m; i++)
		str[i] = '0';
	printf("%s\n", str);
	return;
}

void min(int m, int s)
{
	if(!possible(m,s))
	{
		printf("-1");
	}
	int x = s/9;
	int q = s%9;

	for(int i=0; i<x; i++)
	{
		str[m-1-i] = '9';
	}
	if(q==0)
	{
		str[m-2-x]--;
	}
	else if(q==1)
	{
		str[0] = '1';
	}
	else
	{
		str[0] = '1';
		str[m-2-x] = '0' + q-1;
	}
	str[m] = '\0';
	printf("%s\n", str);
}

/*
void func(int m, int s)
{
	str[m] = '\0';
	int x = s/9;
	if(x>m)
	{
		printf("-1 -1")
	}
	for(int i=0; i<x; i++)
	{
		str[i] = '9';
	}
	str[x] = 
}*/

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif
	int m,s;
	cin>>m>>s;

	max(m,s);
	min(m,s);
	return 0;
}

/*am.....a3a2a1
a1+a2+a3+....+am = s*/