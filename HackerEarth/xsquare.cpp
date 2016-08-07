#include <bits/stdc++.h>
#define LL long long int

using namespace std;

LL func(LL A[], int n)
{
	if(n==1 || n==2)
		return 0;
	else
		return A[n-2];
}

LL query(LL A[], LL B[], int x, int l, int r)
{
	r = r-l+1;
	if(x == 1)
	{
		if(r%2 == 0)
		{
			return (A[l+r-2]-func(A,l)) + (B[l+r-1]-func(B,l+1));
		}
		else
		{
			return (A[l+r-1]-func(A,l)) + (B[l+r-2]-func(B,l+1));
		}
	}
	else
	{
		if(r%2 == 0)
		{
			return (B[l+r-2]-func(B,l)) + (A[l+r-1]-func(A,l+1));
		}
		else
		{
			return (B[l+r-1]-func(B,l)) + (A[l+r-2]-func(A,l+1));
		}		
	}
}

int main()
{
	// freopen("input.txt","r",stdin);

	int n,q,x,l,r;
	cin>>n>>q;

	LL A[n+1],B[n+1];

	for(int i=1; i<=n; i++)
	{
		scanf("%lld", A+i);
		if(i>2)
		{
			A[i] = A[i] + A[i-2];
		}
	}
	for(int i=1; i<=n; i++)
	{
		scanf("%lld", B+i);	
		if(i>2)
		{
			B[i] = B[i] + B[i-2];
		}
	}

	while(q--)
	{
		scanf("%d %d %d", &x, &l, &r);
		printf("%lld\n",query(A ,B ,x, l,r));
	}
	return 0;
}