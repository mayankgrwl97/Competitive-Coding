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

	int n;
	cin>>n;

	int a;

	set<int> myset;
	set<int>::iterator it;
	for(int i=0; i<n; i++)
		cin>>a, myset.insert(a);	

	it = myset.begin();
	int s = myset.size();

	if(s==1 || s==2)
	{
		cout<<"YES";
		return 0;
	}
	else if(s==3)
	{
		int a = *it;
		it++;
		int b = *it;
		it++;
		int c = *it;
		if(c-b == b-a)
		{
			cout<<"YES";
		}
		else
			cout<<"NO";
		return 0;
	}
	else
	{
		cout<<"NO";
		return 0;
	}


	return 0;
}