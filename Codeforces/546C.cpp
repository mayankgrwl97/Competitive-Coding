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

	int k1;
	cin>>k1;

	queue<int> st1;
	queue<int> st2;

	for(int i=0; i<k1; i++)
		cin>>a,st1.push(a);

	int k2;
	cin>>k2;

	for(int i=0; i<k2; i++)
		cin>>a,st2.push(a);

	return 0;
}