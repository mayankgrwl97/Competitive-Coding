#include <stdio.h>
#include <malloc.h>

#define max 50

int I[max],R[max],C[max],P[max];

typedef struct node node;

struct node
{
	int i,r,c,p;
	node *lchild,*rchild,*parent;
};

node* T = NULL;

node* getNode(int i, int r, int c, int p);
void tree_insert(node* z);
node* tree_maximum(node* x);
node* tree_minimum(node* x);
void transplant(node* u, node* v);
node* tree_delete();
void print(node* c);
int priority(node* n);
void func(int n);

int main()
{
	freopen("2.in","r",stdin);
	// freopen("res.txt","w",stdout);
	int i;
	for(i=0; i<max; i++)
	{
		int t = scanf("%d %d %d %d", I+i,R+i,C+i,P+i);
		if(t == EOF)
			break;
		// printf("%d %d %d %d\n", I[i], R[i], C[i], P[i]);
	}

	// printf("%d\n", i);

	func(i);

	return 0;
}

node* getNode(int i, int r, int c, int p)
{
	node* n = (node*)malloc(sizeof(node));
	n->i = i;	n->r = r;	n->c = c;	n->p = p;
	n->lchild = n->rchild = n->parent = NULL;
}

void tree_insert(node* z)
{
	node* y = NULL;
	node* x = T;
	while(x != NULL)
	{
		y = x;
		if((z->p) < (x->p))
			x = x->lchild;
		else
			x = x->rchild;
	}

	z->parent = y;
	if(y == NULL)
		T=z;
	else
	{
		if((z->p) < (y->p))
			y->lchild = z;
		else
			y->rchild = z;
	}
	return;
}

node* tree_maximum(node* x)
{
	while(x->rchild != NULL)
		x = x->rchild;
	return x;
}

node* tree_minimum(node* x)
{
	while(x->lchild != NULL)
		x = x->lchild;
	return x;
}

void transplant(node* u, node* v)
{
	if(u->parent == NULL)
		T = v;
	else
	{
		if(u == u->parent->lchild)
			u->parent->lchild = v;
		else
			u->parent->rchild = v;
	}
	if(v != NULL)
		v->parent = u->parent;
	return;
}

node* tree_delete()
{
	node* z = tree_maximum(T);

	if(z->lchild == NULL)
		transplant(z,z->rchild);
	else if(z->rchild == NULL)
		transplant(z,z->lchild);
	else
	{
		node* y = tree_minimum(z->rchild);
		if(y->parent != z)
		{
			transplant(y,y->rchild);
			y->rchild = z->rchild;
			y->rchild->parent = y;
		}
		transplant(z,y);
		y->lchild = z->lchild;
		y->lchild->parent = y;
	}

	z->lchild = z->rchild = z->parent = NULL;

	return z;
}

void print(node* c)
{
	if(c == NULL)
		printf("%d\n", 0);
	else
		printf("%d\n", c->i);
}

int priority(node* n)
{
	if(n==NULL)
		return -1;
	else
		return n->p;
}

void func(int n)
{
	int i=0,t=0;
	node *z, *current = NULL;
	while(i != n)
	{
		while(R[i] <= t && i<n)
		{
			z = getNode(I[i],R[i],C[i],P[i]);
			if((priority(z) > priority(current)) && current != NULL)
			{
				tree_insert(z);
				tree_insert(current);
				current = NULL;
			}
			else
			{
				tree_insert(z);
			}
			i++;
		}

		// if(T!=NULL && current!=NULL && (current->c) > 0)
		// 	current = tree_delete();
		if(current!= NULL && (current->c) > 0)
		{	
			// print(current);
			(current->c)--;
		}
		else if(T != NULL)
		{
			current = tree_delete();
			// printf("Hello" );
			// printf("%d ",current->i);
			// print(current);
			(current->c)--;
		}
		print(current);
		t++;
	}

	if(current != NULL)
	{
		while((current->c) > 0)
		{
			print(current);
			(current->c)--;
		}
	}	
		
	while(T != NULL)
	{
		current = tree_delete();
		while((current->c) > 0)
		{
			print(current);
			(current->c)--;
		}
	}
	return;
}