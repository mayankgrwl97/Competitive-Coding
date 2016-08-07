/*NORMAL BST INSERTION WITH HEIGHT UPADTION*/
#include <stdio.h>
#include <malloc.h>
#include <string.h>

typedef struct node node;

struct node
{
	char str[50];
	node* left;
	node* right;
	node* parent;
	int height;
};

node* root = NULL;
node* new_node(char str[]);
node* insert(node* z);
void set_height(node* tmp);
void preorder(node* n);
int max(int a, int b);
void print_node(node* z);

int main()
{
	freopen("input.txt","r",stdin);
	char str[50];
	int i = 0;
	node* z;
	for(i=0; i<50; i++)
	{
		int t = scanf("%s",str);
		if(t == EOF)
			break;
		z = new_node(str);
		insert(z);
	}
	preorder(root);
	// print_node(root);
	// print_node(root->left);
	// print_node(root->right);
	// print_node(root->right->left);
	// print_node(root->right->right);
	// print_node(root->right->right->left);
	// print_node(root->right->right->right);
	// printf("%d\n", );
	
	return 0;
}

void print_node(node* z)
{
	if(z == NULL)
	{
		// printf("NULL\n" );
		return;
	}
		
	/*printf("node:%s\n", z->str);
	if(z->parent == NULL)
		printf("parent: NULL\n");
	else
		printf("parent: %s\n", z->parent->str);
	if(z->left == NULL)
		printf("left: NULL\n");
	else
		printf("left: %s\n", z->left->str);
	if(z->right == NULL)
		printf("right: NULL\n");
	else
		printf("right: %s\n", z->right->str);
	printf("\n");*/
	printf("%s %d\n",z->str, z->height);
	return;
}

node* new_node(char str[])
{
	node* n = malloc(sizeof(node));
	strcpy(n->str,str);
	n->left = n->right = n->parent = NULL;
	n->height = 1;
	return n;
}

node* insert(node* z)
{
	node* y = NULL;
	node* x = root;
	while(x != NULL)
	{
		y = x;
		if(strcmp(z->str,x->str) < 0)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}

	z->parent = y;

	if(y == NULL)
	{
		root = z;
	}
	else
	{
		if(strcmp(z->str,y->str)<0)
		{
			y->left = z;
		}
		else
		{
			y->right = z;
		}
	}

	while(y!= NULL)
	{
		set_height(y);
		y = y->parent;
	}
	// print_node(z);
	// print_node(z->parent);
	return root;
}

void set_height(node* tmp)
{
	if(tmp->left == NULL && tmp->right == NULL)
		tmp->height = 1;
	else if(tmp->left == NULL)
	{
		tmp->height = 1 + tmp->right->height;
	}
	else if(tmp->right == NULL)
	{
		tmp->height = 1 + tmp->left->height;
	}
	else
	{
		tmp->height = 1 + max(tmp->right->height, tmp->left->height);
	}
	return;
}

void preorder(node* n)
{
	if(n == NULL)
		return;
	print_node(n);
	preorder(n->left);
	preorder(n->right);
	return;
}

int max(int a, int b)
{
	return (a>b ? a : b);
}

/*
AUG 
APR 
JAN 
DEC 
JUL 
FEB 
JUN 
OCT 
SEP  */