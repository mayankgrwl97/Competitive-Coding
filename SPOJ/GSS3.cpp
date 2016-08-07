#include <iostream>
#include <stdio.h>
#include <limits.h>
#define min -20000
using namespace std;

typedef struct
{
	int left;//max sum starting from the leftmost index
	int right;//max sum ending at the leftmost index
	int sum;//sum of all elements
	int best;//max sum of elements
}node;

node input[50000];
node seg_tree[100100];
node flag;
node final;

int MAX(int a, int b)
{
	return (a>b) ? a : b;
}
void set_root(int root)
{
	seg_tree[root].left = MAX(seg_tree[2*root+1].left, seg_tree[2*root+1].sum + seg_tree[2*root+2].left);
	seg_tree[root].right = MAX(seg_tree[2*root+2].right, seg_tree[2*root+2].sum + seg_tree[2*root+1].right);
	seg_tree[root].sum = seg_tree[2*root+1].sum + seg_tree[2*root+2].sum;
	seg_tree[root].best = MAX(MAX(seg_tree[2*root+2].best, seg_tree[2*root+1].best) , seg_tree[2*root+2].left + seg_tree[2*root+1].right);
}
void construct_tree(int low, int high, int root)
{
	if(low == high)
	{
		seg_tree[root].left = input[low].left;
		seg_tree[root].right = input[low].right;
		seg_tree[root].sum = input[low].sum;
		seg_tree[root].best = input[low].best;
		return;
	}
	int mid = (low + high)/2;
	construct_tree(low,mid,2*root+1);
	construct_tree(mid+1,high,2*root+2);
	
	set_root(root);
	return;
}
node merge(node n1, node n2)
{
	node final;
	final.left = MAX(n1.left, n1.sum + n2.left);
	final.right = MAX(n2.right, n2.sum + n1.right);
	final.sum = n1.sum + n2.sum;
	final.best = MAX(MAX(n1.best,n2.best),n1.right + n2.left);
	return final;
}
node max_sum(int low, int high, int root, int qlow, int qhigh)
{
	if(qlow <= low && qhigh >= high)//total overlap
		return seg_tree[root];
	if(qlow > high || qhigh < low)
		return flag;
	int mid = (low+high)/2;
	return merge(max_sum(low,mid,2*root+1,qlow,qhigh), max_sum(mid+1,high,2*root+2,qlow,qhigh));
}
void update_tree(int low, int high, int x, int y, int root)
{
	if(low==high && low==x)
	{
		seg_tree[root].left = y;
		seg_tree[root].right = y;
		seg_tree[root].sum = y;
		seg_tree[root].best = y;
		return;
	}
	
	int mid = (low+high)/2;
	if (x>=low && x<= mid)
	{
		update_tree(low, mid, x, y, 2*root+1);
	}
	else if(x<=high && x>mid)
	{
		update_tree(mid+1, high, x, y, 2*root+2);
	}
	set_root(root);
	return;
}

int main()
{
	int n,m;//n is the no. of integers//m is the no. of queries
	int tmp;
	node ans;
	scanf("%d",&n);
	flag.left = min; flag.right = min; flag.best = min; flag.sum = 0;
	for(int i=0; i<n; i++)//setting the leaf nodes
	{
		scanf("%d",&tmp);
		input[i].left = tmp;
		input[i].right = tmp;
		input[i].sum = tmp;
		input[i].best = tmp;
	}
	scanf("%d",&m);
	construct_tree(0, n-1, 0);
	int q, x, y;
	for(int i=0; i<m; i++)
	{
		scanf("%d %d %d",&q, &x, &y);
		if(q==1)
		{
			ans = max_sum(0,n-1,0,x-1,y-1);
			printf("%d\n",ans.best);
		}
		else if(q==0)
		{
			update_tree(0,n-1,x-1,y,0);
		}
	}
	return 0;
}