#include <bits/stdc++.h>
using namespace std;

int arr[1002][1002];
int prefix[1002][1002];
int rmq[11][11][1002][1002];

int pow2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};

void precompute_rmq(int n, int m)
{
	int ln = (int)log2(n) + 1;
	int lm = (int)log2(m) + 1;
	int m1, m2;#include <bits/stdc++.h>
using namespace std;

int arr[1002][1002];
int prefix[1002][1002];
int rmq[11][11][1002][1002];

int pow2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};

void precompute_rmq(int n, int m)
{
	int ln = (int)log2(n) + 1;
	int lm = (int)log2(m) + 1;
	int m1, m2;
	int sn,sm;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			rmq[0][0][i][j] = arr[i][j];
		}
	}

	for(int i=1; i<lm; i++)
	{
		sm = pow2[i];
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<=m-sm; k++)
			{
				rmq[0][i][j][k] = max(rmq[0][i-1][j][k], rmq[0][i-1][j][k+pow2[i-1]]);
			}
		}
	}

	for(int i=1; i<ln; i++)
	{
		sn = pow2[i];
		for(int j=0; j<=n-sn; j++)
		{
			for(int k=0; k<m; k++)
			{
				rmq[i][0][j][k] = max(rmq[i-1][0][j][k], rmq[i-1][0][j+pow2[i-1]][k]);
			}
		}
	}

	for(int i=1; i<ln; i++)
	{
		sn = pow2[i];
		for(int j=1; j<lm; j++)
		{
			sm = pow2[j];
			for(int k=0; k<=n-sn; k++)
			{
				for(int l=0; l<=m-sm; l++)
				{
					m1 = max(rmq[i-1][j][k][l], rmq[i-1][j][k+pow2[i-1]][l]);
					m2 = max(rmq[i][j-1][k][l], rmq[i][j-1][k][l+pow2[j-1]]);
					rmq[i][j][k][l] = max(m1,m2);
				}
			}
		}
	}
	return;
}

int range_query(int i1, int j1, int i2, int j2)
{
	int ln = i2-i1+1;
	int lm = j2-j1+1;
	int kn = (int)log2(ln);
	int km = (int)log2(lm);
	int tn = ln-pow2[kn];
	int tm = lm-pow2[km];
	int m1 = max(rmq[kn][km][i1][j1], rmq[kn][km][i1+tn][j1]);
	int m2 = max(rmq[kn][km][i1][j1+tm], rmq[kn][km][i1+tn][j1+tm]);
	return max(m1,m2);
}

void precompute_sum(int n, int m)
{
	prefix[0][0] = arr[0][0];

	for(int i=1; i<m; i++)
	{
		prefix[0][i] = arr[0][i] + prefix[0][i-1];
	}
	for(int i=1; i<n; i++)
	{
		prefix[i][0] = prefix[i-1][0] + arr[i][0];
		for(int j=1; j<m; j++)
		{
			prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + arr[i][j];
		}
	}
}

int calc_sum(int a1, int b1, int a2, int b2)
{
	if(a1 == 0 && b1 == 0)
		return prefix[a2][b2];
	if(a1 == 0)
		return prefix[a2][b2] - prefix[a2][b1-1];
	if(b1 == 0)
		return prefix[a2][b2] - prefix[a1-1][b2];

	return prefix[a2][b2] - prefix[a1-1][b2] - prefix[a2][b1-1] + prefix[a1-1][b1-1];
}

void func(int a, int b, int n, int m)
{
	int sum,max,temp;
	int min = 2000000000;
	for(int i=0; i<=n-a; i++)
	{
		for(int j=0; j<=m-b; j++)
		{
			sum = calc_sum(i,j,i+a-1,j+b-1);
			max = range_query(i,j,i+a-1,j+b-1);
			sum = (max*a*b-sum);
			if(min>sum)
				min = sum;
		}
	}
	printf("%d\n",min);
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	int n,m,a,b,q;
	scanf("%d %d",&n, &m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	precompute_sum(n,m);
	precompute_rmq(n,m);

	scanf("%d",&q);

	while(q--)
	{
		scanf("%d %d", &a, &b);
		func(a,b,n,m);
	}
	return 0;
}
	int sn,sm;
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			rmq[0][0][i][j] = arr[i][j];
		}
	}

	for(int i=1; i<lm; i++)
	{
		sm = pow2[i];
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<=m-sm; k++)
			{
				rmq[0][i][j][k] = max(rmq[0][i-1][j][k], rmq[0][i-1][j][k+pow2[i-1]]);
			}
		}
	}

	for(int i=1; i<ln; i++)
	{
		sn = pow2[i];
		for(int j=0; j<=n-sn; j++)
		{
			for(int k=0; k<m; k++)
			{
				rmq[i][0][j][k] = max(rmq[i-1][0][j][k], rmq[i-1][0][j+pow2[i-1]][k]);
			}
		}
	}

	for(int i=1; i<ln; i++)
	{
		sn = pow2[i];
		for(int j=1; j<lm; j++)
		{
			sm = pow2[j];
			for(int k=0; k<=n-sn; k++)
			{
				for(int l=0; l<=m-sm; l++)
				{
					m1 = max(rmq[i-1][j][k][l], rmq[i-1][j][k+pow2[i-1]][l]);
					m2 = max(rmq[i][j-1][k][l], rmq[i][j-1][k][l+pow2[j-1]]);
					rmq[i][j][k][l] = max(m1,m2);
				}
			}
		}
	}
	return;
}

int range_query(int i1, int j1, int i2, int j2)
{
	int ln = i2-i1+1;
	int lm = j2-j1+1;
	int kn = (int)log2(ln);
	int km = (int)log2(lm);
	int tn = ln-pow2[kn];
	int tm = lm-pow2[km];
	int m1 = max(rmq[kn][km][i1][j1], rmq[kn][km][i1+tn][j1]);
	int m2 = max(rmq[kn][km][i1][j1+tm], rmq[kn][km][i1+tn][j1+tm]);
	return max(m1,m2);
}

void precompute_sum(int n, int m)
{
	prefix[0][0] = arr[0][0];

	for(int i=1; i<m; i++)
	{
		prefix[0][i] = arr[0][i] + prefix[0][i-1];
	}
	for(int i=1; i<n; i++)
	{
		prefix[i][0] = prefix[i-1][0] + arr[i][0];
		for(int j=1; j<m; j++)
		{
			prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + arr[i][j];
		}
	}
}

int calc_sum(int a1, int b1, int a2, int b2)
{
	if(a1 == 0 && b1 == 0)
		return prefix[a2][b2];
	if(a1 == 0)
		return prefix[a2][b2] - prefix[a2][b1-1];
	if(b1 == 0)
		return prefix[a2][b2] - prefix[a1-1][b2];

	return prefix[a2][b2] - prefix[a1-1][b2] - prefix[a2][b1-1] + prefix[a1-1][b1-1];
}

void func(int a, int b, int n, int m)
{
	int sum,max,temp;
	int min = 2000000000;
	for(int i=0; i<=n-a; i++)
	{
		for(int j=0; j<=m-b; j++)
		{
			sum = calc_sum(i,j,i+a-1,j+b-1);
			max = range_query(i,j,i+a-1,j+b-1);
			sum = (max*a*b-sum);
			if(min>sum)
				min = sum;
		}
	}
	printf("%d\n",min);
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
	#endif

	int n,m,a,b,q;
	scanf("%d %d",&n, &m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	precompute_sum(n,m);
	precompute_rmq(n,m);

	scanf("%d",&q);

	while(q--)
	{
		scanf("%d %d", &a, &b);
		func(a,b,n,m);
	}
	return 0;
}