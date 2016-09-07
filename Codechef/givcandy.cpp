#include <bits/stdc++.h>
#define LL long long
using namespace std;

template <typename T> T extended_euclidean(T a, T b, T &x, T &y)
{
	if(b==0)
	{
		x = 1;
		y = 0;
		return a;
	}
	T x1,y1;
	T d = extended_euclidean(b, a%b, x1, y1);
	x = y1;
	y = x1 - (a/b)*y1;
	return d;
}

LL gcd(LL a, LL b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	int t;
	LL a,b,c,d,ans,g;
	cin>>t;

	while(t--)
	{
		scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
		LL g = gcd(c,d);
		// y = -y;
		LL x;
		if(a==b)
			ans = 0;
		if(b>a)
		{
			ans = (b-a)%g;
			x = ans-g;
			x = -x;
			ans = min(ans,x);
		}
		else
		{
			ans = (a-b)%g;
			x = ans-g;
			x = -x;
			ans = min(ans,x);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

/*(A+cx) - (B+Dy)*/
/*(B+Dy) - (A+cx)*/