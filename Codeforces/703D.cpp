#include <bits/stdc++.h>
#define LL long long
using namespace std;

	int capital[100100];

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif


	int n,k,a,index;
	cin>>n>>k;
	int beauty[n+1];
	int indices[n+1];
	int nx[n+1];
	int pr[n+1];

	if(n == 1)
	{
		cout<<0<<'\n';
		return 0;
	}

	for(int i=1; i<=n; i++)
	{
		nx[i] = i%n+1;
		// nx.push_back(i%n + 1);
	}

	// pr.push_back(n);
	pr[1] = n;
	for(int i=2; i<=n; i++)
	{
		pr[i] = i-1;
	}

	for(int i=1; i<=n; i++)
	{
		cin>>beauty[i];
	}

	for(int i=1; i<=k; i++)
	{
		cin>>indices[i];
		capital[indices[i]]  = 1;
	}

	if(n == 2)
	{
		cout<<beauty[1] * beauty[2]<<'\n';
		return 0;
	}
	int q;
	LL sum = 0,temp = 0;

	for(int i=1; i<=n; i++)
	{
		sum += (LL)(beauty[i] * beauty[nx[i]]);
	}
	// cout<<sum<<'\n';

	for(int i=1; i<=n; i++)
	{
		if(!capital[i])
		for(int j=1; j<=k; j++)
		{
			if(indices[j]!=nx[i] && indices[j]!=pr[i])
				sum += (LL)(beauty[i] * beauty[indices[j]]);
		}
		else
		{
			for(int j=1; j<=k; j++)
			{
				if(indices[j]!=nx[i] && indices[j]!=pr[i] && indices[j] > i)
					sum += (LL)(beauty[i] * beauty[indices[j]]);
			}	
		}
	}
	cout<<sum<<"\n";
	return 0;
}