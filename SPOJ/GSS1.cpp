#include <bits/stdc++.h>
#define min -20000
using namespace std;

typedef struct node node;

struct node{
	int sum,left_sum,right_sum,max_sum;
};

int get(int n)
{
	int i=1;
	for(;i<n; i = i<<1);
	return i<<1;
}

int max(int a, int b)
{
	return (a>b ? a : b);
}

void create_tree(node tree[], int arr[], int lo, int hi, int root)
{
	if(lo == hi)
	{
		node n;
		n.sum = n.right_sum = n.left_sum = n.max_sum = arr[lo];
		tree[root] = n;
		return;
	}
	
	int mid = (lo+hi)/2;
	int l = 2*root+1, r = l+1;
	create_tree(tree,arr,lo,mid,l);
	create_tree(tree,arr,mid+1,hi,r);
	
	tree[root].sum = tree[l].sum + tree[r].sum;
	tree[root].left_sum = max(tree[l].left_sum, tree[l].sum + tree[r].left_sum);
	tree[root].right_sum = max(tree[r].right_sum, tree[l].right_sum + tree[r].sum);
	tree[root].max_sum = max(tree[l].max_sum,max(tree[r].max_sum,max(tree[l].right_sum+tree[r].left_sum,max(tree[root].left_sum,tree[root].right_sum))));
	
	return;
}

node query(node tree[], int lo, int hi, int root, int qlo, int qhi)
{
	node n;
	if(qlo <= lo && qhi >= hi)
		return tree[root];
	if(qlo > hi || qhi < lo)
	{
		n.left_sum = n.right_sum = n.max_sum = min;
		n.sum = 0;
		return n;
	}
	int mid = (lo+hi)/2;
	int l = 2*root+1 ,r = l+1;
	node n1 = query(tree, lo, mid, l, qlo, qhi);
	node n2 = query(tree, mid+1, hi, r, qlo, qhi);
	n.sum = n1.sum + n2.sum;
	n.left_sum = max(n1.left_sum, n1.sum+n2.left_sum);
	n.right_sum = max(n2.right_sum, n1.right_sum+n2.sum);
	n.max_sum = max(n1.max_sum,max(n2.max_sum,max(n1.right_sum+n2.left_sum, max(n.left_sum,n.right_sum))));
	return n;
}

int main() 
{
	int N;
	cin>>N;
	int arr[N+1];
	node tree[get(N)+1];
	for(int i=0; i<N; i++)
		scanf("%d",arr+i);
	create_tree(tree,arr,0,N-1,0);
	
	// for(int i=0; i<2*N-1; i++)
	// printf("%d - %d %d %d %d\n",i,tree[i].left_sum, tree[i].right_sum , tree[i].sum, tree[i].max_sum);
	
	int M;
	cin>>M;
	int x,y;
	
	while(M--)
	{
		scanf("%d %d",&x,&y);
		printf("%d\n",query(tree,0,N-1,0,x-1,y-1).max_sum);
	}
	
	
	return 0;
}