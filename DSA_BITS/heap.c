#include <stdio.h>

typedef struct heap heap;

struct heap
{
	int arr[5000];
	int length;
	int heap_size;
};

int parent(int n);
int lchild(int n);
int rchild(int n);
void min_heapify(heap* A, int i);
void build_min_heap(heap* A);


int main()
{
	freopen("input.txt","r",stdin);
	heap A;

	scanf("%d",&(A.length));

	int n = A.length;

	for (int i=1; i<=n; i++)
		scanf("%d",A.arr + i);
	
	build_min_heap(&A);
	
	for (int i=1; i<=n; i++)
		printf("%d ",A.arr[i]);

	return 0;
}

int parent(int n)
{
	return n/2;
}

int lchild(int n)
{
	return 2*n;
}

int rchild(int n)
{
	return 2*n+1;
}

void min_heapify(heap* A, int i)
{
	int l = lchild(i);
	int r = rchild(i);
	int min,tmp;

	if(l<= A->heap_size && A->arr[l] < A->arr[i])
		min = l;
	else
		min = i;

	if(r<= A->heap_size && A->arr[r] < A->arr[min])
		min = r;

	if(min != i)
	{
		tmp = A->arr[i];
		A->arr[i] = A->arr[min];
		A->arr[min] = tmp;
		min_heapify(A, min);
	}
	return;
}

void build_min_heap(heap* A)
{
	A->heap_size = A->length;
	int i,n = A->length;
	for(i=n/2; i>=1; i--)
	{
		min_heapify(A,i);
	}
}