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

int x[] = {0, 0, 1, 1, 1,-1,-1, -1};
int y[] = {1,-1, 0, 1,-1, 0, 1, -1};

bool occupied[1010][1010];

bool valid(int i, int j, int si, int sj)
{
	if(i>=0 && i<8 && j>=0 && j<8)
	{
		// return !occupied[i][j];
		if(i == si)

		if(j == sj)

	}

	return false;
}

void func(int n, int m, int fi, int fj, int si, int sj)
{
	queue<pair<pair<int,int>,int > > q;
	q.push(mp(mp(si,sj),0));

	int curri,currj,dis;

	while(!q.empty())
	{
		pair<pair<int,int>,int > curr = q.front();
		curri = curr.X.X;
		currj = curr.X.Y;

		cout<<curri

		dis = curr.Y;
		q.pop();

		if(curri == fi && currj == fj)
		{
			cout<<dis<<endl;
			return;
		}

		for(int i=0; i<8; i++)
		{
			for(int j=1; j<=8; j++)
			{
				if(valid(curri + j*x[i], currj + j*y[i]))
					q.push(mp(mp(curri + j*x[i], currj + j*y[i]),dis+1));
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