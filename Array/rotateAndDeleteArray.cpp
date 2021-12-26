#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr)
{
	for(int i = 0; i<arr.size(); i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

int rotateAndDelete(vector<int> arr, int n)
{
	// int start = 0, end = n;
	int k = 1;
	while(arr.size() != 1)
	{
		// rotate
		// for(int i = end; i>start; i--)
		// 	arr[i] = arr[i-1];
		// arr[start] = temp;
	    rotate(arr.begin(), arr.begin() + arr.size()- 1, arr.end());
	    printArray(arr);
        if(k >= arr.size())
        	arr.erase(arr.end()-arr.size());
		else
		    arr.erase(arr.end() - k);
	    k++;

		// arr.insert(arr.begin(), arr[end]);
		// printArray(arr, start, end);

		// //delete
		// if(key >= end)
		// 	start++;
		// else
		// {
		// 	int place = end - start - key;
		// 	// cout<<place<<" "<<arr[place]<<endl;
		// 	for(int i = place; i<end; i++)
		// 		arr[i] = arr[i+1];
		// 	end--;
		// }
		// key++;
		// printArray(arr, start, end);
		// printArray(arr);
	}
	return arr[0];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		// int arr[n];
		vector<int> arr;
		for(int i=0; i<n; i++)
		{
			int temp;
			cin>>temp;
			arr.push_back(temp);
			// cin>>arr[i];
		}

		cout<<rotateAndDelete(arr, n)<<endl;
	}
}

