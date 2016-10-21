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

int r,c;
char graph[52][52];
bool visited[52][52];

bool valid(int ri, int ci)
{
	return (ri>=0 && ri<r && ci>=0 && ci<c);
}

int dfs(int ri, int ci)
{
	int l = graph[ri][ci] - 'A' + 1;

	for(int i=-1; i<=1; i++)
	{
		for(int j=-1; j<=1; j++)
		{
			int nxt_ri = ri+i;
			int nxt_ci = ci+j;
			if(valid(nxt_ri,nxt_ci) && !visited[nxt_ri][nxt_ci] && (graph[nxt_ri][nxt_ci] == (graph[ri][ci]+1)))
			{
				visited[nxt_ri][nxt_ci] = true;
				l = max(l,dfs(nxt_ri,nxt_ci));
				if(l == 26)
				{
					// visited[ri][ci] = false;
					return l;
				}
			}
		}
	}
	// visited[ri][ci] = false;
	return l;
}

void func()
{
	int ans = 0;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			visited[i][j] = false;
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			if(graph[i][j] == 'A')
			{
				visited[i][j] = true;
				ans = max(ans, dfs(i,j));
			}
			if(ans == 26)
			{
				cout<<ans<<endl;
				return ;
			}
		}
	}
	cout<<ans<<endl;
	return ;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t = 1;
	cin>>r>>c;
	while(r>0 && c>0)
	{
		for(int i=0; i<r; i++)
			cin>>graph[i];
		cout<<"Case "<<t<<":"<<" ";
		t++;
		// printf("Case %d: ",t++);
		func();
		cin>>r>>c;
	}
		
	
	return 0;
}