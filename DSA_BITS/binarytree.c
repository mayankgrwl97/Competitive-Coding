/*Binary Tree representation and traversal*/

#include <stdio.h>
#include <malloc.h>

typedef struct node node;

struct node{
	int data;
	node* lchild;
	node* rchild;
	node* parent;
};

node* newNode(int data)
{
	node* n = (node*)malloc(sizeof(node));
	n->data = data;
	n->lchild = NULL;
	n->rchild = NULL;
	n->parent = NULL;
	return n;
}

node* addLchild(node* a, int data)
{
	a->lchild = newNode(data);
	a->lchild->parent = a;
	return a->lchild;
}

node* addRchild(node* a, int data)
{
	a->rchild = newNode(data);
	a->rchild->parent = a;
	return a->rchild;
}

void preorder(node* root)
{
	if(root != NULL)
		printf("%c ",root->data);
	
	if(root->lchild != NULL)
		preorder(root->lchild);
	
	if(root->rchild != NULL)
		preorder(root->rchild);

	return;
}

void postorder(node* root)
{
	if(root->lchild != NULL)
		postorder(root->lchild);
	if(root->rchild != NULL)
		postorder(root->rchild);
	printf("%c ", root->data);

	return;
}

void inorder(node* root)
{
	if(root->lchild != NULL)
		inorder(root->lchild);
	printf("%c ", root->data);
	if(root->rchild != NULL)
		inorder(root->rchild);
	return;
}

int main()
{
	node* root = newNode('A');
	addLchild(root,'B');
	addRchild(root,'C');
	addLchild(root->lchild,'D');
	addLchild(root->rchild,'E');
	addRchild(root->rchild,'F');
}