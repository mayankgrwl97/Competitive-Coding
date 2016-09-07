#include <bits/stdc++.h>
using namespace std;

char matrix[100][100];
int visited[100][100];
string final = "ALLIZZWELL";

int delta[] = {0,1,-1};

int is_possible(int a, int b, int r, int c)
{
	if(a>=0 && a<r && b>=0 && b<c)
		return 1;
	return 0;
}

int util(int ri, int ci, string str, int r, int c)
{
	int tempr, tempc;
	int flag = 0;
	str = str + matrix[ri][ci];
	visited[ri][ci] = 1;
	if(str == final)
		return 1;
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			tempr = ri+delta[i];
			tempc = ci+delta[j];
			if(is_possible(tempr, tempc, r, c) && !visited[tempr][tempc])
			{
				flag = util(tempr, tempc, str,r,c);
				if(flag)
					return 1;
				else
					visited[tempr][tempc] = 0;
			}
		}
	}
	visited[ri][ci] = 0;
	return 0;
}

int func(int ri, int ci, int r, int c)
{
	string str;
	if(matrix[ri][ci] == 'A')
	{
		return util(ri,ci,str,r,c);
	}
	return 0;
}

int finalfunc(int r, int c)
{
	for(int i=0; i<r; i++)
	{
		for(int j=0; j<c; j++)
		{
			visited[i][j]  = 0;
		}
	}
	int flag;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
		{
			flag = func(i,j,r,c);
			if(flag)
				return 1;
		}
	return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int t,r,c,ans;
	cin>>t;

	while(t--)
	{
		cin>>r>>c;
		for(int i=0; i<r; i++)
		{
			for(int j=0; j<c; j++)
			{
				cin>>matrix[i][j];
			}
		}
		ans = finalfunc(r,c);
		if(ans)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	
	return 0;
}