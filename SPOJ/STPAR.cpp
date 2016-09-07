#include <bits/stdc++.h>
using namespace std;

void func(int n)
{
	stack<int> mystack;
	queue<int> myqueue;

	int curr;
	for(int i=0; i<n; i++)
	{
		cin>>curr;
		myqueue.push(curr);
	}
	curr = 1;
	while(!myqueue.empty() || !mystack.empty())
	{
		if(!myqueue.empty() && myqueue.front() == curr)
		{
			myqueue.pop();
			curr++;
		}
		else if(!mystack.empty() && mystack.top() == curr)
		{
			mystack.pop();
			curr++;
		}
		else if(!myqueue.empty())
		{
			mystack.push(myqueue.front());
			myqueue.pop();
		}
		else if(!mystack.empty())
		{
			cout<<"no\n";
			return;
		}
	}
	if(curr == n+1)
	{
		cout<<"yes\n";
		return;
	}
	cout<<"no\n";
	return;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;

	while(n!=0)
	{
		func(n);
		cin>>n;
	}
	
	return 0;
}