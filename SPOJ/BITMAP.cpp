#include <bits/stdc++.h>
#define MAX 182
using namespace std;

string str[MAX];
int dis[MAX][MAX];

int isvalid(int a, int b, int n, int m)
{
	return (a>=0 && a<n && b>=0 && b<m && str[a][b] != '1');
}

void func(int n, int m)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			dis[i][j] = INT_MAX;
		}
	}

	queue<pair<int,int> > myqueue;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(str[i][j] == '1')
			{
				myqueue.push(make_pair(i,j));
				dis[i][j] = 0;
			}
		}
	}

	pair<int,int> temp;
	int ri,ci;

	while(!myqueue.empty())
	{
		temp = myqueue.front();
		ri = temp.first;
		ci = temp.second;
		myqueue.pop();

		if(isvalid(ri+1, ci, n, m))
		{
			if(dis[ri+1][ci] > dis[ri][ci] + 1)
			{
				dis[ri+1][ci] = dis[ri][ci] + 1;
				myqueue.push(make_pair(ri+1,ci));
			}
		}
		if(isvalid(ri, ci+1, n, m))
		{
			if(dis[ri][ci+1] > dis[ri][ci] + 1)
			{
				dis[ri][ci+1] = dis[ri][ci] + 1;
				myqueue.push(make_pair(ri,ci+1));
			}

		}
		if(isvalid(ri-1, ci, n, m))
		{
			if(dis[ri-1][ci] > dis[ri][ci] + 1)
			{
				dis[ri-1][ci] = dis[ri][ci] + 1;
				myqueue.push(make_pair(ri-1,ci));
			}
		}
		if(isvalid(ri, ci-1, n, m))
		{
			if(dis[ri][ci-1] > dis[ri][ci] + 1)
			{
				dis[ri][ci-1] = dis[ri][ci] + 1;
				myqueue.push(make_pair(ri,ci-1));
			}
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<dis[i][j]<<' ';
		}
		cout<<'\n';
	}
	return ;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t,n,m;
	cin>>t;

	while(t--)
	{
		cin>>n>>m;
		for(int i=0; i<n; i++)
		{
			cin>>str[i];
		}
		func(n,m);
	}
	
	return 0;
}