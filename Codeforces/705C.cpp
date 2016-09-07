#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	
	int n,q,type,xort,unread=0,curr=0,read,x;
	cin>>n>>q;

	vector< pair< pair<int, int>, int > > notifs(n+1,make_pair(make_pair(0,0),0)); // first.first = read, first.second = readupto , second = total
	vector<int> order;
	order.push_back(0);

	while(q--)
	{
		cin>>type>>xort;
		if(type==1)
		{
			order.push_back(xort);
			notifs[xort].second++;
			unread++;
		}
		else if(type==2)
		{
			unread -= (notifs[xort].second - notifs[xort].first.first);
			notifs[xort].first.first = notifs[xort].second;
		}
		else
		{
			if(xort>curr)
			{
				for(int i=curr+1; i<=xort; i++)
				{
					x = order[i];
					notifs[x].first.second++;
					if(notifs[x].first.second > notifs[x].first.first)
					{
						notifs[x].first.first++;
						unread--;
					}
				}
				curr = xort;
			}
		}
		cout<</*notifs[1].first.first<<"\t"<<notifs[1].first.second<<"\t"<<notifs[1].second<<"\t"<<*/unread<<"\n";
	}
	return 0;
}