#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	
	sort(arr, arr+n);
	unordered_map<int,int> umap;

	for(int i=0;i<n;i++)
		umap[arr[i]] = 1;

	vector<int> result;
	vector<int> temp;
	for(int i=0;i<n;i++)
	{
		int tempVal = arr[i];
		if(umap.find(tempVal) != umap.end())
		{
			temp.push_back(tempVal);
			while(true)
			{
				if(umap.find(tempVal+k) != umap.end())
				{
					temp.push_back(tempVal+k);
					tempVal +=k;
				}
				else
					break;
			}
		}

		if(temp.size()>=result.size())
			result = temp;
		temp.clear();
	}
	cout<<result.size()<<endl;
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<endl;
	// cout<<endl;
		// cout,<result
}