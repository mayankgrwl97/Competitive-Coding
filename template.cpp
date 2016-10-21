#include <bits/stdc++.h>
#define all(c) c.begin(), c.end()
#define reverse(c) c.rbegin(), c.rend() //useful for sorting in descending order
#define tr(container,it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define present(container,element) (container.find(element) != container.end()) //for set/map
#define cpresent(container,element) (find(all(container),element) != container.end()) //for vector

using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		// freopen("output.txt","w",stdout);
	#endif

	vector<int> v;
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);	
	v.push_back(8);	
	v.insert(v.begin()+1,4);
	v.erase(v.begin(),v.end()-1);
	tr(v,it)
		cout<<*it<<" ";
	


	return 0;
}