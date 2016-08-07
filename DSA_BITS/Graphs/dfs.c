#include <stdio.h>
#include <string.h>

int ind[50];
int visited[50];
int adj_list[50][50];

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

void dfs_util(int a)
{
	printf("%d->",a);
	visited[a] = 1;
	int i;
	for(i=0; i<ind[a]; i++)
	{
		if(!visited[adj_list[a][i]])
			dfs_util(adj_list[a][i]);	
	}
	return;
}

void dfs(int a)
{
	reset();
	dfs_util(a);
	return;
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
