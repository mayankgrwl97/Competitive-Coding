#include <bits/stdc++.h>
using namespace std;


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	int t,n;
	cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		if(n%6 == 0)
			printf("Misha\n");
		else
			printf("Chef\n");
	}
	return 0; 
}

/*ci, mi > 0 belonging to {1,p^x}
c1 + m1 + c2 + m2 + c3 + m3 + .... + ci = n => chef wins
c1 + m1 + c2 + m2 + c3 + m3 + .... + ci + mi = n => misha wins*/