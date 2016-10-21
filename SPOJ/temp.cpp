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

string str;
bool occupied[1010][1010];
bool visited[1010][1010];
pii previous[1010][1010];
int distance[1010][1010];

void clean(int n, int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            visited[i][j] = false;
            distance[i][j] = INT_MAX;
        }
    }
    return ;
}

bool valid(int i, int j, int n, int m)
{
    return (i>=0 && i<n && j>=0 && j<m && (i!=0 || j!=0)); 
}

void func(int n, int m, int fi, int fj, int si, int sj)
{
    previous[si][sj] = mp(si,sj);

    queue<pii> q;
    distance[si][sj] = 0;
    q.push(mp(si,sj));

    while(!q.empty())
    {
        int curri = q.front().X;
        int currj = q.front().Y;
        int currd = distance[curri][currj];
        q.pop();
        int deltai = curri-previous[curri][currj].X;
        int deltaj = currj-previous[curri][currj].Y;

        for(int i=-1; i<2; i++)
        {
            for(int j=-1; j<2; j++)
            {
                int nexti = curri + i;
                int nextj = currj + j;
                if(valid(nexti, nextj, n, m) && distance[nexti][nextj] != INT_MAX && !occupied[nexti][nextj])
                {
                    if(nexti)
                }
            }
        }
    }
}

void func(int n, int m, int fi, int fj, int si, int sj)
{
    visited[si][sj] = true;
    previous[si][sj] = mp(si,sj);

    queue<pair<pii,int> > q;
    q.push(mp(mp(si,sj),0));

    while(!q.empty())
    {
        int curri = q.front().X.X;
        int currj = q.front().X.Y;
        int currd = q.front().Y;
        q.pop();

        int previ = previous[curri][currj].X;
        int prevj = previous[curri][currj].Y;

        if(curri == fi && currj == fj)
        {
            cout<<currd<<endl;
            return ;
        }

        for(int i=-1; i<2; i++)
        {
            for(int j=-1; j<2; j++)
            {
                if(i==0 && j==0)
                    continue;
                int nexti = curri + i;
                int nextj = currj + j;
                if(valid(nexti, nextj, n, m) && !visited[nexti][nextj] && !occupied[nexti][nextj])
                {
                    previous[nexti][nextj] = mp(curri,currj);
                    visited[nexti][nextj] = true;
                    if(curri-previ == nexti-curri && currj-prevj == nextj-currj)
                        q.push(mp(mp(nexti,nextj),currd));
                    else
                        q.push(mp(mp(nexti,nextj),currd+1));
                }
            }
        }
    }
    cout<<-1<<endl;
    return ;
}


int main()
{
    io;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        // freopen("output.txt","w",stdout);
    #endif

    int t,n,m;
    int si,sj,fi,fj;
    cin>>t;

    while(t--)  
    {
        cin>>n>>m;
        for(int i=0; i<n; i++)
        {
            cin>>str;
            for(int j=0; j<m; j++)
            {
                if(str[j] == 'S')
                    si = i,sj = j;
                else if(str[j] == 'F')
                    fi = i,fj = j;
                else if(str[j] == '.')
                    occupied[i][j] = false;
                else if(str[j] == 'X')
                    occupied[i][j] = true;
            }
        }
        func(n,m,fi,fj,si,sj);
    }    
    
    return 0;
}