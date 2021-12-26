#include<bits/stdc++.h>
using namespace	 std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0; i < n; i++)
			cin>>arr[i];
		vector<int> leaders;
		leaders.push_back(arr[n-1]);
		for(int i = n-2; i >= 0; i--)
		{
			if(arr[i] >= leaders[leaders.size()-1])
				leaders.push_back(arr[i]);
		}
		for(int i = leaders.size() - 1; i >= 0; i--)
			cout<<leaders[i]<<" ";
		cout<<endl;
	}
}