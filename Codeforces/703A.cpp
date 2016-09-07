#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,a,b,ctm,ctc;
	cin>>n;
	ctc = ctm = 0;

	for(int i=0; i<n; i++)
	{
		cin>>a>>b;
		if(a>b)
			ctm++;
		else if(b>a)
			ctc++;
	}
	// cout<<ctc<<ctm;
	if(ctc>ctm)
		cout<<"Chris\n";
	else if(ctm>ctc)
		cout<<"Mishka\n";
	else
		cout<<"Friendship is magic!^^\n";

	
	return 0;
}