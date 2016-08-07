#include <stdio.h>
#include <malloc.h>

int main(int argc, char **argv)
{
	freopen("input.txt","r",stdin);

	int *arr,n,j=0,k;
	void *p;
	arr = (int*)malloc(5*sizeof(int));

	while(1)
	{
		for (int i = 0; i < 5; ++i)
		{
			//printf("\narr[%d] = ",j);
			scanf("%d",arr+j);
			j++;
		}

		//printf("\nEnter 0 to exit 1 to continue");
		scanf("%d",&k);

		if(k==1)
		{
			arr = (int*)realloc(arr, (j+5)*sizeof(int));
		}
		else
		{
			break;
		}
	}

	for (int i = 0; i < j; ++i)
	{
		printf("arr[%d] = %d\n",i,arr[i]);
	}
	printf("\n");

	return 0;
}