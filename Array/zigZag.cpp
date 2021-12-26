#include <bits/stdc++.h>
using namespace std;

void swap(int *item1, int *item2)
{
	int temp = *item1;
	*item1 = *item2;
	*item2 = temp;
}

void printArr(int arr[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

void zigzag(int arr[], int n)
{
	int flag = true;
	for(int i=0; i<n-1; i++)
	{
		if(flag)
		{
			if(arr[i] > arr[i+1])
				swap(&arr[i], &arr[i+1]);
		}
		else
		{
			if(arr[i] < arr[i+1])
				swap(&arr[i], &arr[i+1]);
		}
		flag = !flag;
	}
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
		for(int i = 0; i < n; i++)
			cin>>arr[i];
		zigzag(arr, n);
		printArr(arr, n);
	}
	return 0;
}