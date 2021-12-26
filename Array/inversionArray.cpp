#include <bits/stdc++.h>
using namespace std;

long long merge(long long arr[], long long l, long long m, long long r)
{
	long long tempArr[r - l + 1];
	long long n = r - l + 1;
	long long a = l, b = m + 1; 
	long long count = 0;
	for(long long i = 0; i < n; i++)
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
				count += (m - a + 1);
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
	for(long long i = l, z = 0; i <= r; i++,z++)
		arr[i] = tempArr[z];
	return count;
}

long long mergeSort(long long arr[], long long l, long long r)
{
	long long count = 0;
	if(l < r)
	{
		long long m = l + (r - l)/2;
		count += mergeSort(arr, l , m);
		count += mergeSort(arr, m + 1, r);
		count += merge(arr, l ,m ,r);
	}
	return count;
}

int main()
{
	long long t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long arr[n];
		for(long long i = 0; i < n; i++)
			cin>>arr[i];
		long long count = mergeSort(arr, 0 , n-1);
		cout<<count<<endl;
	}
}