#include <stdio.h>
#include <string.h>

int ind[50];
int visited[50];
int adj_list[50][50];
char color[50];
int d[50];
int f[50];
int parent[50];
int time;

void reset()
{
	memset(visited,0,sizeof(visited));
	return;
}

void add_edge(int a, int b)
{
	adj_list[a][ind[a]++] = b;
	return;
}

void dfs(int source, int last)
{
	int i;
	for(i=0; i<=last; i++)
	{
		color[i] = 'w';
		parent[i] = -1;
	}
	time = 0;
	for(i=0; i<=last; i++)
	{
		if(color[i] == 'w')
		{
			dfs_visit(i);
		}
	}
}

int main(void)
{
	printf("%d\n",sizeof(adj_list));
	add_edge(0,1);
	add_edge(0,2);
	add_edge(2,0);
	add_edge(2,3);
	add_edge(3,3);
	add_edge(1,2);
	dfs(1);
	return 0;
}
