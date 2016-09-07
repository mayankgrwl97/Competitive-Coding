#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;

int arr[100100];
long double pref[100100];
LL product;

LL modulo(LL a)
{
	if(a>MOD)
		return a%MOD;
	else
		return a;
}

void pre(int n,int k)
{
	product = 1;
	for(int i=1; i<=n; i++)
		product = modulo(product*arr[i]);

	pref[1] = log10(arr[1]);
	for(int i=k; i<=n; i++)
	{
		pref[i] = pref[i-1] + log10(arr[i]);
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

	if(r==1)
	{
		sum = pref[n];
		prod = product;
	}
	else
		for(int i=1; i<=n; i+=r)
		{
			sum += log10(arr[i]);
			prod = modulo(prod*arr[i]);
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

	pre(n,2);

	cin>>q;
	
	while(q--)
	{
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d %d",&p, &f);
			arr[p] = f;
			pre(n,p);
		}
		else
		{
			scanf("%d",&r);
			func(r,n);
		}
	}
	return 0;
}