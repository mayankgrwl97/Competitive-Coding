#include <stdio.h>
#include <string.h>


int ind[50];
int visited[50];
int ind1[50];

void add_edge(int a, int b, int adj_list[][50])
{
	adj_list[a][ind[a]++] = b;
	return;
}

void dfs_util(int a, int adj_list[][50])
{
	visited[a] = 1;
	int i;
	for(i=0; i<ind[a]; i++)
	{
		if(!visited[adj_list[a][i]])
		{
			dfs_util(adj_list[a][i], adj_list);
		}
	}
	return;
}

void dfs(int a, int adj_list[][50])
{
	memset(visited, 0, sizeof(visited));
	dfs_util(a,adj_list);
	return;
}

void reverse(int a, int last, int adj_list[][50], int adj_list1[][50])
{
	int i,j,curr;
	for(i=a; i<=last; i++)
	{
		for(j=0; j<ind[i]; j++)
		{
			curr = adj_list[i][j];
			adj_list1[curr][ind1[curr]++] = i;
			// printf("%d -> %d  , ind = %d\n", curr, i, ind1[curr]);
		}
	}
	return;
}

int is_scc(int a, int last, int adj_list[][50], int adj_list1[][50])
{
	dfs(a,adj_list);
	int i;
	for(i=a; i<=last; i++)
	{
		if(!visited[i])
			return 0;
	}

	reverse(a,last,adj_list,adj_list1);

	dfs(a,adj_list1);

	for(i=a; i<=last; i++)
	{
		if(!visited[i])
			return 0;
	}

	return 1;	
}

int main()
{
	int adj_list[50][50];
	int adj_list1[50][50];

	int t, a, b;
	while(1)
	{
		t = scanf("%d %d", &a, &b);
		if(t==EOF)
			break;
		add_edge(a,b,adj_list);
	}
	
	printf("%d\n", is_scc(1,7,adj_list,adj_list1));
	return 0;
}