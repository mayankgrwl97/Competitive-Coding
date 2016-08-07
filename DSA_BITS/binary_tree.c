#include <stdio.h>
#include <malloc.h>

typedef struct node node;

struct node
{
	int info;
	struct node* lchild;
	struct node* rchild;
	struct node* parent;
};

node* newNode(int data)
{
	node* ptr = (node*)malloc(sizeof(node));
	ptr->info = data;
	ptr->lchild = NULL;
	ptr->rchild = NULL;
	ptr->parent = NULL;
	return ptr;
}

void printInorder(node* p)
{
	if(p == NULL)
		return;
	printInorder(p->lchild);
	printf("%d ",p->info);
	printInorder(p->rchild);
	return;
}

int main()
{
	node* root = newNode(1);
	root->lchild = newNode(2);
	root->rchild = newNode(3);
	root->lchild->lchild = newNode(4);
	root->lchild->rchild = newNode(5);
	printInorder(root);
}