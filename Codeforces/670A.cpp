#include <bits/stdc++.h>
using namespace std;

int minim[] = {0,0,0,0,0,0,1,2};
int maxim[] = {0,1,2,2,2,2,2,2};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,quot,temp;
	cin>>n;

	if(n<=7)
	{
		cout<<minim[n]<<' '<<maxim[n];
	}
	else
	{
		quot = n/7;
		temp = n%7;
		cout<<quot*2 + minim[temp]<<' '<<quot*2 + maxim[temp] ;
	}
	
	return 0;
}