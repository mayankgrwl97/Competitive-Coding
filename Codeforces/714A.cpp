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

	LL l1,r1,l2,r2,k;
	cin>>l1>>r1>>l2>>r2>>k;
	l1 = max(l1,l2);
	r1 = min(r1,r2);

	LL ans = r1-l1 + 1;
	if(l1>r1)
	{
		cout<<0;
		return 0;
	}

	if(k>=l1 && k<=r1)
		ans--;
	cout<<ans;
	


	return 0;
}
