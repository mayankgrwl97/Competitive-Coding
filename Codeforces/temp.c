#include <stdio.h>

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	printf("%d",2^3);
	
	return 0;
}