#include <bits/stdc++.h>
#define MAX_SIZE 1000100
using namespace std;

bool marked[MAX_SIZE]; //primes and even nos. are not marked so they store the value 0 and others store the value 1
int primes[80000]; //78504 primes

int sieve()
{
	int count = 0;
	int n = MAX_SIZE;
	int sq = (int)sqrt(n);
	sq+=2;
	for(int i=3; i<=sq; i+=2)
		if(!marked[i])
			for(int j=i*i; j<=n; j+=2*i)
				marked[j] = true;

	primes[1] = 2;
	int t=2;
	for(int i=3; i<=n; i+=2)	
		if(!marked[i])
			primes[t++] = i;
	return t-1;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
	#endif

	sieve();
	return 0;
}