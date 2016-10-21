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

LL a[100100];

void func(int n)
{
	int i=0;
	int j=n-1;
	int ct = 0;
	while(i<j)
	{
		if(a[i] == a[j])
		{
			i++;
			j--;
		}
		else
		{
			ct++;
			if(a[i] < a[j])
			{
				a[i+1] += a[i];
				i++;
			}
			else
			{
				a[j-1] += a[j];
				j--;
			}
		}
	}
	cout<<ct<<'\n';
	return;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t,n;
	cin>>t;

	while(t--)	
	{
		cin>>n;
		FOR(i,n)
			cin>>a[i];
		func(n);
	}

	
	return 0;
}