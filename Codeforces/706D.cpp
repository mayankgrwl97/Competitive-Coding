#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	int count;
	char bit;
	struct TrieNode *zero;
	struct TrieNode *one;
};

struct TrieNode* newNode(int a)
{
	char bit = (a==1?'1':'0');

	struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));

	node->count = 0;
	node->bit = bit;
	node->zero = NULL;
	node->one = NULL;

	return node;
}

struct TrieNode* root = NULL;

void newTree()
{
	root = newNode(0);
	return;
}

void remove(int x)
{
	struct TrieNode* curr = root;
	struct TrieNode* temp;
	int t;

	stack<struct TrieNode*> mystack;

	for(int i=31; i>=0; i--)
	{
		t = ((x>>i)&1);
		if(t)
			temp = curr->one;
		else
			temp = curr->zero;
		curr = temp;
		mystack.push(temp);
	}
	if(temp->count > 1)
		temp->count--;
	else
		while(!mystack.empty())
		{
			temp=mystack.top();

			if(temp->zero != NULL || temp->one != NULL)
				return;
		
			mystack.pop();
		
			if(!mystack.empty())
			{
				if(temp->bit == '0')
					mystack.top()->zero = NULL;
				else
					mystack.top()->one = NULL;
				free(temp);
			}
			else
			{
				if(temp->bit == '0')
					root->zero = NULL;
				else
					root->one = NULL;
				free(temp);
			}
		}
	return;
}

void insert(int x)
{
	struct TrieNode* curr = root;
	struct TrieNode* temp;
	int t;

	for(int i=31; i>=0; i--)
	{
		t = ((x>>i)&1);
		if(t)
		{
			if(curr->one == NULL)
			{
				temp = newNode(t);
				curr->one = temp;
			}
			curr = curr->one;
		}
		else
		{
			if(curr->zero == NULL)
			{
				temp = newNode(t);
				curr->zero = temp;
			}
			curr = curr->zero;
		}
	}
	curr->count++;
	return;
}

int find(int x)
{
	int y = 0;
	int t;
	int z = 1;

	struct TrieNode* curr = root;

	for(int i=31; i>=0; i--)
	{
		t = ((x>>i)&1);
		if(t)
		{
			if(curr->zero != NULL)
			{
				curr = curr->zero;
			}
			else
			{
				curr = curr->one;
				y = y|(z<<i);
			}
		}
		else
		{
			if(curr->one != NULL)
			{
				curr = curr->one;
				y = y|(z<<i);
			}
			else
			{
				curr = curr->zero;
			}
		}
	}
	return y;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int q,x;
	cin>>q;
	char ch;
	newTree();
	insert(0);
	while(q--)
	{
		cin>>ch>>x;
		if(ch == '+')
		{
			insert(x);
		}
		else if(ch == '-')
		{
			remove(x);
		}
		else
		{
			cout<<(x^find(x))<<"\n";
		}
	}
	// cout<<(0|(1<<3));
	// cout<<max((6^8),(6^9));
	// cout<<(8^3);
	return 0;
}