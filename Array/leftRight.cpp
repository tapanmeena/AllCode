#include <bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

bool checkLeft(int arr[], int i, int n)
{
	for(int j = 0; j<i; j++)
	{
		if(arr[j] > arr[i])
			return false;
	}
	return true;
}

bool checkRight(int arr[], int i, int n)
{
	for(int j = i+1; j<n; j++)
	{
		if(arr[j] < arr[i])
			return false;
	}
	return true;
}

void bruteForce(int arr[], int n)
{
	for(int i = 1; i < n-1; i++)
	{
		bool valid = false;
		valid = checkLeft(arr, i, n);
		if(valid)
			valid = checkRight(arr, i, n);
		if(valid)
		{
			cout<<arr[i]<<endl;
			return;
		}
	}
	cout<<-1<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0; i<n; i++)
			cin>>arr[i];
		bruteForce(arr, n);
		// printArr(arr, n);
	}
}