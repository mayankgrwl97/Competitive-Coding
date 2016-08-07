#include <bits/stdc++.h>
#define LL long long int
using namespace std;

int is_sq(LL i)
{
	LL x = (LL)sqrt((double)i);
	if(x*x == i)
		return 1;
	return 0;
}

void func(LL l, LL r)
{
	LL x = (LL)sqrt(l);
	LL y = (LL)sqrt(r);

	if(x*x != l)
		x++;
	printf("%lld\n", y-x+1);
}

int main()
{
	freopen("input.txt","r",stdin);

	int t;
	LL l,r,x,sum = 0;
	cin>>t;
	// cout<<t<<"\n";
	while(t--)
	{
		sum = 0;
		scanf("%lld %lld",&l, &r);
		func(l,r);
		// printf("%lld\n", sum);
	}
	return 0;
}