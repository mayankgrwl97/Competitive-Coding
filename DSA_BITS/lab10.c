#include <stdio.h>

typedef struct edge edge;
typedef struct vertex vertex;

struct vertex
{
	int label;//vertex label
	int edges;//number of outgoing edges
};

int count=0;

struct edge
{
	int label;//edge label
	int dest;//destination vertex number
};

vertex vertices[100];
edge adjList[100][100];

int accepts(int q, int bin_string[], int l)
{
	if(l==0)
		return vertices[q].label;

	int i;
	for(i=1; i<=vertices[q].edges; i++)
	{
		if( (bin_string[1] == adjList[q][i].label) && (accepts(adjList[q][i].dest, bin_string+1, l-1)) )
			return 1;
	}
	return 0;
}

int power2(int n)
{
	int p=1;
	int i;
	for(i=0; i<n; i++)
	{
		p = p*2;
	}
	return p;
}

void populate(int bin_string[], int l, int x)
{
	while(l>=1)
	{
		bin_string[l] = x%2;
		x = x/2;
		l--;
	}
	return;
}
void generate_bin(int bin_string[])
{
	int i=1;//length of binary string
	while(1)
	{
		int j;//the number corresponding to the binary string
		for(j=0; j<power2(i); j++)
		{
			populate(bin_string, i, j);
			if(accepts(1, bin_string, i))
			{
				int k;
				for(k=1; k<=i;k++)
					printf("%d",bin_string[k]);
				printf("\n");
				count++;
				if(count == 10)
					return;
			}
		}
		i++;
	}
	return;
}

int main()
{
	// freopen("input.txt","r",stdin);
	int i,n,e;
	int bin_string[50];
	scanf("%d",&n);

	for(i=1; i<=n; i++)
	{
		scanf("%d",&e);//vertex number
		scanf("%d",&vertices[e].label);//vertex label
		scanf("%d",&vertices[e].edges);//number of outgoing edges
		int j;
		for(j=1; j<=vertices[e].edges; j++)
		{
			scanf("%d",&adjList[i][j].label);//edge label
			scanf("%d",&adjList[i][j].dest);//destination vertex
		}
	}
	if(vertices[1].label == 1)
	{
		printf("e\n");
		count++;
	}
	generate_bin(bin_string);
	
	return 0;
}
