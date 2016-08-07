#include <stdio.h>
#include <malloc.h>
#include <string.h>	
#include <ctype.h>
#include <math.h>

typedef struct tnode tnode;
typedef struct queue queue;

struct tnode
{
	int data;
	char orand;
	tnode* lchild;
	tnode* rchild;
	tnode* parent;
};

struct queue
{
	tnode* q[5000];
	int start;
	int end;
};

char reverse(char a);//
int comp(int a);//
int max(int a, int b);//
int min(int a, int b);//
tnode* getNode(int data, char orand);//
queue* newQueue();//
void push(tnode* p, queue* Q);//
tnode* pop(queue* Q);//
int isEmpty(queue* Q);//
void populate(int val[], int n, int s);//
int size(char str[]);//
int evaluate(char str[], int n, int s);
tnode* generateTree(int s, char str[]);
void preorder(tnode* root);

int main()
{
	char str[500];
	scanf("%s",str);
	int s = size(str);

	preorder(generateTree(s,str));
	return 0;
}

char reverse(char a)
{
	return (a=='o' ? 'a' : 'o');
}

int comp(int a)
{
	return (a==1 ? 0 : 1);
}

int max(int a, int b)
{
	return (a>b ? a : b);
}

int min(int a, int b)
{
	return (a<b ? a : b);
}

tnode* getNode(int data, char orand)
{
	tnode* n = (tnode*)malloc(sizeof(tnode));
	n->data = data;
	n->orand = orand;
	n->lchild = NULL;
	n->rchild = NULL;
	n->parent = NULL;
	return n;
}

queue* newQueue()
{
	queue* q = (queue*)malloc(sizeof(queue));
	q->start = 0;
	q->end = 0;
	return q;
}

void push(tnode* p, queue* Q)
{
	(Q->q[Q->end]) = p;
	(Q->end)++;
}

tnode* pop(queue* Q)
{
	tnode* tmp;
	tmp = (Q->q[Q->start]);
	(Q->start)++;
	return tmp;
}

int isEmpty(queue* Q)
{
	if(Q->start == Q->end)
		return 1;
	return 0;
}
	
void populate(int val[], int n, int s)
{
	int i = s-1;
	while(n>0)
	{
		val[i] = n%2;
		n = n/2;
		i--;
	}
	while(i>=0)
	{
		val[i] = 0;
		i--;
	}
	return;
}

int size(char str[])
{
	int l = strlen(str);
	int n = 'A', i;
	for (i=0; i<l; i++)
	{
		if(isalnum(str[i]) && str[i]>n)
			n = str[i];
	}
	return n-'A'+1;
}

int evaluate(char str[], int n, int s)
{
	int val[26];
	int i=0;
	int a=1,b;
	int l = strlen(str);
	populate(val,n,s);
	while(1)
	{
		if(i == l)
			break;
		else if(str[i] == '(')
		{
			i++;
			b = 0;
			while(str[i]!=')')
			{
				if(str[i] == '-')
				{
					i++;
					val[str[i]-'A'] = comp(val[str[i]-'A']);
				}
				else if(str[i] == '+')
					i++;
				else
				{
					b = max(b,val[str[i]-'A']);
					i++;
				}
			}
			a = min(a,b);
			// printf("b = %d\n", b);
			i++;
		}
		else if(str[i] == '*')
		{
			i++;
		}
	}
	return a;
}

tnode* generateTree(int s, char str[])
{
	tnode* root = getNode(0,'o');
	tnode* tmp;
	queue* q = newQueue();
	push(root, q);
	
	int i,t = pow(2,s)-1;

	for (i=0; i<t; i++)
	{
		tmp = pop(q);
		int a = tmp->data;
		char b = reverse(tmp->orand);
		tmp->lchild = getNode(2*a+1,b);
		tmp->lchild->parent = tmp;
		push(tmp->lchild, q);
		tmp->rchild = getNode(2*a+2,b);
		tmp->rchild->parent = tmp;
		push(tmp->rchild, q);
	}

	/*------NOW EVALUATING All NODES-------*/

	t++;
	int j=0;
	for (i=0; i<t; i++)
	{
		tmp = pop(q);
		if((tmp->data)%2 != 0)
		{
			tmp->data = evaluate(str,j,s);
			// printf("--%d",tmp->data);
			j++;	
		}
		else
		{
			tmp->data = evaluate(str,j,s);
			// printf("--%d",tmp->data);
			j++;
			push(tmp->parent, q);
		}
	}

	while(!isEmpty(q))
	{
		tmp = pop(q);
		if((tmp->data)%2 != 0 || tmp->data == 0)
		{
			if(tmp->orand == 'o')
				tmp->data = max(tmp->lchild->data, tmp->rchild->data);
			else
				tmp->data = min(tmp->lchild->data, tmp->rchild->data);
		}
		else
		{
			if(tmp->orand == 'o')
				tmp->data = max(tmp->lchild->data, tmp->rchild->data);
			else
				tmp->data = min(tmp->lchild->data, tmp->rchild->data);

			push(tmp->parent, q);
		}
			
	}
	return root;
}

void preorder(tnode* root)
{
	if(root != NULL)
		printf("%d",root->data);
	
	if(root->lchild != NULL)
		preorder(root->lchild);
	
	if(root->rchild != NULL)
		preorder(root->rchild);

	return;
}