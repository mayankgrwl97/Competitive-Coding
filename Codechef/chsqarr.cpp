#include <bits/stdc++.h>
using namespace std;

int arr[1002][1002];
int prefix[1002][1002];
int rmq[1002][1002][11];
// double log10_2 = log10(2.00);

/*int (int)log2((double)int n)
{
	double x = log10((double)n) / log10_2;
	return (int)x;
}*/

int pow2[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};

/*int pow2(int n)
{
	int p = 1;
	for(int i=0; i<n; i++)
		p *= 2;
	return p;
}*/

void precompute_rmq(int n, int m)
{
	int t, l=(int)log2((double)m)+1;
	int s;

	for(int i=0; i<n; i++)//for each row
	{
		t=1;
		for(int j=0; j<m; j++)//for each element in each row
		{
			rmq[i][j][0] = arr[i][j];
		}
		for(int k=1; k<l; k++)
		{
			s = pow2[k];
			for(int j=0; j<=m-s; j++)
			{
				rmq[i][j][k] = max(rmq[i][j][k-1], rmq[i][j+t][k-1]);
			}
			t = t*2;
		}
	}
/*	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			for(int k=0; k<l; k++)
			{
				printf("%d\t",rmq[i][j][k]);
			}
			cout<<"\n";
		}
		cout<<"\n";
	}
*/	return;
}

int range_query(int a, int b, int n, int l)
{
	// int l = b-a+1;
	int k = (int)log2((double)l);
	int m1 = rmq[n][a][k];
	int t = l-pow2[k];
	int m2 = rmq[n][a+t][k];
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
			prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1];
		}
	}
	return;
	/*for(int i=0; i<n; i++)
	{
		prefix[i][0] = arr[i][0];

		for(int j=1; j<m; j++)
		{
			prefix[i][j] = arr[i][j] + prefix[i][j-1];
		}
	}*/
	/*for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			printf("%d\t",prefix[i][j]);
		}
		cout<<"\n";
	}
	cout<<"\n";*/
	return;
}

int calc_sum(int a1, int b1, int a2, int b2, int n)
{
	if(a1 == 0 && b1 == 0)
		return prefix[a2][b2];
	if(a1 == 0)
		return prefix[a2][b2] - prefix[a2][b2-b1-1];
	if(b1 == 0)
		return prefix[a2][b2] - prefix[a2-a1-1][b2];
	return prefix[a2][b2] - prefix[a1-1][b1-1];
}

void func(int a, int b, int n, int m)
{
	int sum,max,temp;
	int min = 2000000000;
	for(int i=0; i<=n-a; i++)
	{
		for(int j=0; j<=m-b; j++)
		{
			sum = 0;
			max = -1;
			for(int k=0; k<a; k++)
			{
				sum += calc_sum(j,j+b-1,i+k);
				// sum += prefix[i][j+b] - prefix[i][j];
				temp = range_query(j,j+b-1,i+k, b);
				if(temp>max)
					max = temp;
			}
			/*sum = 0;
			max = -1;
			for(int k=i; k<i+a; k++)
			{
				for(int l=j; l<j+b; l++)
				{
					if(max<arr[k][l])
						max = arr[k][l];
					sum += arr[k][l];
				}
			}*/
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

	int n,m,a,b;
	cin>>n>>m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	precompute_sum(n,m);
	precompute_rmq(n,m);

	int q;
	cin>>q;

	while(q--)
	{
		scanf("%d %d", &a, &b);
		func(a,b,n,m);
	}
	/*for(int i=1; i<100; i++)
		cout<<(int)log2((double)i)<<"\n";*/
	return 0;
}