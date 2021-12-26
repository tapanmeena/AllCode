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
		for(int i=0;i<n;i++)
			cin>>arr[i];
		int min = arr[0];
		int temp = arr[0];
		bool found = false;
		int temp2 = arr[0]+1;
		bool found2 =false;
		for(int i=1;i<n;i++)
		{
			// cout<<"before arr[i] "<<arr[i]<<" temp "<<temp<<" temp2 "<<temp2<<endl;
			if(arr[i] != arr[n-i-1])
			{
				found = true;
				break;
			}
			if(arr[i] == temp || arr[i] == temp2)
			{
				temp = arr[i];
				if(!found2)
					temp2 = temp+1;
				else
					temp2 = temp-1;
				// cout<<"dasd"<<endl;
				continue;
			}
			else if(arr[i] == temp || arr[i] == temp-1)
			{
				temp = arr[i];
				temp2 = temp-1;
				found2 = true;
				// cout<<"asdasd"<<endl;
				continue;
			}
			// cout<<"after arr[i] "<<arr[i]<<" temp "<<temp<<" temp2 "<<temp2<<endl;
			// cout<<"sad"<<endl;
			found = true;
			break;
		}
		if(!found)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;

	}
}