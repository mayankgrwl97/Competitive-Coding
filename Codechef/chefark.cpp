#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAX = 100005;
const LL MOD = 1000000007;		//a prime number

template <typename T>T mod(T a, T b) {return (a < b ? a : a % b);}
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p,m);p=mod(p*p,m);n>>=1;}return x;}
template <typename T>T InverseEuler(T a, T m){return (a==1?1:power(a,m-2,m));}

LL fact[MAX], invp[MAX];

void pre() {
	fact[0] = invp[0] = 1LL;
	for(int i=1; i<MAX; ++i) {
		fact[i] = mod(fact[i-1]*i, MOD);
		invp[i] = InverseEuler(fact[i], MOD);
	}
}

LL ncr(int n, int r) {
	if (r<0 || r>n) return 0LL;
	return mod(fact[n] * mod(invp[n-r]*invp[r], MOD), MOD);
}

int arr[100100];
/*int C[100100];
*/
LL modulo(LL n)
{
	if(n>MOD)
		return n%MOD;
	return n;
}

/* C(n-1,r) + C(n-1,r-1) = C(n,r) */

/*int ncr(int n, int k)
{
	for (int i = 0; i < k+1; ++i)
		C[i] = 0;

	C[0] = 1;

	for(int i=1; i<=n; i++)
	{
		for(int j=min(i,k); j>0; j--)
		{
			C[j] = modulo(C[j] + C[j-1]);
		}
	}
	return C[k];
}
*/
LL odd(LL n)
{
	if(n%2 != 0)
		return 1;
	return 0;
}

LL even(LL n)
{
	if(n%2 == 0)
		return 1;
	return 0;
}

void func(LL n, LL zero, LL k)
{
	LL count = 0;

	if(zero == 0)
	{
		if(even(k))
			count++;
		if(k>n)
		{
			if((even(k) && even(n)) || (odd(k) && odd(n)))
				k = n;
			else
				k = n-1;
		}
		for(LL i=k; i>0; i-=2)
		{
			count = modulo(count + ncr(n,i));
		}
	}
	else //zero != 0
	{
		count++; //no change in array
		n -= zero;
		if(k>n)
			k = n;
		for(LL i=k; i>0; i--)
		{
			count = modulo(count + ncr(n,i));
		}
	}
	printf("%lld\n",count);
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	int t;
	LL n,k,zero;
	cin>>t;

	// cout<<ncr(50,3);
	pre();
	while(t--)
	{
		zero = 0;
		scanf("%lld %lld",&n, &k);
		for (LL i = 0; i < n; ++i)
		{
			scanf("%d",arr+i);
			if(arr[i] == 0)
				zero++;
		}
		func(n,zero,k);
	}

	return 0;
}