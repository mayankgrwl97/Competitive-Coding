#include <bits/stdc++.h>
using namespace std;

typedef struct node node;

struct node{
	int odd;
	int even;
};

int get_size(int n)
{
	int i=1;
	for(;i<n; i=i<<1);
	return i<<1;
}

void generate_tree(int arr[], node seg_tree[], int lo, int hi, int root)
{
	if(lo == hi)
	{
		if(arr[lo] % 2 == 0)
		{
			seg_tree[root].odd = 0;
			seg_tree[root].even = 1;
		}
		else
		{
			seg_tree[root].odd = 1;
			seg_tree[root].even = 0;
		}
		return;
	}

	int mid = (lo+hi)/2, l = 2*root+1, r = l+1;

	generate_tree(arr,seg_tree, lo, mid, l);
	generate_tree(arr,seg_tree, mid+1,hi, r);

	seg_tree[root].odd = seg_tree[l].odd + seg_tree[r].odd;
	seg_tree[root].even = seg_tree[l].even + seg_tree[r].even;
	return;
}

void update_tree(node seg_tree[], int lo, int hi, int root, int index, int val)
{
	if(lo == hi)
	{
		if(val %2 == 0)
		{
			seg_tree[root].odd = 0;
			seg_tree[root].even = 1;
		}
		else
		{
			seg_tree[root].odd = 1;
			seg_tree[root].even = 0;
		}
		return;
	}
	int mid = (lo+hi)/2, l = 2*root+1, r = l+1;
	if(index <= mid)
	{
		update_tree(seg_tree, lo, mid, l, index, val);
	}
	else
	{
		update_tree(seg_tree, mid+1, hi, r, index, val);
	}
	seg_tree[root].odd = seg_tree[l].odd + seg_tree[r].odd;
	seg_tree[root].even = seg_tree[l].even + seg_tree[r].even;	
	return;
}

node query(node seg_tree[], int lo, int hi, int root, int qlow, int qhigh)
{
	if(qlow<=lo && qhigh>=hi)
	{
		return seg_tree[root];
	}
	if(qlow>hi || qhigh<lo)
	{
		node n;
		n.odd = 0;
		n.even = 0;
		return n;
	}
	int mid = (lo+hi)/2, l = 2*root+1, r = l+1;

	node n1 = query(seg_tree,lo,mid,l,qlow,qhigh);
	node n2 = query(seg_tree,mid+1,hi,r,qlow,qhigh);
	node n;
	n.odd = n1.odd+n2.odd;
	n.even = n1.even+n2.even;
	return n;
}

int main()
{
	freopen("input.txt","r",stdin);
	int N;
	cin>>N;
	int arr[N];

	for(int i=0; i<N; i++)
	{
		scanf("%d",arr+i);
	}

	node seg_tree[get_size(N)];
	generate_tree(arr,seg_tree,0,N-1,0);

	/*for (int i=0; i<2*N-1; i++)
	{
		printf("%d %d %d\n",i,seg_tree[i].odd,seg_tree[i].even);
	}*/

	int Q,a,x,y;
	cin>>Q;
	while(Q--)
	{
		scanf("%d %d %d",&a,&x,&y);
		switch(a)
		{
			case 0:
			update_tree(seg_tree,0,N-1,0,x-1,y);
			break;
			
			case 1:
			printf("%d\n",(query(seg_tree,0,N-1,0,x-1,y-1)).even);
			break;
			
			case 2:
			printf("%d\n",(query(seg_tree,0,N-1,0,x-1,y-1)).odd);			
			break;
		}
	}
	return 0;
}