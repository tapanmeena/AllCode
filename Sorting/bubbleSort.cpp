#include <bits/stdc++.h>
using namespace std;
#define printArr(arr,n) for (int i = 0; i < n; i++) cout<<arr[i]<<" " 

void swapFunc(int *first, int *second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

int main()
{
	int arr[] = { 64, -1,25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	// printArr(arr, n);
	// cout<<endl;
	for(int i = 0; i < n; i++)
	{
		bool swap = false;
		for(int j = 0; j < n-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap = true;
				swapFunc(&arr[j], &arr[j+1]);
			}			
		}
		// printArr(arr, n);
		// cout<<endl;
		if(!swap)
			break;
	}
	// printArr(arr, n);
	// cout<<endl;
}