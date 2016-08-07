#include <stdio.h>
#define scan(n) scanf("%d",&n)

void counting_sort(int A[], int B[], int k, int n)
{
	int i,C[k+1];  // C[0..k]

	for(i=0; i<=k; i++)
		C[i] = 0;

	for(i=0; i<n; i++)
		C[A[i]]++;

	for(i=1; i<=k; i++)
		C[i] = C[i] + C[i-1];

	for(i=n-1; i>=0; i--)
	{
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
}

int main()
{
	int n,i,k = 0;
	scan(n);
	int A[n], B[n];

	for(i=0; i<n; i++)
	{
		scan(A[i]);
		if(k<A[i])
			k = A[i];
	}

	counting_sort(A,B,k,n);

	for(i=0; i<n; i++)
		printf("%d\n", B[i]);	

	return 0;
}