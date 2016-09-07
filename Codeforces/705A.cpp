#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	string hate = "I hate ";
	string love = "I love ";
	string that = "that ";
	string it = "it";

	cout<<hate;

	for(int i=1; i<n; i++)
	{
		if(i%2)
			cout<<that<<love;
		else
			cout<<that<<hate;
	}
	cout<<it;
	return 0;
}