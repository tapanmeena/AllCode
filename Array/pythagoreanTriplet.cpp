#include <bits/stdc++.h>
using namespace std;

void findTriplet(int arr[], int n)
{
	for(int i=0; i<n; i++)
		arr[i] *= arr[i];
	sort(arr, arr+n);

	for (int i = n - 1; i >= 2; i--) { 
        int l = 0; // index of the first element in arr[0..i-1] 
        int r = i - 1; // index of the last element in arr[0..i-1] 
        while (l < r) { 
            if (arr[l] + arr[r] == arr[i])
            {
            	cout<<"Yes"<<endl;
            	return;
            }
            (arr[l] + arr[r] < arr[i]) ? l++ : r--; 
        } 
    }
    cout<<"No"<<endl;
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
		findTriplet(arr, n);
	}
} 