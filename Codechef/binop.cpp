#include <bits/stdc++.h>
using namespace std;

char A[1000100];
char B[1000100];

int max(int a, int b)
{
	return (a>b ? a : b);
}

void func()
{
	int ct_0=0, ct_1=0;
	int n = strlen(A);
	int flag_0=0, flag_1=0;

	for (int i = 0; i < n; ++i)
	{
		if(A[i] == '0')
			flag_0 = 1;
		else
			flag_1 = 1;
		if(A[i] != B[i])
		{
			if(A[i] == '0')
				ct_0++;
			else
				ct_1++;
		}
	}
	if(flag_0 == 0 || flag_1 == 0)
	{
		printf("Unlucky Chef\n");
		return;
	}
	else
	{
		printf("Lucky Chef\n%d\n",max(ct_1,ct_0)) ;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	int t,n;
	cin>>t;
	while(t--)
	{
		scanf("%s",A);
		scanf("%s",B);
		func();
	}
	return 0; 
}
