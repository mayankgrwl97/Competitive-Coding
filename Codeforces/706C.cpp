#include <bits/stdc++.h>
#define LL long long
using namespace std;

vector<int> c;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,a;
	cin>>n;

	c.push_back(0);

	for(int i=1; i<=n; i++)
	{
		cin>>a;
		c.push_back(a);
	}

	string s1,s2;
	string rs1,rs2;
	LL dp1[n+1]; //dp1[i] :- strings upto i are arranged and i is unchanged
	LL dp2[n+1]; //dp2[i] :- strings upto i are arranged and i is reversed

	dp1[1] = 0;
	dp2[1] = c[1];

	cin>>s1;
	rs1 = s1;
	reverse(rs1.begin(), rs1.end());

	for(int i=2; i<=n; i++)
	{
		cin>>s2;
		rs2 = s2;
		reverse(rs2.begin(), rs2.end());

		dp1[i] = dp2[i] = LLONG_MAX;

		if(s1<=s2 && rs1<=s2)
			dp1[i] = min(dp2[i-1],dp1[i-1]);
		else if(s1<=s2)
			dp1[i] = dp1[i-1];
		else if(rs1<=s2)
			dp1[i] = dp2[i-1];

		if(s1<=rs2 && rs1<=rs2)
			dp2[i] = min(dp1[i-1],dp2[i-1])+c[i];
		else if(s1<=rs2 && dp1[i-1]!=LLONG_MAX)
			dp2[i] = dp1[i-1]+c[i];
		else if(rs1<=rs2 && dp2[i-1]!=LLONG_MAX)
			dp2[i] = dp2[i-1]+c[i];
		if(dp1[i] == LLONG_MAX && dp2[i] == LLONG_MAX)
		{
			printf("-1\n");
			return 0;
		}
		s1 = s2;
		rs1 = rs2;
	}
	
	LL ans = min(dp1[n],dp2[n]);
	cout<<ans<<"\n";
	return 0;
}