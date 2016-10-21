#include <bits/stdc++.h>
#define lim 10000
#define pii pair<int,int>
#define mp make_pair
using namespace std;

int visited[30000];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;
	//n = n*2;
	//n = n-1

	if(n == m)
	{
		cout<<0;
		return 0;
	}

	queue<pii> q;
	q.push(mp(n,0));

	while(!q.empty())
	{
		pii temp = q.front();
		q.pop();
	
		int curr = temp.first;
		int clicks = temp.second;
		visited[curr] = 1;
		if(curr == m)
		{
			cout<<clicks;
			return 0;
		}
		if(curr < lim)
		{
			if(!visited[2*curr])
				q.push(mp(2*curr,clicks+1));
		}
		if(curr - 1 > 0)
		{
			if(!visited[curr-1])
				q.push(mp(curr-1,clicks+1));
		}
	}
	return 0;
}