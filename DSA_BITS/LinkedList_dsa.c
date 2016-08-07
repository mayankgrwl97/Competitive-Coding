#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
	int info;
	struct node* next;
};

typedef struct node* NODEPTR;

NODEPTR getnode()
{
	NODEPTR p;
	p = (NODEPTR)malloc(sizeof(struct node));
	return p;
}

void freenode(NODEPTR p)
{
	free(p);
}

void addFront(NODEPTR *plist, int x)
{
	NODEPTR p;

	p = getnode();
	p->info = x;
	p->next = *plist;
	*plist = p;
}

void removeFront(NODEPTR *plist, int *px)
{
	NODEPTR p;

	if(*plist == NULL)
		exit(1);

	p = *plist;
	*plist = p->next;
	*px = p->info;
	freenode(p);
}

int main()
{

}