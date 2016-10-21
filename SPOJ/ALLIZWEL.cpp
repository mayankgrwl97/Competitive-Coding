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

int dir[] = {-1,0,1};
string str = "ALLIZZWELL";
char graph[110][110];
bool visited[110][110];
int l=0;
int r,c;
bool isvalid(int i, int j)
{
	return (i<r && j<c);
}

bool dfs(int ri, int ci)//ri = row index //ci = column index
{
	if(graph[ri][ci] == str[l])
	{
		if(l==9)
			return true;
		l++;
		for(int i=-1; i<2; i++)
			for(int j=-1; j<2; j++)
			{
				// if(i==0 && j==0)
				// 	continue;
				int new_ri = ri+i;
				int new_ci = ci+j;
				if(isvalid(new_ri,new_ci) && !visited[new_ri][new_ci])
				{
					visited[new_ri][new_ci] = true;
					bool curr = dfs(new_ri,new_ci);
					if(curr)
						return true;
				}
			}
		l--;
	}
	visited[ri][ci] = false;
	return false;
}
/*
bool dfs(int ri, int rj)
{
	// if(l==9 && graph[ri][rj] == str[l])
	// 	return true;
	// if(l>9)
	// 	return false;
	// if(graph[ri][rj] != str[l])
	// 	return false;

	// l++;
	// for(int i=0; i<3; i++)
	// {
	// 	for(int j=0; j<3; j++)
	// 	{
	// 		int new_ri = ri+dir[i];
	// 		int new_ci = ci+dir[j];
	// 		if(isvalid(new_ri, new_ci))
	// 			dfs(new_ri, new_ci);
	// 	}
	// }
	visited[ri][rj] = false;
	return ;
}*/

void func()
{
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			visited[i][j] = 0;

	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			l = 0;
			visited[i][j] = true;
			if(dfs(i,j))
			{
				cout<<"YES\n";
				return ;
			}
		}
	}
	cout<<"NO\n";
	return ;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t;
	cin>>t;

	while(t--)
	{
		cin>>r>>c;
		for(int i=0; i<r; i++)
			cin>>graph[i];
		l = 0;
		func();
	}
	
	return 0;
}