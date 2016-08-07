/*inorder and preorder traversal to binary tree*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>

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
		postorder(root->lchild);
	printf("%c ", root->data);
	if(root->rchild != NULL)
		postorder(root->rchild);
	return;
}

node* func(char in[], char pre[])
{
	int l, it;
	l = strlen(in);

	node* root = newNode(pre[0]);
	for(int i=0; i<l; i++)
	{
		if(in[i] == pre[0])
		{
			it = i;
			break;
		}
	}

	char tmpin[it];
	char tmppre[it];

	for (int i=0; i<it; i++)
	{
		tmpin[i] = in[i];
		tmppre[i] = pre[i+1];
	}

	root->lchild = func(tmpin,tmppre);
	root->lchild->parent = root;
	root->rchild = func(in+it+1,pre+it+1);
	root->rchild->parent = root;

	return root;
}

int main()
{
	/*node* root = newNode('A');
	addLchild(root,'B');
	addRchild(root,'C');
	addLchild(root->lchild,'D');
	addLchild(root->rchild,'E');
	addRchild(root->rchild,'F');
	*/

	char in[100];
	char pre[100];
	scanf("%s",in);
	scanf("%s",pre);
	func(in,pre);
}