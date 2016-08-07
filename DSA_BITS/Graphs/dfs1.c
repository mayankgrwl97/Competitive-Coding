#include <stdio.h>
/*
typedef struct edge edge;

struct edge
{
	int 
};*/

int ind[50];
int adj_list[50][50];
int visited[50];

void add_edge(int a, int b)
{
	adj_list[a][ind[a]++] = b;
	return;
}

int dfs(int a, int b)
{
	visited[a] = 1;
	// printf("%d->", a);
	int i;
	for(i=0; i<ind[a]; i++)
	{
		if(adj_list[a][i] == b)
			return 1;
		if(!visited[adj_list[a][i]])
		{
			visited[adj_list[a][i]] = 1;
			if(dfs(adj_list[a][i], b))
				return 1;	
		}
	}
	return 0;
}

void reset()
{
	int i;
	for(i=0; i<50; i++)
	{
		visited[i] = 0;
	}
}

int main()
{
	add_edge(0,1);
	add_edge(0,2);
	add_edge(2,0);
	add_edge(1,2);
	add_edge(2,3);
	add_edge(3,3);
	/*dfs(0);
	reset();
	printf("\n");
	dfs(1);
	reset();
	printf("\n");
	dfs(2);
	reset();
	printf("\n");
	dfs(3);*/

	printf("%d\n", dfs(1,3));
	return 0;
}