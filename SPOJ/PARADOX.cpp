#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define scani(n) scanf("%d",&n);
#define endl '\n'
#define EPS 1e-9
#define FOR(i,n) for(int i=0; i<n; i++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define X first
#define Y second
#define for0(i,n) for(int i=0; i<n; i++)
#define for1(i,n) for(int i=1; i<=n; i++)
#define forr(i,n) for(int i=n-1; i>=0; i--)

typedef long long LL;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const int MOD = 1e9+7;
const int n_ = 1e5+1000;
const long double PI = acos(-1.0);

LL gcd (LL a, LL b) {return ( a ? gcd(b%a, a) : b );}
LL power(LL a, LL n) {LL p = 1;while (n > 0) {if(n%2) {p = p * a;} n >>= 1; a *= a;} return p;}
LL power(LL a, LL n, LL mod) {LL p = 1;while (n > 0) {if(n%2) {p = p * a; p %= mod;} n >>= 1; a *= a; a %= mod;} return p % mod;}

pair<int,bool> input[110];
bool visited[110];
bool assigned[110];

int n;

bool dfs(int node)
{
	int next = input[node].X;
	bool nextval = input[node].Y;
	bool flag = false;
	if(assigned[node] == false)
		nextval = !nextval;

	if(visited[next] && assigned[next] != nextval)
	{
		visited[node] = false;
		return false;
	}

	if(!visited[next])
	{
		flag = true;
		visited[next] = true;
		assigned[next] = nextval;
		bool temp = dfs(next);
		if(!temp)
		{
			visited[next] = false;
			visited[node] = false;
			return false;
		}
	}
	return true;
}

bool func()
{
	for(int i=1; i<=n; i++)
	{
		visited[i] = false;
	}

	for(int i=1; i<=n; i++)
	{
		visited[i] = true;
		assigned[i] = true;
		bool a = dfs(i);
		if(!a)
		{
			visited[i] = true;
			assigned[i] = false;
			a = dfs(i);
			if(!a)
				return false;
		}
	}

	// visited[1] = true;
	// assigned[1] = true;
	// bool a = dfs(1);
	// if(a)
	// 	return true;
	// for(int i=1; i<=n; i++)
	// 	visited[i] = false;
	// visited[1] = true;
	// assigned[1] = false;
	// a = dfs(1);
	return true;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	// int n;
	cin>>n;
	int a;
	string b;
	while(n != 0)
	{
		for(int i=1; i<=n; i++)
		{
			cin>>a>>b;
			if(b[0] == 'f')
				input[i] = mp(a,false);
			else
				input[i] = mp(a,true);


			
		}
		if(func())
			cout<<"NOT PARADOX\n";
		else
			cout<<"PARADOX\n";
		// cout<<func(n)<<endl;
		cin>>n;
	}
	
	return 0;
}