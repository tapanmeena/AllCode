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
		if(n == 1)
		{
			cout<<1<<endl;
			continue;
		}
		else if(n == 2)
		{
			cout<<-1<<endl;
			continue;
		}
		int leftSum = arr[0];
		int rightSum = 0;
		for(int i = 2; i < n; i++)
			rightSum += arr[i];

		bool found = false;
		for(int i = 1; i < n-1; i++)
		{
			if(i != 1)
			{
				leftSum += arr[i-1];
				rightSum -= arr[i];
			}
			if(leftSum == rightSum)
			{
				cout<<i+1<<endl;
				found = true;
				break;
			}
		}
		if(!found)
			cout<<-1<<endl;
	}
}