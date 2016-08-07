#include <bits/stdc++.h>
#define LL long long int
using namespace std;

bool waytosort(pair<LL,LL> a, pair<LL,LL> b){return a.first > b.first;};

int main()
{
	freopen("input.txt","r",stdin);
	int t,n;
	cin>>t;

	pair<LL,LL> input[250];//radius,height
	LL dp[250];
	LL ht,max,tmp;

	while(t--)
	{
		ht = 0;
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cin>>input[i].first>>input[i].second;
		}
		
		sort(input,input+n,waytosort);
		/*for(int i=0; i<n; i++)
		{
			cout<<input[i].first<<" ";	
		}
		cout<<"\n";
		for(int i=0; i<n; i++)
		{
			cout<<input[i].second<<" ";	
		}
		cout<<"\n";*/
		dp[0] = ht = input[0].second;
		// printf("%d ",dp[0] );
		for(int i=1; i<n; i++)
		{
			max = input[i].second;
			for(int j=0; j<i; j++)
			{
				if((input[i].second < input[j].second) && (input[i].first < input[j].first))
				{
					tmp = input[i].second + dp[j];
					if(tmp>max)
						max = tmp;
				}
			}
			dp[i] = max;
			// printf("%d ",dp[i] );

			if(ht<max)
				ht = max;
		}
		printf("%lld\n", ht);
	}	
	return 0;
}