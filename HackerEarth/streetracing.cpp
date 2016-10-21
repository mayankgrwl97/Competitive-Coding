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

double x[110];
double y[110];

double dis[110][110];
bool pos[110][110][110];

vi adj[110];
int graph[110][110];

void pre(int n, double a)
{
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            dis[i][j] = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            for(int k=1; k<=n; k++)
            {
                double theta = acos((x[j]-x[i])*(x[k]-x[j]) + (y[j]-y[i])*(y[k]-y[i]));
                if(theta < a+EPS)
                    pos[i][j][k] = true;
                else
                    pos[i][j][k] = false;
            }
        }
    }
    return ;
}

double dp[110][110][110];
bool visited[110][110][110];
bool vis[110];

double dfs(int p, int v, int f, double a)//p is the parent node //v is the child node //f is the final node //a is the theta limit
{
    if(v == f)
        return 0.0;

    double ans = INT_MAX;
    
    for(int i=0; i<adj[v].size(); i++)
    {
        int t = adj[v][i];
        if(pos[p][v][i])
        {
            if(visited[])
        }
    }
    return ans;    
}


double func(int s, int f, double a)
{
    if(s == f)
        return 0.0;

    double ans = INT_MAX;
    vis[s] = true;
    
    for(int i=0; i<adj[s].size())
    {
        int v = adj[s][i];
        ans = min(ans, dis[s][v] + dfs(s,v,f,a));
    }

    return ans;
}

int main()
{
	io;
	int n,m;
	double a;
	cin>>n>>m>>a;
	int s,f;
	cin>>s>>f;
    a = PI*a/180.0;
    pre();
    for(int i=1; i<=n; i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=0; i<m; i++)
    {
        cin>>q>>w;
        adj[q].pb(w);
        adj[w].pb(q);
        graph[q][w] = graph[w][q] = 1;
    }
	double ans = func(s,f,a);
    if(abs(ans-INT_MAX)<EPS)
        cout<<-1;
    else
        cout<<ans;
	return 0;
}