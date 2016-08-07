#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>

typedef struct node node;
typedef struct queue queue;
typedef struct stack stack;

int ct = 0;

struct node{
	int n1, n2, prod;
	node *a,*b,*c;
	int isleft;
	node* parent;
};

struct queue
{
	node* q[5000];
	int start;
	int end;
};

struct stack
{
	node* s[5000];
	int start;
};

int max(int a, int b);
node* getnode(int n1, int n2);
void karatsuba(int n1, int n2);
int length(int n);
queue* newQueue();
void queue_push(node* p, queue* Q);
node* queue_pop(queue* Q);
int is_queue_empty(queue* Q);
stack* newStack();
void stack_push(node* p, stack* S);
node* stack_pop(stack* S);
int is_stack_empty(stack* S);

int main()
{
	freopen("input.txt","r",stdin);
	int n1,n2;
	scanf("%dX%d",&n1,&n2);
	// printf("%d %d\n", n1,n2);
	karatsuba(n1,n2);
	return 0;
}

int max(int a, int b)
{
	return (a>b ? a : b);
}

node* getnode(int n1, int n2)
{
	// printf("%d %d %d\n",ct++,n1,n2);
	node* n = (node*)malloc(sizeof(node));
	n->n1 = n1;
	n->n2 = n2;
	n->prod = 1111;
	n->a = n->b = n->c = n->parent = NULL;
	n->isleft = 0;
	return n;
}

int isleaf(node* n)
{
	if(length(n->n1) == 1 && length(n->n2) == 1)
		return 1;
	return 0;
}

void karatsuba(int n1, int n2)
{	
	queue* Q = newQueue();
	stack* S = newStack();
	node* n = getnode(n1,n2);
	queue_push(n,Q);
	// printf("%d\n", Q->end);
	
	while(!is_queue_empty(Q))
	{
		n = queue_pop(Q);
		if(isleaf(n))
		{
			stack_push(n,S);
		}
		else
		{
			int h1,h2,l1,l2,tmp,len1,len2;
			len1 = length(n->n1);
			len2 = length(n->n2);
			if(l1>l2)
			{
				tmp = (int)pow(10,(len1/2));
				h1 = (n->n1)/tmp;	l1 = (n->n1)%tmp;
				h2 = (n->n2)/tmp;	l2 = (n->n2)%tmp;
			}
			else
			{
				tmp = (int)pow(10,(len2/2));
				h1 = (n->n1)/tmp;	l1 = (n->n1)%tmp;
				h2 = (n->n2)/tmp;	l2 = (n->n2)%tmp;
			}
			n->a = getnode(l1+h1,l2+h2);
			n->b = getnode(h1,h2);
			n->c = getnode(l1,l2);
			n->a->parent = n->b->parent = n->c->parent = n;
			n->a->isleft = 1;
			queue_push(n->a,Q);
			queue_push(n->b,Q);
			queue_push(n->c,Q);
		}
	}
	
	if(is_queue_empty(Q))
	{
		Q->start = Q->end = 0;
	}

	while(!is_stack_empty(S))
	{
		queue_push(stack_pop(S),Q);
	}

	while(!is_queue_empty(Q))
	{
		n = queue_pop(Q);
		if(n->isleft == 1)
			queue_push(n->parent,Q);
		if(isleaf(n))
		{
			n->prod = (n->n1)*(n->n2);
			printf("%dX%d=%d\n", n->n1,n->n2,n->prod);
		}
		else
		{
			int l1 = length(n->n1), l2 = length(n->n2);
			int tmp = pow(10,max(l1,l2)/2);
			n->prod = (n->b->prod)*tmp*tmp + ((n->a->prod)-(n->b->prod)-(n->c->prod))*tmp + n->c->prod;
			printf("%dX%d=%dX%dX%d+(%d-%d-%d)X%d+%d=%d\n",n->n1,n->n2,n->b->prod,tmp,tmp,n->a->prod,n->b->prod,n->c->prod,tmp,n->c->prod,n->prod);
		}
	}
	return;
}

int length(int n)
{
	if(n==0)
		return 1;
	int l = 0;
	while(n>0)
	{
		n /= 10;
		l++;
	}
	return l;
}


/*QUEUE*/
queue* newQueue()
{
	queue* q = (queue*)malloc(sizeof(queue));
	q->start = 0;
	q->end = 0;
	return q;
}

void queue_push(node* p, queue* Q)
{
	(Q->q[Q->end]) = p;
	(Q->end)++;
	return;
}

node* queue_pop(queue* Q)
{
	node* tmp;
	tmp = (Q->q[Q->start]);
	(Q->start)++;
	return tmp;
}

int is_queue_empty(queue* Q)
{
	if(Q->start == Q->end)
		return 1;
	return 0;
}
/*End of QUEUE*/

/*STACK*/
stack* newStack()
{
	stack* s = (stack*)malloc(sizeof(stack));
	s->start = 0;
	return s;
}

void stack_push(node* p, stack* S)
{
	S->s[S->start] = p;
	S->start++;
	return;
}

node* stack_pop(stack* S)
{
	node* tmp;
	tmp = S->s[S->start-1];
	S->start--;
	return tmp;
}

int is_stack_empty(stack* S)
{
	if(S->start == 0)
		return 1;
	return 0;
}
/*End of STACK*/

