#include <stdio.h>
#include <malloc.h>

typedef struct NODE NODE;

struct NODE
{
	int info;
	NODE* next;
};

void addFront(NODE** head, int data)
{
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->next = *head;
	p->info = data;
	*head = p;
	return;
}

void addEnd(NODE **head, int data)
{
	NODE* p = (NODE*)malloc(sizeof(NODE));
	p->info = data;
	
	if(*head == NULL)
	{
		*head = p;
		p->next = NULL;
	}
	else
	{
		NODE* pt = *head;
		while(pt->next != NULL)
		{
			pt = pt->next;
		}
		pt->next = p;
		p->next = NULL;	
	}
	return;
}

void addAfter(NODE* p, int data)
{
	NODE* q = (NODE*)malloc(sizeof(NODE));
	q->data = x;
	q->next = p->next;
	p->next = q;
	return;
}

void removeFront(NODE** head)
{
	if(*head == NULL)
		return;
	else
	{
		NODE* p = *head;
		*head = p->next;
		printf("%d\n",p->info);
		free(p);
	}
	return;
}

void removeAfter(NODE* p)
{
	if(p->next->next == NULL)
	{
		printf("%d\n",p->next->data);
		NODE* tmp = p->next;
		p->next = p->next->next;
		free(tmp);
	}
	else
	{
		printf("%d\n",p->next->data );
		free(p->next);
		p->next = NULL;
	}
}

void removeEnd(NODE** head)
{
	if(*head == NULL)
		return;
	else if((*head)->next == NULL)
	{
		printf("%d\n",(*head)->info);
		free(*head);
		*head = NULL;
	}
	else
	{
		NODE* pt = *head;
		while(pt->next->next != NULL)
		{
			pt = pt->next;
		}
		printf("%d\n",pt->next->info);
		free(pt->next);
		pt->next = NULL;
	}
	return;
}

void traverse(NODE* head)
{
	if(head == NULL)
		return;
	else
	{
		while(head != NULL)
		{
			printf("%d\t",head->info);
			head = head->next;
		}
		printf("\n");
	}
	return;
}

int main()
{
	NODE* head = NULL;
	int n,m;
	scanf("%d",&n);
	while(n!=-1)
	{
		if(n==0)
		{
			scanf("%d",&m);
			addFront(&head, m);
			traverse(head);
		}
		else if(n==1)
		{
			scanf("%d",&m);
			addEnd(&head, m);
			traverse(head);
		}
		else if(n==2)
		{
			removeFront(&head);	
		}
		else if(n==3)
		{
			removeEnd(&head);	
		}
		else
		{
			traverse(head);
		}
		scanf("%d",&n);
	}
	return 0;		
}