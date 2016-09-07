#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL ex_euclid(LL a, LL b, LL* x, LL* y)
{
	if(b==0)
	{
		*x = 1;
		*y = 0;
		return a;
	}
	LL d1,x1,y1;

	d1 = ex_euclid(b, a%b, &x1, &y1);
	*x = y1;
	*y = x1 - (a/b)*y1;
	return d1;
}

LL ceil(LL a,LL b)
{
	if(a%b == 0)
		return a/b;
	else if((a<0 && b>0) || (a>0 && b<0))
		return a/b;
	else
		return (a/b) + 1;
}

LL max(LL a, LL b)
{
	return (a>b ? a : b);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int q;
	LL a,d,n,k,m,g,tl,tu,t;
	// int n;
	// cout<< ex_euclid(7,-6,&k,&m);
	// cout<<m;
	cin>>q;
	while(q--)
	{
		scanf("%lld %lld",&a,&d);
		scanf("%lld",&n);
		g = ex_euclid(n, d, &k, &m);
		m = -m;
		cout<<"g = "<<g<<"\n";
		if(a%g != 0)
			printf("-1\n");
		else
		{
			cout<<"k = "<<k<<"\n";
			k = k*(a/g);
			cout<<"k = "<<k<<"\n";
			cout<<"m = "<<m<<"\n";
			m = m*(a/g);
			cout<<"m = "<<m<<"\n";
			tl = ceil(-k,(d/g));
			// cout<<"tl = "<<tl<<"\n";
			tu = ceil(-m,(n/g));
			t = max(tl,tu);
			m = m + (n/g)*t;
			printf("%lld\n", m);
		}
	}

	return 0;
}

// a + md = nk
// nk - md = a
// nk + (-d)m = a
// ax + by = c
// k = x0 - (-d/g)t >= 0
// m = m0 + (n/g)t >= 0