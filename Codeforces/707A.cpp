#include <bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n,m;
	cin>>n>>m;
	int flag = 0;

	char photo[n][m];

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cin>>photo[i][j];
			if(photo[i][j] == 'C' || photo[i][j] == 'M' || photo[i][j] == 'Y')
				flag = 1;
		}
	}

	if(flag == 1)
		cout<<"#Color\n";
	else
		cout<<"#Black&White\n";
	
	return 0;
}