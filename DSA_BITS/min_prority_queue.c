#include <stdio.h>
#include <limits.h>

#define parent(i) i/2
#define left(i) 2*i
#define right(i) 2*i+1

typedef struct heap heap;

struct heap
{
	int arr[5000];
	int length;
	int heap_size;
};

void min_heapify(heap* A, int i);
void build_min_heap(heap* A);
int heap_min(heap A);
int heap_extract_min(heap* A);
void heap_decrease_key(heap* A, int i, int key);
void min_heap_insert(heap* A, int key);

int main(int argc, char const *argv[])
{
	
	return 0;
}

void min_heapify(heap* A, int i)
{
	int l = left(i);
	int r = right(i);
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

int heap_min(heap A)
{
	return A.arr[1];
}

int heap_extract_min(heap* A)
{
	if(A->heap_size<1)
		return INT_MAX;

	int min = A->arr[1];
	A->arr[1] = A->arr[A->heap_size];
	A->heap_size--;
	min_heapify(A,1);
	return min;
}

void heap_decrease_key(heap* A, int i, int key)
{
	int tmp;
	if(key > A->arr[i])
		printf("New key is larger than current key");
	A->arr[i] = key;
	while(i>1 && A->arr[parent(i)] > A->arr[i])
	{
		tmp = A->arr[i];
		A->arr[i] = A->arr[parent(i)];
		A->arr[parent(i)] = tmp;
		i = parent(i);
	}
	return;
}

void min_heap_insert(heap* A, int key)
{
	A->heap_size++;
	A->arr[A->heap_size] = INT_MAX;
	heap_decrease_key(A,A->heap_size,key);
	return;
}