/*this code is in order of occurence of frequencies*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define parent(i) i/2
#define left(i) 2*i
#define right(i) 2*i+1

typedef struct node node;
struct node{
	char ch;
	int freq;
	node* lchild;
	node* rchild;
	node* parent;
	int isleft;
	int pr;
};

typedef struct heap heap;
struct heap{
	node* arr[500];
	int length;
	int heap_size;
};

int count = 0, priority = 1;
void inorder(node* root);
void postorder(node* root);
node* get_node(char ch, int freq);
void min_heapify(heap* A, int i);
void build_min_heap(heap* A);
node* heap_extract_min(heap* A);
void heap_decrease_key(heap* A, int i, int key);
void min_heap_insert(heap* A, node* t);
void huff_code(node* n);

void print_node(node* n)
{
	printf("%c %d\n",n->ch, n->freq);
	return;
}

int main()
{
	freopen("input.txt","r",stdin);

	char str[500];
	scanf("%s",str);
	char visit[26];
	node* ptr[26];
	int i,l = strlen(str),j=1,k;

	for(i=0; i<26; i++)
		visit[i] = 0;

	/*for(i=0; i<l; i++)
		freq[str[i]-'A']++;*/

	heap min_queue;
	min_queue.length = 0;
	node *n1, *n2, *n;

	for(i=0; i<l; i++)
	{
		k = str[i]-'A';
		if(visit[k] == 0)
		{
			visit[k] = 1;
			ptr[k] = min_queue.arr[j++] = get_node(str[i], 1);//made changes here inplace of i use j for min_queue arr
			min_queue.length++;
		}
		else
		{
			ptr[k]->freq++;
		}
	}

	/*for(i=0; i<min_queue.length; i++)
		print_node(min_queue.arr[i+1]);
*/
	build_min_heap(&min_queue);

	/*for(i=0; i<min_queue.length; i++)
		print_node(min_queue.arr[i+1]);*/

	/*n1 = heap_extract_min(&min_queue);
		print_node(n1);
		n2 = heap_extract_min(&min_queue);
		print_node(n2);

		printf("ABCD\n");

	for(i=0; i<min_queue.heap_size; i++)
		print_node(min_queue.arr[i+1]);*/

	while(min_queue.heap_size >= 2)
	{
		n1 = heap_extract_min(&min_queue);
		print_node(n1);
		n2 = heap_extract_min(&min_queue);
		print_node(n2);
		n = get_node('0',0);
		n->freq = n1->freq + n2->freq;
		n->lchild = n1;
		n->rchild = n2;
		n1->isleft = 1;
		n2->isleft = 0;
		n1->parent = n2->parent = n;
		min_heap_insert(&min_queue,n);
	}

	printf("%d\n", count);
	n = heap_extract_min(&min_queue);
	postorder(n);
	printf("\n");
	inorder(n);
	printf("\n");
	for(i=0; i<l; i++)
	{
		huff_code(ptr[str[i]-'A']);
	}

		/*ENDDDDDDDDDDDDDDDDDD
	/*print_node(n);
	printf("\n");
	print_node(n->lchild);
	printf("\n");
	print_node(n->rchild);
	printf("\n");
	print_node(n->rchild->lchild);
	printf("\n");
	print_node(n->rchild->rchild);
	printf("\n");
	print_node(n->rchild->rchild->lchild);
	printf("\n");
	print_node(n->rchild->rchild->rchild);*/

	//Used for checking if Prority Queue is working fine
	/*while(min_queue.heap_size >= 1)
	{
		node* tmp = heap_extract_min(&min_queue);
		printf("%c-%d\n",tmp->ch, tmp->freq);
	}*/

	return 0;
}

node* get_node(char ch, int freq)
{
	count++;
	node* t = (node*)malloc(sizeof(node));
	t->ch = ch;
	t->pr = priority;
	priority++;
	t->freq = freq;
	t->lchild = t->rchild = t->parent = NULL;
	return t;
}

void min_heapify(heap* A, int i)
{
	int l = left(i);
	int r = right(i);
	int min = i;
	node* tmp;

	if( (l<= A->heap_size) && ( (A->arr[l]->freq < A->arr[i]->freq) || ((A->arr[l]->freq == A->arr[i]->freq) && (A->arr[l]->pr < A->arr[i]->pr)) ) )
		min = l;

	if( (r<= A->heap_size) && ( (A->arr[r]->freq < A->arr[min]->freq) || ((A->arr[r]->freq == A->arr[min]->freq) && (A->arr[r]->pr < A->arr[min]->pr)) ) )
		min = r;

	if(min != i)
	{
		tmp = A->arr[i];
		A->arr[i] = A->arr[min];
		A->arr[min] = tmp;
		// swap(&(A->arr[i]),&(A->arr[min]));
		min_heapify(A,min);
	}
	return;
}

void build_min_heap(heap* A)
{
	A->heap_size = A->length;
	int i, n = A->length;
	for(i=n/2; i>=1; i--)
	{
		min_heapify(A,i);
	}
	return;
}

node* heap_extract_min(heap* A)
{
	if(A->heap_size<1)
		return NULL;

	node* min = A->arr[1];
	A->arr[1] = A->arr[A->heap_size];
	A->heap_size--;
	min_heapify(A,1);
	return min;
}

void heap_decrease_key(heap* A, int i, int key)
{
	node* tmp;
	if(key > A->arr[i]->freq)
		return;
	A->arr[i]->freq = key;
	while(i>1 && A->arr[parent(i)]->freq > A->arr[i]->freq)
	{
		tmp = A->arr[parent(i)];
		A->arr[parent(i)] = A->arr[i];
		A->arr[i] = tmp;
		i = parent(i);
	}
	return;
}

void min_heap_insert(heap* A, node* t)
{
	// node* tmp = get_node(ch,INT_MAX);
	int key = t->freq;
	t->freq = INT_MAX;
	A->heap_size++;
	A->arr[A->heap_size] = t;
	heap_decrease_key(A,A->heap_size,key);
	return;
}

void postorder(node* root)
{
	if(root->lchild != NULL)
		postorder(root->lchild);
	if(root->rchild != NULL)
		postorder(root->rchild);
	printf("%c ", root->ch);

	return;
}

void inorder(node* root)
{
	if(root->lchild != NULL)
		inorder(root->lchild);
	printf("%c ", root->ch);
	if(root->rchild != NULL)
		inorder(root->rchild);
	return;
}

void huff_code(node* n)
{
	if(count==1)
	{
		printf("%d", 0);
		return;
	}
	int arr[50];
	int i=0,l=0;
	node* tmp = n;
	while(n->parent != NULL)
	{
		if(n->isleft)
			arr[i] = 0;
		else
			arr[i] = 1;
		i++;
		n = n->parent;
	}
	i--;
	for(;i>=0;i--)
	{
		printf("%d",arr[i]);
	}
}

/*void swap(node* a, node* b)
{
	node tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}*/