#include <bits/stdc++.h>
using namespace std;

void bruteForce(int arr[], int n)
{
	int count = 0;
	for(int i=0; i<n; i++)
	{
		int curr = arr[i];
		for(int j = i+1; j<n;j++)
		{
			if(arr[j] < arr[i])
				count++;
		}
	}
	cout<<count<<endl;
}

int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++)
		cin>>arr[i];
	bruteForce(arr, n);
}

84 2 37 3 67 82 19 97 91 63 27 6 13 90 63 89 100 60 47 96 54 26 64 50 71 16 6 40 84 93 67 85 16 22 60