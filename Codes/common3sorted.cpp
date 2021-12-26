#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr1[] = {1,5,10,20,40,80};
	int arr2[] = {6,7,20,80,100};
	int arr3[] = {3,4,15,20,30,70,80,120};
	vector<int> sorted;
	int size1 = sizeof(arr1)/sizeof(arr1[0]);
	int size2 = sizeof(arr2)/sizeof(arr2[0]);
	int size3 = sizeof(arr3)/sizeof(arr3[0]);
	int totalSize = size1+size2+size3;
	int a=0,b=0,c=0;
	for(int i=0; i<totalSize; i++)
	{
		int minVal = INT_MAX;
		int val1 = INT_MAX;
		int val2 = INT_MAX;
		int val3 = INT_MAX;
		if (a != size1)
			val1 = arr1[a];
		if(b != size2)
			val2 = arr2[b];
		if(c != size3)
			val3 = arr3[c];

		if(val1 <= val2 && val1 <= val3)
		{
			a++;
			minVal = val1;
		}
		else if(val2 <= val3)
		{
			b++;
			minVal = val2;
		}
		else
		{
			c++;
			minVal = val3;
		}

		sorted.push_back(minVal);
	}
	for(int i=0;i<totalSize;i++)
		cout<<sorted[i]<<" ";
	cout<<endl;
	cout<<"Common elements are : ";
	int currElement = sorted[0];
	int count = 1;
	for(int i=1;i<totalSize;i++)
	{
		if(sorted[i] == currElement)
		{
			count++;
			if(count == 3)
			{
				cout<<sorted[i]<<" ";
			}
		}
		else
		{
			currElement = sorted[i];
			count = 1;
		}
	}
}