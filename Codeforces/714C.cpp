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
typedef struct node node;

struct node
{
	node* zero;
	node* one;
	int count;
};

node* newnode()
{
	node* p = (node*)malloc(sizeof(node));
	p->zero = NULL;
	p->one = NULL;
	p->count = 0;
	return p;
}

node* root;

void insert(LL n)
{
	node* p = root;
	int curr;
	// while(n>0)
	for(int i=0; i<18; i++)
	{
		curr = n%10;
		n=n/10;
		if(curr % 2 == 0)
		{
			if(p->zero != NULL)
			{
				p->zero->count++;
				p = p->zero;
			}
			else
			{
				p->zero = newnode();
				p->zero->count++;
				p = p->zero;
			}
		}
		else
		{
			if(p->one != NULL)
			{
				p->one->count++;
				p = p->one;
			}
			else
			{
				p->one = newnode();
				p->one->count++;
				p = p->one;
			}
		}
	}
	return ;
}

int del(LL n)
{
	node* p = root;
	node* temp;
	int curr;
	// while(n>0)
	for(int i=0; i<18; i++)
	{
		int curr = n%10;
		n = n/10;
		if(curr%2 == 0)
		{
			p->zero->count--;
			// temp = p->zero;
			// if(p->zero->count == 0)
			// 	p->zero = NULL;
			p = p->zero;
		}
		else
		{
			p->one->count--;
			// temp = p->one;
			// if(p->one->count == 0)
			// 	p->one = NULL;
			p = p->one;
		}
	}	
	return 1;
}

void find(LL n)
{
	// cout<<n<<':';
	node* p = root;
	int curr;
	int ans=0;
	for(int i=0; i<18; i++)
	{
		int curr = n%10;
		n = n/10;
		if(curr)//1
		{
			if(p->one == NULL)
			{
				cout<<0<<'\n';
				return ;
			}
			else
				ans = p->one->count;
			p = p->one;
		}
		else
		{
			if(p->zero == NULL)
			{
				cout<<0<<'\n';
				return ;
			}
			else
				ans = p->zero->count;
			p = p->zero;
		}
	}
	cout<<ans<<'\n';
	return;
}

int main()
{
	io;
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	root = newnode();
	int t;
	cin>>t;

	while(t--)
	{
		char ch;
		LL n;
		// scanf("%c %lld",&ch,&n);
		cin>>ch>>n;
		// cout<<ch<<n<<endl;

		if(ch == '+')
			insert(n);
		if(ch == '-')
			del(n);
		if(ch == '?')
			find(n);
	}

	// cout<<root->zero->count;
	return 0;
}