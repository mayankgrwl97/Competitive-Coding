#include <stdio.h>
#include <malloc.h>

int main(int argc, char **argv)
{
	int **array,r,c;

	printf("#Rows: ");
	scanf("%d",&r);
	printf("#Columns: ");
	scanf("%d",&c);

	array = (int**)malloc(r*sizeof(int*));

	for (int i = 0; i < r; ++i)
	{
		array[i] = (int*)malloc(c*sizeof(int));
	}

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			printf("\narray[%d][%d] = ",i,j);
			scanf("%d",&array[i][j]);
		}
	}

	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			printf("%d\n",array[i][j]);
		}
	}
	printf("\n");

	return 0;
}