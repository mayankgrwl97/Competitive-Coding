#include <bits/stdc++.h>
using namespace std;

string str;

void func()
{
	int flag = 0;
	int l = str.length();
	for(int i=0; i<(l/2); i++)
	{
		if(str[i] != str[l-i-1])
		{
			str[l-i-1] = str[i];
			flag = 1;
		}
		else
		{
			str[l-i-1] = str[i];
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--)
	{
		cin>>str;
		func(str);
	}
	
	return 0;
}