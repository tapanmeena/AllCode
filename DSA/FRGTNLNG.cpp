#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		unordered_map<string,int> umap;
		for(int i=0;i<k;i++)
		{
			int temp;
			cin>>temp;
			for(int j=0;j<temp;j++)
			{
				string s;
				cin>>s;
				umap[s]=1;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(umap[arr[i]] != 1)
				cout<<"NO"<<" ";
			else
				cout<<"YES"<<" ";
		}
		cout<<endl;
	}
}