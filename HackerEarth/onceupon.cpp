#include <bits/stdc++.h>
#define LL long long int
using namespace std;

int main()
{
	freopen("input.txt","r",stdin);
	LL A[10000];
	int t,n,k;
	LL max;
	cin>>t;
	while(t--)
	{
		max = 0;
		scanf("%d %d", &n, &k);
		for(int i=0; i<n; i++)
		{
			scanf("%lld", A+i);
		}
		/*for(int i=0; i<n; i++)
		{
			printf("%d ", A[i]);	
		}
		printf("\n");*/
		for(int i=0; i<=k; i++)
		{
			if(max < A[i])
				max = A[i];
			else
				A[i] = max;
			// if(A[i] > ans)
			// 	ans = A[i];
		}
		for(int i=k+1; i<n; i++)
		{
			if(A[i]<=0)
			{
				A[i] = max;
			}
			else
			{
				if(A[i]+A[i-k-1] > max)
					A[i] = max = A[i] + A[i-k-1];
				else
					A[i] = max;
			}
			// if(A[i] > ans)
			// 	ans = A[i];
		}
		/*for(int i=0; i<n; i++)
		{
			printf("%d ", A[i]);	
		}*/

		printf("%lld\n", max);
	}
	return 0;
}

/*0   1   2   3   4   5    6   7   8    9   10  11   12  13  14   15  16  17   18 19  20   21
391 604 902 153 292 382  421 716 718  895 447 726  771 538 869  912 667 299  35 894 703  811 
391 604 902 153 292 1284 421 716 2002 895 447 2728 771 538 3597 912 667 3896 35 894 4599 811 

4599*/