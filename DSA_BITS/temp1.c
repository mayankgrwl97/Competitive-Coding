#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define num 3

char str[num][50];
// char buf[num][50];
char* B[num];
int len[num];

int func(char ch)
{
	if(ch == '\0')
		return 0;
	return tolower(ch)-'a'+1;
}

void count_sort(int index)
{
	int i,t,C[27];
	for(i=0; i<27; i++)
		C[i] = 0;
	for(i=0; i<num; i++)
	{
		C[func(str[i][index])]++;
	}

	for(i=1; i<=27; i++)
		C[i] = C[i] + C[i-1];

	for(i=num-1; i>=0; i--)
	{
		B[ C[func(str[i][index])] - 1] = str[i];
	}
	for(i=0; i<num-1; i++)
	{
		strcpy(str[i],B[i]);
	}
}

void radix_sort()
{
	int i,j,l=0;
	for(i=0; i<num; i++)
	{
		len[i] = strlen(str[i]);	
		if(l<len[i])
			l = len[i];
	}
	for(i=0; i<num; i++)
	{
		for(j=len[i]; j<l; j++)
		{
			str[i][j] = '\0';
		}
		str[i][j] = '\0';
	}

	for(i=0; i<num; i++)
	{
		for(j=0; j<l; j++)
		{
			printf("%d ", func(str[i][j]));
		}
		printf("\n");
	}

	/*for(i=l-1; i>=0; i++)
	{
		count_sort(i);
	}*/

	count_sort(l-1);
	for(i=0; i<num-1; i++)
	{
		// B[i] = str[i];
		printf("%s\n", str[i]);
	}
	return;
}

int main()
{
	freopen("input.txt","r",stdin);
	int i,l=0;
	for(i=0; i<num; i++)
	{
		scanf("%s",str[i]);
	}
	
	/*for(i=0; i<num; i++)
	{
		B[i] = str[i];
		strcpy(str[i],B[i]);
	}*/
	radix_sort();
	return 0;
}