#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s = "100,180,260,310,40,535,695";
	int n = s.length();
	string temp = "";
	vector<int> result;
	for(int i=0; i<n; i++)
	{
		if(s[i] == ',')
		{
			stringstream geek(temp); 
		    int x = 0; 
		    geek >> x; 
			result.push_back(x);
			temp = "";
		}
		else
		{
			temp += s[i];
		}
	}
	stringstream geek(temp);
	int x = 0;
	geek >> x;
	result.push_back(x);
	for(int i=0;i<result.size(); i++)
		cout<<result[i]<<" ";
	cout<<endl;
/*
	int arr[result.size()];
	memset(arr, 0, sizeof(arr));

	int arr_size = result.size();
	int min = result[0];

	for(int i=0;i<arr_size; i++)
	{
		if(min > result[i])
			min = result[i];
		arr[i] = min;
	}

	for(int i=0;i<result.size(); i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	int max = result[arr_size-1];

	for(int i=arr_size-1; i>=0; i--)
	{
		if(max < result[i])
			max = result[i];
		arr[i] = max - arr[i];
	}

	for(int i=0;i<result.size(); i++)
		cout<<arr[i]<<" ";
	cout<<endl;

*/
	n = result.size();
	int profit = 0;
	for(int i=0;i<n-1;i++)
	{
		int min = result[i];
		int max = 0;
		for(int j=i;j<n-1;j++)
		{
			if(result[j+1] > result[j])
				break;
			else
				i++;
		}
		if(i == n-1)
			break;
		min = result[i];
		i++;
		cout<<"ival "<<i<<endl;
		for(int j=i;j<n; j++)
		{
			// cout<<"e "<<result[j]<<endl;
			if(result[j] >= result[j-1])
				i++;
			else
				break;
		}
		max = result[i-1];
		--i;
		cout<<"Buy "<<min<<" Sell "<<max<<" i "<<i<<endl;
	}
	return 0;
}