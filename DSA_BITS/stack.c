#include <stdio.h>
#include <malloc.h>

typedef struct NODE NODE;

struct NODE
{
	int data;
	NODE* next;
};

NODE* newStack()
{
	NODE* ptr = NULL;
	return ptr;
}

NODE* getNode()
{
	NODE* ptr = (NODE*)malloc(sizeof(NODE));
	return ptr;
}

void push(int data, NODE** ptr)
{
	NODE* p = getNode();
	p->data = data;
	p->next = *ptr;
	*ptr = p;
}

int top(NODE* ptr)
{
	if(ptr == NULL)
		return 0;
	else
		return ptr->data;
}

int pop(NODE** ptr)
{
	if(*ptr == NULL)
		return 0;
	else
	{
		int tmp = (*ptr)->data;
		*ptr = (*ptr)->next;
		return tmp;
	}
}

int isEmpty(NODE* ptr)
{
	if(ptr == NULL)
		return 1;
	else
		return 0;
}

int main()
{
	NODE* st = newStack();

	pop(&st);
}