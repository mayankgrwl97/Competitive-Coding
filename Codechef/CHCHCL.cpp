#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t,n,m;
	scanf("%d",&t);
	
	while(t--)
	{
		scanf("%d %d ",&n,&m);
		if(n%2 == 0 || m%2 == 0)
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	
	return 0;
}
