#include <bits/stdc++.h>
using namespace std;

bool a[100000009];//a[i] = 0 for prime and even nos.(!=2); a[i] = 1 for not prime 
int p[5800009];

void sieve()//p is the array which stores the primes from p[1] to p[5761455]
{
	long long k=1;

	a[0]=1; a[1]=1; p[1]=2;

	for (long long i=3; i<100000006; i=i+2)
	{
		if(a[i] == 0)
		{
			p[++k] = i;
			for(long long j=i*i; j<=100000006; j=j+2*i)
				a[j]=1;
		}
	}
}


int main()
{
	
	return 0;
}