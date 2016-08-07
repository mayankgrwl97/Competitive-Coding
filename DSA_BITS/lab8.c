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
int balance(node* z);
node* new_node(char str[]);
node* insert(node* z);
void set_height(node* tmp);
void preorder(node* n);
int max(int a, int b);
void print_node(node* z);
void avl_insert(node* z);
node* rotate_right(node* z);
node* rotate_left(node* z);


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
		avl_insert(z);
	}
	preorder(root);
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
	return z;
}

void avl_insert(node* z)
{
	z = insert(z);
	z = z->parent;
	while(z != NULL)
	{
		if(balance_factor(z)>1)
		{
			if(balance_factor(z->left) >= 0)
			{
				z = rotate_right(z);
			}
			else
			{
				z->left = rotate_left(z->left);
				// z->left->parent = z;
				rotate_right(z);

			}
				// LR
			break;
		}
		else if(balance_factor(z)<-1)
		{
			if(balance_factor(z->right) <= 0)
				rotate_left(z);
			else
			{
				z->right = rotate_right(z->right);
				rotate_left(z);
			}
			break;
		}
	}
	return;
}

int height(node* z)
{
	if(z == NULL)
		return 0;
	else
		return z->height;
}

/*node* balance(node* z)
{
	if(balance_factor(z)>1)
	{
		if(balance_factor(z->left) >= 0)
			// LL
		else
			// LR
	}
	else if(balance_factor(z)<-1)
	{
		if(balance_factor(z->right) <= 0)
			// RR
		else
			// RL
	}
	else
	{
		return;
	}
}
*/
node* rotate_right(node* z)
{
	if(z == NULL)
		return NULL;

	node* new_root = z->left;
	new_root->parent = z->parent;

	z->left = new_root->right;
	if(new_root->right != NULL)
		new_root->right->parent = z;

	new_root->right = z;
	z->parent = new_root;
	set_height(z);
	set_height(new_root);
	return new_root;
}

node* rotate_left(node* z)
{
	if(z == NULL)
		return NULL;

	node* new_root = z->right;
	new_root->parent = z->parent;

	z->right = new_root->left;
	if(new_root->left != NULL)
		new_root->left->parent = z;

	new_root->left = z;
	z->parent = new_root;
	set_height(z);
	set_height(new_root);
	return new_root;
}


void set_height(node* tmp)
{
	if(tmp == NULL)
		return;
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

int balance_factor(node* z)
{
	int l=0,r=0;
	if(z->left != NULL)
		l = z->left->height;
	if(z->right != NULL)
		l = z->right->height;
	return l-r;
}