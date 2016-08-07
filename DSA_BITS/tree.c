#include <stdio.h>
#include <malloc.h>

typedef struct treenode treenode;
typedef treenode* NODEPTR;

struct treenode
{
	int data;
	NODEPTR parent;
	NODEPTR child;
	NODEPTR next;
};

NODEPTR newNode(int data)
{
	NODEPTR n = malloc(sizeof(treenode));
	n->data = data;
	n->parent = NULL;
	n->child = NULL;
	n->next = NULL;
	return n;
}

NODEPTR addChild(NODEPTR n, int data)
{
	NODEPTR x = newNode(data);
	n->child = x;
	x->parent = n;
	return x;
}

NODEPTR addNext(NODEPTR n, int data)
{
	NODEPTR x = newNode(data);
	n->next = x;
	x->parent = n->parent;
	return x;
}

int main()
{
	NODEPTR a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p;
	a = newNode('A');
	b = addChild(a,'B');
	f = addChild(b,'F');
	c = addNext(f,'C');
	g = addChild(f,'G');
	m = addChild(g,'M');
	h = addNext(m,'H');
	p = addChild(m,'P');
	n = addNext(p,'N');
	o = addChild(n,'O');
	i = addChild(c,'I');
	d = addNext(i,'D');
	e = addChild(d,'E');
	j = addChild(e,'J');
	k = addChild(j,'K');
	l = addChild(k,'L');

	if(a->parent == NULL)
		printf("cool");
}