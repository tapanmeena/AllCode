#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int main()
{
	int arr[] = { 64, -1, 25, 12, 22, 11};
	// int arr[] = {1, 2, 3, 4, 5};
	int n = sizeof(arr)/sizeof(arr[0]);
	int j = -1;
	int key;
	for(int i = 1; i < n; i++)
	{
		key = arr[i];
		j = i-1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
		printArr(arr, n);
	}
	printArr(arr, n);
}