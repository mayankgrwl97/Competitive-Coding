#include <bits/stdc++.h>
using namespace std;

char str[100100];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	scanf("%s",str);
	int ab = 0;
	int ba = 0;
	int bab = 0;
	int aba = 0;
	int l = strlen(str);

	for(int i=0; i<l-1; i++)
	{
		if(str[i] == 'A' && str[i+1] == 'B')
		{
			ab++;
		}
		else if(str[i] == 'B' && str[i+1] == 'A')	
		{
			ba++;
		}
	}

	for(int i=1; i<l-1; i++)
	{
		if(str[i] == 'B' && str[i-1] == 'A' && str[i+1] == 'A')
			aba++;
		else if(str[i] == 'A' && str[i-1] == 'B' && str[i+1] == 'B')
			bab++;
	}

	if(ab == 0 || ba == 0)
		printf("NO\n");
	else if(ab == ba && ba == aba)
		printf("NO\n");
	else if(ab == ba && ba == bab)
		printf("NO\n");
	else
		printf("YES\n");

	return 0;
}