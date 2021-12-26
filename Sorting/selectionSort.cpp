#include <bits/stdc++.h>
using namespace std;

int main()
{
	int arr[] = {-1, 64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	for(int i = 0; i < n; i++)
	{
		int cMin = arr[i];
		int minIndex = i;
		int current = arr[i];
		for(int j = i; j < n; j++)
		{
			if(cMin > arr[j])
			{
				cMin = arr[j];
				minIndex = j;
			}
		}
		arr[i] = cMin;
		arr[minIndex] = current;
	}
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}