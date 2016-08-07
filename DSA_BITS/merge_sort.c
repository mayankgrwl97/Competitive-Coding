#include <stdio.h>

void merge_sort(int arr[], int aux[], int lo, int hi)
{
	if(lo == hi)
		return;
	int mid = (lo+hi)/2;
	merge_sort(arr,aux,lo,mid);
	merge_sort(arr,aux,mid+1,hi);
	for(int i=lo; i<=hi; i++)
		aux[i] = arr[i];
	int i = lo, j = mid+1;
	for(int k=lo; k<=hi; k++)
	{
		if(i>mid)
			arr[k] = aux[j++];
		else if(j>hi)
			arr[k] = aux[i++];
		else if(aux[j]<aux[i])
			arr[k] = aux[j++];
		else
			arr[k] = aux[i++];
	}
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	int n;
	scanf("%d",&n);

	int arr[n],aux[n];

	for (int i=0; i<n; i++)
		scanf("%d",arr+i);

	merge_sort(arr,aux,0,n-1);
	for (int i=0; i<n; i++)
	{
		printf("%d ",arr[i]);	
	}

	return 0;
}