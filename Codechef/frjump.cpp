#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;

int arr[100100];
long double pre_log[100100];

template <typename T>T mod(T a, T b) {return (a < b ? a : a % b);}
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template <typename T>T InverseEuler(T a, T m){return (a==1?1:power(a,m-2,m));}

void pre_compute(int n)
{
	LL prod = 1;
	for(int i=1; i<=n; i++)
	{
		pre_log[i] = log10l(arr[i]);
		prod = mod(prod*arr[i], MOD);
	}
	return;
}

int first_digit(int n)
{
	while(n>=10)
	{
		n = n/10;
	}
	return n;
}

void func(int r, int n)
{
	long double sum = 0;
	LL prod = 1;
	for(int i=1; i<=n; i+=r)
	{
		// sum += log10((long double)arr[i]);
		sum += pre_log[i];
		prod = (prod*arr[i])%MOD;
	}
	sum = sum - (int)sum;
	long double p = powl(10,sum);
	int x = (int)p;
	int f = first_digit(x);
	printf("%d %lld\n",f,prod);
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	int n,t,q,p,f,r;
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		scanf("%d",arr+i);
	}
	pre_compute_log(n);
	cin>>q;
	while(q--)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d %d",&p, &f);
			arr[p] = f;
			pre_log[p] = log10l(arr[p]);
		}
		else
		{
			scanf("%d",&r);
			func(r,n);
		}
	}
	return 0;
}

	// cout<<sum;

	// cout<<"\n";

	// cout<<sum;

	// cout<<"\n";

	// printf("%0.20lf",p);

	// cout<<p;

	// cout<<"\n";

	// cout<<x;

	// cout<<"\n";
