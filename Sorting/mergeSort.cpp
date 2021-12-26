#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int tempArr[r - l + 1];
	int n = r - l + 1;
	int a = l, b = m + 1; 

	for(int i = 0; i < n; i++)
	{
		if(a <= m && b <= r)
		{
			if(arr[a] <= arr[b])
			{
				tempArr[i] = arr[a];
				a++;
			}
			else
			{
				tempArr[i] = arr[b];
				b++;
			}
		}
		else if(a > m)
		{
			tempArr[i] = arr[b];
			b++;
		}
		else if(b > r)
		{
			tempArr[i] = arr[a];
			a++;
		}
	}
	for(int i = l, z = 0; i <= r; i++,z++)
		arr[i] = tempArr[z];
}

void mergeSort(int arr[], int l, int r)
{
	if(l < r)
	{
		int m = l + (r - l)/2;
		mergeSort(arr, l , m);
		mergeSort(arr, m + 1, r);
		merge(arr, l ,m ,r);
	}
}

int main()
{
	int arr[] = { 64, -1, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);

	mergeSort(arr, 0 , n-1);
	while(n--)
		cout<<arr[n]<<" ";
}