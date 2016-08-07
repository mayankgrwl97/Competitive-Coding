#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

/*-------------char stack-------------*/

typedef struct node node;

struct node
{
	int data;
	node* next;
};

node* newStack()
{
	node* ptr = NULL;
	return ptr;
}

node* getNode()
{
	node* ptr = (node*)malloc(sizeof(node));
	return ptr;
}

void push(int data, node** ptr)
{
	node* p = getNode();
	p->data = data;
	p->next = *ptr;
	*ptr = p;
}

int top(node* ptr)
{
	if(ptr == NULL)
		return 'a';
	else
		return ptr->data;
}

int pop(node** ptr)
{
	if(*ptr == NULL)
		return 'a';
	else
	{
		int tmp = (*ptr)->data;
		*ptr = (*ptr)->next;
		return tmp;
	}
}

int isEmpty(node* ptr)
{
	if(ptr == NULL)
		return 1;
	else
		return 0;
}

/*----------------End of char stack-------------*/


int isOperator(char c)
{
	if(c == '$' || c == '*' || c == '/' || c == '-' || c == '+' /*|| c=='(' || c==')'*/)
		return 1;
	return 0;
}

int isOperand(char c)
{
	if((c>='a' && c<='z') || (c>='A' && c<='Z'))
		return 1;
	return 0;
}

int prcd(char a, char b)
{
	/*if(a=='(')
		return 0;
	else if(b==')' && a!='(')
		return 0;*/
	if(b=='+' || b=='-')
		return 1;
	else if((b=='*' || b=='/')&&(a!='+' && a!='-'))
		return 1;
	else if(b=='$' && a=='$')
		return 1;
	return 0;
}

void infix_to_postfix(char* str, char* post)
{
	node* st = newStack();
	char symb, topsymb;
	scanf("%s",str);
	int l = strlen(str), i, j=0;

	for (i=0; i<l; i++)
	{
		symb = str[i];

		if(isOperand(symb))
		{
			post[j] = symb;
			//printf("%c",symb);
			j++;
		}
		else if(isOperator(symb))
		{
			while(!isEmpty(st) && top(st) != '('  && prcd(top(st),symb))
			{
				post[j] = pop(&st);
				j++;
			}
			/*
			if(iscEmpty(st) || symb != ')')
			{
				cpush(symb, &st);
			}
			else
			{
				topsymb = cpop(&st);
			}*/
			push(symb, &st);
		}
		else if(symb == '(')
			push('(', &st);
		else if(symb == ')')
		{
			while(!isEmpty(st) && top(st)!='(')
			{
				post[j] = pop(&st);
				j++;
			}
			pop(&st);
		}
	}

	while(!isEmpty(st))
	{
		post[j] = pop(&st);
		j++;
	}
	post[j] = '\0';
	printf("%s\n",post);

	return;
}

void print1(int a)
{
	if(!isOperand(a))
		printf("\tTEMP%d\n",a);
	else
		printf("\t%c\n",a);
	return;
}

void print2(char a)
{
	if(a == '+')
		printf("AD");
	else if(a == '*')
		printf("ML");
	else if(a == '-')
		printf("SB");
	else if(a == '/')
		printf("DV");
	return;
}

void evaluate(char* str)
{
	int l = strlen(str), i;
	int j=1;

	node* stack = newStack();

	for (i=0; i<l; i++)
	{
		if(isOperand(str[i]))
		{
			push(str[i], &stack);
		}
		else
		{
			int op2 = pop(&stack);
			int op1 = pop(&stack);
			printf("LD");
			print1(op1);
			print2(str[i]);
			print1(op2);
			printf("ST");
			print1(j);
			push(j,&stack);
			j++;
		}
	}
}

int main()
{
	char str[500], post[500];
	infix_to_postfix(str,post);
	evaluate(post);
	return 0;
}