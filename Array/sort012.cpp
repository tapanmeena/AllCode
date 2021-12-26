#include<bits/stdc++.h>
using namespace std;

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
		int zeroCount = 0, oneCount = 0, twoCount = 0;
		for(int i = 0; i < n; i++)
		{
			if(arr[i] == 0)
				zeroCount++;
			else if(arr[i] == 1)
				oneCount++;
			else
				twoCount++;
		}
		for(int i = 0; i < zeroCount; i++)
			cout<<0<<" ";
		for(int i = 0; i < oneCount; i++)
			cout<<1<<" ";
		for(int i = 0; i < twoCount; i++)
			cout<<2<<" ";
		cout<<endl;
	}
}