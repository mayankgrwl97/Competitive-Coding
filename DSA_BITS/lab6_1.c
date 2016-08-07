/*INPUT AS ONE NO ONE STRING UNTIL EOF FROM STDIN*/ 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define max 10
#define max_words 500
#define max_word_size 50
#define max_length_of_line_in_file 100

typedef struct node node;
struct node
{
	char word[max_word_size];
	int page;
};

int ind = 0;
node all_words[max_words];
node B[max_words];
int len[max_words], C[27];

int helper(char ch)
{
	if(ch == '\0')
		return 0;
	return ch - 'a' + 1;
}

int isaplha(char ch)
{
	if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
		return 1;
	return 0;
}

void populate(int n, char str[])
{
	int i, l=strlen(str), k=0;
	int tmp = ind;
	for(i=0; i<l;)
	{
		if(isaplha(str[i]))
		{
			all_words[ind].word[k] = tolower(str[i]);
			k++;
			i++;
		}
		else
		{
			all_words[ind].word[k] = '\0';//remember to pad with extra \0 in case of radix sort for different length strings
			
			while(!isaplha(str[i]))
				i++;
			ind++;
			k=0;
		}
	}
	for(i=tmp; i<ind; i++)
	{
		all_words[i].page = n;
		// printf("%s %d\n", all_words[i].word, all_words[i].page);
	}
}

void count_sort(int t)
{
	int i;
	for(i=0; i<27; i++)
		C[i] = 0;

	for(i=0; i<ind; i++)
		C[ helper(all_words[i].word[t]) ]++;

	for(i=1; i<27; i++)
	{
		C[i] = C[i] + C[i-1];
	}
	for(i=ind-1; i>=0; i--)
	{
		// strcpy(B[ --C[helper(all_words[i].word[t])] ], all_words[i].word);
		B[ --C[helper(all_words[i].word[t])] ] = all_words[i];
	}
	for(i=0; i<ind; i++)
	{
		// strcpy(all_words[i].word, B[i]);
		all_words[i] = B[i];
	}
}

void radix_sort()
{
	int i,j;
	int l=0;
	for(i=0; i<ind; i++)
	{
		len[i] = strlen(all_words[i].word);
		if(l<len[i])
			l = len[i];
	}

	for(i=0;i<ind; i++)
	{
		for(j=len[i]; j<=l; j++)
			all_words[i].word[j] = '\0';
	}

	for(i=l-1; i>=0; i--)
		count_sort(i);

	return;
}

void final()
{
	int i;
	for(i=0; i<ind;)
	{
		printf("%s %d", all_words[i].word, all_words[i].page);
		while((i+1<ind) && strcmp(all_words[i].word, all_words[i+1].word)==0 )
		{
			if(all_words[i].page != all_words[i+1].page)
				printf(",%d", all_words[i+1].page);
			i++;
		}
		i++;
		printf("\n");
	}
}

int main()
{
	// freopen("input.txt","r",stdin);
	FILE* stream;
	stream = fopen("input.txt","r");
	int n, i=0;
	char ch;
	
	char str[5000];	
	
	while(fscanf(stream,"%d",&n) != EOF)
	{
		fscanf(stream,"%c",&ch);
		fgets(str, max_length_of_line_in_file ,stream);
		// printf("%s\n", str);
		i++;
		populate(n,str);
	}
	radix_sort();

	/*for(i=0; i<ind; i++)
		printf("%s %d\n",all_words[i].word, all_words[i].page);*/
	final();
	return 0;
}