#include <stdio.h>
#include <malloc.h>

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int** arr;

	arr = (int**)malloc((n+1)*sizeof(int*));

	for (int i=0; i<=n; i++)
	{
		arr[i] = (int*)malloc((i+1)*sizeof(int));
	}

	arr[0][0] = 1;

	for(int i=1; i<=n; i++)
	{
		arr[i][0] = 1; arr[i][i] = 1;

		for(int j=1; j<i; j++)
		{
			arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
		}
	}

	for(int i=0; i<=n; i++)
	{
		for(int j=0; j<n-i; j++)
			printf(" ");
		for(int j=0; j<=i; j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}

}