#include <bits/stdc++.h>
using namespace std;

void build(int node, int start, int end)//Time Complexity O(n)
{
	if(start>end)
		return;
	if(start == end)//Leaf Node
	{
		tree[node] = arr[start];
		return ;
	}

	int mid = (start + end)/2;

	build(2*node, start, mid);//left subtree
	build(2*node+1, mid+1, end)//right subtree
	tree[node] = tree[2*node] + tree[2*node+1];//update node

	return;
}

int query_sum(int node, int start,  int end, int l, int r) //node stores arr[start.....end] , query from [l....r] , node = index of seg tree node
{
	//no overlap
	if(start>end || l>end || start>r) // complete disjoint intervals start..end and l..r
		return 0;
	//complete overlap
	if(l<=start && r>=end)
		return tree[node];
	//partial overlap
	int mid = (start + end)/2;
	return query_sum(2*node, start, mid, l, r) + query_sum(2*node+1, mid+1, end, l, r);
}

void updateindex(int node, int start, int end, int idx, int value)
{
	if(start>end)
		return ;
	if(start == end)
	{
		tree[node] += value;
		arr[idx] += value;
		return ;
	}
	int mid = (start+end)/2;

	if(start<=idx && idx<=mid)
	{
		updateindex(2*node,start,mid,idx,value);
	}
	if(mid+1<=idx && idx<=end)
	{
		updateindex(2*node+1,mid+1,end,idx,value);
	}
	tree[node] = tree[2*node] + tree[2*node+1];
	return ;
}

void update(int node, int start, int end, int l, int r, int value)
{
	if(start>end || start>r || end<l)
		return ;
	if(start == end)
	{
		tree[node] += value;
		return ;
	}
	int mid = (start+end)/2;
	update(2*node, start, mid, l, r, value);
	update(2*node+1, mid+1, end, l, r, value);
	tree[node] = tree[2*node] + tree[2*node+1];
	return ;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n;
	int arr[n];
	int seg_tr_size = 2*pow(2,(int)ceil(log2(n)));


	return 0;
}