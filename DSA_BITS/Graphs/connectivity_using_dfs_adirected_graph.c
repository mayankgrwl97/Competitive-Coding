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

int dfs_util(int a, int b)
{
	// printf("%d->",a);
	visited[a] = 1;
	if(a==b)
		return 1;
	int i;
	for(i=0; i<ind[a]; i++)
	{
		if(!visited[adj_list[a][i]])
			if(dfs_util(adj_list[a][i] ,b))
				return 1;	
	}
	return 0;
}

int dfs(int a, int b)
{
	reset();
	return dfs_util(a,b);
}

int main(void)
{
	// printf("%d\n",sizeof(adj_list));
	add_edge(0,1);
	add_edge(0,2);
	add_edge(2,0);
	add_edge(2,3);
	add_edge(3,3);
	add_edge(1,2);
	printf("%d\n",dfs(3,1));
	return 0;
}
