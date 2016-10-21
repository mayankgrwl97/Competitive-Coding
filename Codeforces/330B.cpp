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

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,m,a,b;
	cin>>n>>m;
	vi visited(n+1,0);
	// return 0;
	FOR(i,m)
		cin>>a>>b, visited[a] = visited[b] = 1;
		// return 0;
	int t;
	FOR(i,n)
	{
		// cout<<visited[i+1];
		if(visited[i+1] == 0)
			t = i+1;
		visited[i+1] = 0;
	}
	visited[t] = 1;
	// cout<<t;
	cout<<n-1<<endl;
	FOR(i,n)
	if(!visited[i+1])
		cout<<t<<' '<<i+1<<'\n';	
	
	return 0;
}