#include <bits/stdc++.h>
using namespace std;

bool a[10010];//a[i] = 0 for prime and even nos.(!=2); a[i] = 1 for not prime 
int p[5800009];
int arr[1000][1000];
int ispossible[1000][1000];

void sieve()//p is the array which stores the primes from p[1] to p[5761455]
{
	long long k=1;

	a[0]=1; a[1]=1; p[1]=2;

	for (long long i=3; i<10010; i=i+2)
	{
		if(a[i] == 0)
		{
			p[++k] = i;
			for(long long j=i*i; j<=10010; j=j+2*i)
				a[j]=1;
		}
	}
}

bool isprime(int t)
{
	if(t>10000)
		return 0;
	if(t == 2)
		return 1;
	else if(t%2)
		return !a[t];
	return 0;
}

void util(int n, int k)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(!isprime(arr[i][j]))
			{
				if(!isprime(arr[i][j] + k))
					ispossible[i][j] = -1;
				else
					ispossible[i][j] = 1;
			}
			else
			{
				ispossible[i][j] = 0;
			}
		}
	}
	return;
}

void func(int n, int k)
{
	int row,col;
	int min = INT_MAX;	
	int tmp;
	for(int i=1; i<n-1; i++)
	{
		for(int j=1; j<n-1; j++)
		{
			tmp = util(i,j,k);
			if(tmp != -1)
			{
				if(min>tmp)
				{
					min = tmp;
					row = i;
					col = j;
				}
			}
		}
	}

	if(min != INT_MAX)
	{
		cout<<"yes\n";
		cout<<min;
		cout<<'\n'<<row+1<<' '<<col+1;
	}
	else
		cout<<"no";
	return;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	sieve();

	int n,k;
	cin>>n>>k;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cin>>arr[i][j];
		}
	}

	func(n,k);
	// cout<<isprime(11);
	// cout<<util(1,1,1);
	return 0;
}