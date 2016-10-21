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

LL ht[100100];
int nxt[100100];
int prv[100100];

void fillnxt(int n)
{
	stack<int> st;

	for(int i=0; i<n; i++)
	{
		if(st.empty())
		{
			st.push(i);
			continue;
		}

		int j = st.top();
		if(ht[i] >= ht[j])
		{
			st.push(i);
			continue;
		}

		while(!st.empty())
		{
			int t = st.top();
			if(ht[t] > ht[i])
				st.pop(),nxt[t] = i;
			else
				break;
		}
		st.push(i);
	}
	while(!st.empty())
	{
		int t = st.top();
		nxt[t] = -1;
		st.pop();
	}
	// for(int i=0; i<n; i++)
	// 	cout<<nxt[i]<<'\t';
	return;
}

void fillprv(int n)
{
	stack<int> st;

	for(int i=n-1; i>=0; i--)
	{
		if(st.empty())
		{
			st.push(i);
			continue;
		}

		int j = st.top();
		if(ht[i] >= ht[j])
		{
			st.push(i);
			continue;
		}

		while(!st.empty())
		{
			int t = st.top();
			if(ht[t] > ht[i])
				st.pop(),prv[t] = i;
			else
				break;
		}
		st.push(i);
	}
	while(!st.empty())
	{
		int t = st.top();
		prv[t] = -1;
		st.pop();
	}
	// for(int i=0; i<n; i++)
	// 	cout<<prv[i]<<'\t';
	return ;
}

void func(int n)
{
	LL mx = LLONG_MIN, tmp;
	for(int i=0; i<n; i++)
	{
		if(nxt[i] == -1 && prv[i] == -1)
		{
			tmp = ht[i]*n;
		}
		else if(nxt[i] == -1)
		{
			tmp = ht[i]*(n-1-prv[i]);
		}
		else if(prv[i] == -1)
		{
			tmp = ht[i]*(nxt[i]);
		}
		else
		{
			tmp = ht[i]*(nxt[i]- 1 - prv[i]);
		}
		if(tmp>mx)
			mx = tmp;
		// cout<<tmp<<'\n';
	}
	cout<<mx<<'\n';
	return ;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	while(n!=0)	
	{
		FOR(i,n)
			cin>>ht[i];
		fillnxt(n);
		fillprv(n);
		func(n);
		cin>>n;
	}
	
	return 0;
}