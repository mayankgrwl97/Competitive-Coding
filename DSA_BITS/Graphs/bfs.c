#include <stdio.h>
#include <string.h>

int ind[50];
int visited[50];
int adj_list[50][50];
int queue[50];
int qin,qout;

void new_queue()
{
	qin = qout = 0;
	return;
}

void qpush(int a)
{
	queue[qin++] = a;
	return;
}

int qpop()
{
	if(!isqempty())
		return queue[qout++];
	return -12345;
}

int isqempty()
{
	if(qin == qout)
		return 1;
	return 0;
}

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

void bfs(int a)
{
	int tmp;
	new_queue();
	qpush(a);
	// visited[a] = 1;
	// printf("%d",a);
	while(!isqempty())
	{
		tmp = qpop();
		if(!visited[tmp])
			printf("->%d",tmp);
				visited[tmp] = 1;

		int i;
		for(i=0; i<ind[tmp]; i++)
		{
			if(!visited[adj_list[tmp][i]])
				qpush(adj_list[tmp][i]);
		}
	}
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
	// printf("%d\n",dfs(1,3));
	bfs(1);
	return 0;
}
