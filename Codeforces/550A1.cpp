#include <bits/stdc++.h>
using namespace std;

char str[100100];

void func(int l)
{
	int temp = -1;
	for(int i=0; i<l-1; i++)
	{
		if(str[i] == 'A' && str[i+1] == 'B')
		{
			temp = i+2;
			break;
		}
	}
	if(temp != -1)
	{
		for(int i=temp; i<l-1; i++)
		{
			if(str[i] == 'B' && str[i+1] == 'A')
			{
				printf("YES\n");
				return;
			}
		}
	}

	temp = -1;

	for(int i=0; i<l-1; i++)
	{
		if(str[i] == 'B' && str[i+1] == 'A')
		{
			temp = i+2;
			break;
		}
	}
	if(temp != -1)
	{
		for(int i=temp; i<l-1; i++)
		{
			if(str[i] == 'A' && str[i+1] == 'B')
			{
				printf("YES\n");
				return;
			}
		}
	}

	printf("NO\n");
	return;	
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	scanf("%s",str);
	int l = strlen(str);

	func(l);
}