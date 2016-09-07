#include <bits/stdc++.h>
#define LL long long
using namespace std;

struct MinHeap
{
	bool operator()(pair<LL,int> a, pair<LL,int> b)
	{
		if(a.first>b.first)
			return 1;
		return (a.second>b.second);
	}
};

vector< pair<int,int> > roads[100100]; //first = city //second = length
int isfloorcity[100100];
vector<int> floorcity; //city numbers of floorcities
LL mindistance[100100];

LL findmin(int start, int n)
{
	set<int> myset;
	set<int>::iterator it = myset.begin();
	LL minimum = LLONG_MAX;

	for(int i=1; i<=n; i++)
		mindistance[i] = LLONG_MAX;

	int l,c;
	pair<int,int> curr;
	pair<LL,int> temp;

	// priority_queue<pair<int,int> > myqueue; //first = distance // second = city
	priority_queue<pair<LL,int>, vector<pair<LL,int> >, MinHeap > myqueue;

	for(int i=1; i<=n; i++)
	{
		myqueue.push(make_pair(mindistance[i],i));
	}

	myqueue.push(make_pair(0,start));

	for(int i=0; i<n-1; i++)
	{
		temp = myqueue.top();
		myqueue.pop();
		if(myset.find(temp.second) != myset.end())//temp.second is already present in set
		{
			while(myset.find(temp.second) != myset.end())
			{
				temp = myqueue.top();
				myqueue.pop();
			}
		}
		myset.insert(temp.second);

		l = roads[temp.second].size();
		mindistance[temp.second] = temp.first;
		// cout<<i<<' '<<temp.second<<' '/*<<temp.first*/<<'\n';

		if(!isfloorcity[temp.second] && minimum>temp.first)
			minimum = temp.first;

		if(temp.first != LLONG_MAX)
		for(int j=0; j<l; j++)
		{
			curr = roads[temp.second][j];
			c = curr.second;
			if(mindistance[curr.first] > mindistance[temp.second] + c)
			{
				mindistance[curr.first] = mindistance[temp.second] + c;
				myqueue.push(make_pair(mindistance[curr.first], curr.first));
			}
		}
	}
	temp = myqueue.top();
	myqueue.pop();
	if(myset.find(temp.second) != myset.end())
	{
		while(myset.find(temp.second) != myset.end())
		{
			temp = myqueue.top();
			myqueue.pop();
		}
	}
	myset.insert(temp.second);
	if(!isfloorcity[temp.second] && minimum>temp.first)
		minimum = temp.first;
	// cout<<myset.size()<<'\n';
	return minimum;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,m,k;
	cin>>n>>m>>k;

	int u,v,l;
	for(int i=0; i<m; i++)
	{
		cin>>u>>v>>l;
		roads[u].push_back(make_pair(v,l));
		roads[v].push_back(make_pair(u,l));
	}
	
	for(int i=0; i<k; i++)
	{
		cin>>l;
		isfloorcity[l] = 1;
		floorcity.push_back(l);
	}

	LL minimum,temp;
	minimum = LLONG_MAX;
	for(int i=0; i<k; i++)
	{
		temp = findmin(floorcity[i],n);
		if(temp<minimum)
			minimum = temp;
	}
	if(minimum ==LLONG_MAX)
		cout<<-1;
	else
		cout<<minimum;
	return 0;
}