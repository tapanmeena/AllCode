#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,y;
		cin>>n>>x>>y;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int dist = x*y;
		int result[102];
		memset(result, 0, sizeof(result));
		for(int i=0;i<n;i++)
		{
			int left=1, right = 100;
			if(arr[i]-dist <1)
				left = 1;
			else
				left = arr[i]-dist;
			if(arr[i]+dist >100)
				right = 100;
			else
				right = arr[i] + dist;
			result[left] += 1;
			result[right+1] -= 1;
			cout<<left <<" "<<right<<endl;
		}
		int curr=0;
/*		for(int i=1;i<=100;i++)
			cout<<result[i]<<" ";
		cout<<endl;*/
		for(int i=1;i<=100;i++)
		{
			curr += result[i];
			if(curr>0)
				result[i] = -1;
			else
				result[i] = 0;
		}
		int count=0;
		for(int i=1;i<=100;i++)
			if(result[i]==0)
				count++;
		cout<<count<<endl;
	}
}