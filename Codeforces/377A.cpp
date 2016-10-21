#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define scani(n) scanf("%d",&n);
#define MOD (ll)1000000007
#define endl '\n'
#define EPS 1e-9
#define FOR(i,n) for(int i=0; i<n; i++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

int isnode[3000];
vector<pair<int,vi> > graph;

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,m,k;
	cin>>n>>m>>k;
	string str;
	for(int i=0; i<n; i++)
	{
		cin>>str;
		// cout<<str;
		for(int j=0; j<m; j++)
		{
			if(str[j]=='.')
			{
				isnode[(i*n)+j] = 1;
				graph.pb(mp(i*n+j, vector<int>()));
			}
		}
	}
	// cout<<graph.size();
	// func(n,m,k);
	
	return 0;
}