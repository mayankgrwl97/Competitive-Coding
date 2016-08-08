#include <bits/stdc++.h>
using namespace std;

int arr[100100];
int agla[100100];
int visited[100100];
int possible[100100];

int func(int a, int n)
{
    for(int i=1; i<=n; i++)
        visited[i] = 0;
    int nxt = agla[a];
    
    stack<int> my_stack;
    
    while(1)
    {
    	my_stack.push(nxt);
        if(visited[nxt] == 0)
        {
            if(nxt == a)
            {
            	while(!my_stack.empty())
            	{
            		possible[my_stack.top()] = 1;
            		my_stack.pop();
            	}
            	return 1;
            }
            visited[nxt] = 1;
            nxt = agla[nxt];
        }
        else
        {
        	my_stack.pop();
        	while(!my_stack.empty() && my_stack.top()!=nxt)
        	{
        		possible[my_stack.top()] = 1;
        		my_stack.pop();
        	}
        	possible[nxt] = 1;
        	break;
        }
    }
    return 0;
}

int func2(int n)
{
	for(int i=1; i<=n; i++)
		possible[i] = 0;
    int ct = 0;
    for(int i=1; i<=n; i++)
    {
        if(possible[i] != 1)
            possible[i] = func(i,n);
        ct += possible[i];
    }
    return ct;
}

int main()
{
	// freopen("input.txt","r",stdin);

	int t,n,ans;
	scanf("%d ",&t);
	while(t--)
	{
		scanf("%d ",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d ",arr+i);
    	    agla[i] = (arr[i] + i)%n + 1;
		}
		ans = func2(n);
		printf("%d\n",ans);
	}
	
	return 0;
}