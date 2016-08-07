#include <bits/stdc++.h>
#define scan(i) scanf("%d",&i)
#define print(i) printf("%d\n",i)

using namespace std;

typedef struct node node;
struct node{
	int min, max;
};

node seg_tree[2100000];
int lazy[2100000];

void generate_tree(int lo, int hi, int root)
{
	if(lo==hi)
	{
		seg_tree[root].max = seg_tree[root].min = 0;
		return;
	}

	int mid = (lo+hi)/2 , l = 2*root+1, r = l+1;

	generate_tree(lo,mid,l);
	generate_tree(mid+1,hi,r);

	seg_tree[root].max = seg_tree[root].min = 0;
	return;
}

void update_tree(int lo, int hi, int i, int j, int root)
{
	if(lazy[root] != 0)//if the root node is not updated earlier
	{
		seg_tree[root].max += lazy[root];
		seg_tree[root].min += lazy[root];

		if(lo != hi)//indicates that the node is not a leaf node
		{
			lazy[2*root+1] += lazy[root];
			lazy[2*root+2] += lazy[root];
		}
		lazy[root] = 0;
	}

	if(lo>hi || i>hi || j<lo)//out of range
		return;

	if(lo >= i && hi<= j)//completely in range
	{
		seg_tree[root].max++;
		seg_tree[root].min++;
		if(lo != hi)
		{
			lazy[2*root+1]++;
			lazy[2*root+2]++;
		}
		return;
	}

	int mid = (lo+hi)/2 , l = 2*root+1, r = l+1;

	update_tree(lo,mid,i,j,l);
	update_tree(mid+1,hi,i,j,r);

	seg_tree[root].min = min(seg_tree[l].min,seg_tree[r].min);
	seg_tree[root].max = max(seg_tree[l].max,seg_tree[r].max);
	return;
}

int query(int lo, int hi, int root, int x)
{
	if(lazy[root] != 0)//if the root node is not updated earlier
	{
		seg_tree[root].max += lazy[root];
		seg_tree[root].min += lazy[root];

		if(lo != hi)//indicates that the node is not a leaf node
		{
			lazy[2*root+1] += lazy[root];
			lazy[2*root+2] += lazy[root];
		}
		lazy[root] = 0;
	}

	if(lo == hi)
	{
		if(seg_tree[root].min >= x)
			return 1;
		return 0;
	}

	if(seg_tree[root].min >= x)
	{
		return hi-lo+1;
	}

	if(seg_tree[root].max < x)
	{
		return 0;
	}

	int mid = (lo+hi)/2 , l = 2*root+1, r = l+1;
	int c1 = query(lo,mid,l,x);
	int c2 = query(mid+1,hi,r,x);
	return c1+c2;
}

int main()
{
	freopen("input.txt","r",stdin);
	int N,M;
	scan(N);
	// generate_tree(0,N-1,0);
	scan(M);
	int l,r;
	while(M--)
	{
		scan(l);scan(r);
		update_tree(0,N-1,l-1,r-1,0);
	}
	query(0,N-1,0,1);
	int Q,x;
	scan(Q);
	while(Q--)
	{
		scan(x);
		print(query(0,N-1,0,x));
	}
	return 0;
}