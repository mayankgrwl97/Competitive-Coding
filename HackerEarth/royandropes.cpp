#include <bits/stdc++.h>
using namespace std;

int upper[1000010];
int lower[1000010];

int main()
{
	freopen("input.txt","r",stdin);
	int t,l,max,tmp;
	cin>>t;
	while(t--)
	{
		max = 0;
		scanf("%d",&l);
		for(int i=1; i<=l-1; i++)
		{
			scanf("%d",upper+i);
		}
		for(int i=1; i<=l-1; i++)
		{
			scanf("%d",lower+i);
		}
		for(int i=1; i<=l-1; i++)
		{
			if(upper[i]>lower[i])
				lower[i] = upper[i];
			tmp = lower[i]-(l-i);
			if(tmp>0 && max<tmp)
				max = tmp;
		}
		printf("%d\n", l+max);
	}
	return 0;
}