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

bool composite[100100];//a[i] = 0 for prime and even nos.(!=2); a[i] = 1 for not prime 
vector<int> p;

void sieve()//p is the vector which stores the primes starting from p[1] = 2.
{
	// p.push_back(0);
	composite[0]=1; composite[1]=1;
	// p.push_back(2);//p[1] = 2; => 1st prime

	for (long long i=3; i<100100; i=i+2)
	{
		if(composite[i] == 0)
		{
			// p.push_back(i);
			for(long long j=i*i; j<=100100; j=j+2*i)
				composite[j]=1;
		}
	}
	return ;
}

bool visited[100100];
// int prev[100100];
int dig[4];
int mypow[] = {1000,100,10,1};

void parse(int n)
{
	for(int i=3; i>=0; i--)
	{
		dig[i] = n%10;
		n=n/10;
	}
	return ;
}

/*void func(int n)
{
	stack<int> st;
	while(prev[n] != -1)
	{
		st.push(n);
	}
	while(!st.empty())
	{
		cout<<st.top();
		st.pop();
	}
	return;
}
*/
void bfs(int a, int b)
{
	for(int i=1000; i<=9999; i++)
		visited[i] = false;

	queue<pii> q;
	q.push(mp(a,0));
	// prev[a] = -1;

	while(!q.empty())
	{
		pii temp = q.front();
		int curr = temp.first;
		q.pop();
		visited[curr] = true;
		if(curr == b)
		{
			cout<<temp.second<<'\n';
			// func(b);
			return ;
		}

		parse(curr);

		for(int i=0; i<4; i++)
		{
			for(int j=0; j<10; j++)
			{
				if(i==0 && j==0)
					continue;
				int next = curr + (j-dig[i])*mypow[i];
				// cout<<next<<' ';
				if(next%2 && !composite[next] && !visited[next])
				{
					// cout<<next<<' ';
					// prev[next] = curr;
					q.push(mp(next,temp.second+1));
				}
			}
		}
	}

	cout<<"Impossible";
	return ;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	sieve();

	int t,a,b;
	cin>>t;

	while(t--)
	{
		cin>>a>>b;
		bfs(a,b);
	}
		
	
	return 0;
}