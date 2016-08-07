#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct NODE NODE;

typedef struct NODE
{
	int data;
	NODE* next;
}NODE;

NODE* getNode()
{
	return (NODE*)malloc(sizeof(NODE)); 
}

void addFront(NODE** list, int x)//pass pointer to list pointer because we want to change list pointer
{
	NODE* p = getNode();
	p->data = x;
	p->next = *list;
	*list = p;
}

void removeFront(NODE** list, int* x)
{
	NODE* p = *list;
	*x = p->data;
	*list = p->next;
	free(p);
}

void insertAfter(NODE** p, int x)
{
	NODE* q = getNode();
	q->data = x;
	q->next = (*p)->next;
	(*p)->next = q;
}

void deleteAfter(NODE** p, int* x)
{
	NODE* q = (*p)->next;
	(*p)->next = q->next;
	*x = q->data;
	free(q);
}

void traverse(NODE* list)
{
	NODE* p = list;
	while(p != NULL)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
}

int main(int argc, char **argv)
{
	int x;
	NODE* list = NULL;
	addFront(&list, 5);
	addFront(&list, 6);
	addFront(&list, 7);
	//printf("%d\t",list->data);
	//printf("%d\t",list->next->data);
	//printf("%d\n",list->next->next->data);
	traverse(list);
	printf("\n");
	removeFront(&list, &x);
	traverse(list);
	//printf("%d\n", x);
	//printf("%d\t",list->data);

}