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

int max3(int a, int b, int c)
{
	return max(a,max(b,c));
}

int func2(int H, int A, int fwa, int count)
{
	if(H<=0 || A<=0)
		return 0;
	else
	{
		
	}

}

int func(int H, int A)
{
	int count = 0
	int a = func(H+3, A+2, 0, count);
	int b = func(H-5, A-10, 1, count);
	int c = func(H-20, A-5, 2, count);
	return max3(a,b,c);
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t;cin>>t;

	while(t--)	
	{
		cin>>H>>A;
		cout<<func(H,A);
	}
	
	return 0;
}