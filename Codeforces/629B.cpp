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

int male[400];
int female[400];

void func(int n)
{
	int ans = 0;
	for(int i=1; i<=400; i++)
	{
		ans = max(ans,min(male[i],female[i]));
	}
	cout<<2*ans;
	return ;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n;cin>>n;
	int a,b;
	char ch;

	for(int i=0; i<n; i++)
	{
		cin>>ch>>a>>b;
		if(ch=='M')
		{
			for(int i=a; i<=b; i++)
				male[i]++;
		}
		else
		{
			for(int i=a; i<=b; i++)
				female[i]++;	
		}
	}
	func(n);
	return 0;
}