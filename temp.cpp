/*
longest path in a matrix
#include<bits/stdc++.h>
using namespace std;

vector<int> checkForCell(vector<vector<int>> &mat, vector<vector<bool>> &check, int ind1, int ind2, vector<int> &tempArray)
{
	int currValue = mat[ind1][ind2] + 1;
	tempArray.push_back(mat[ind1][ind2]);
	// cout<<"Previous Value "<<currValue-1<<" Current Value "<<currValue<<" index.1 "<<ind1<<" index.2 "<<ind2<<endl;
	if(ind2+1 < 3 && mat[ind1][ind2+1] == currValue)
	{
		check[ind1][ind2+1] = true;
		checkForCell(mat, check, ind1, ind2+1, tempArray);
	}
	else if(ind1+1 < 3 && mat[ind1+1][ind2] == currValue)
	{
		check[ind1+1][ind2] = true;
		checkForCell(mat, check, ind1+1, ind2, tempArray);
	}
	else if(ind2 -1 >= 0 && mat[ind1][ind2-1] == currValue)
	{
		check[ind1][ind2-1] = true;
		checkForCell(mat, check, ind1, ind2-1, tempArray);
	}
	else if(ind1 - 1 >=0 && mat[ind1-1][ind2] == currValue)
	{
		check[ind1-1][ind2] = true;
		checkForCell(mat, check, ind1-1, ind2, tempArray);
	}
	return tempArray;
}

void findLongestPath(vector<vector<int>> &mat, int n)
{
	vector<vector<bool>> check(3, vector<bool>(3, false));
	vector<int> longestArray;
	for(int i = 0; i<n; i++)
	{
		for(int j = 0; j<n; j++)
		{
			vector<int> tempArray;
			if(check[i][j] == false)
			{
				check[i][j] = true;
				tempArray = checkForCell(mat, check, i, j, tempArray);
				if(tempArray.size() > longestArray.size())
					longestArray = tempArray;
			}
		}
	}
	cout<<longestArray.size()<<endl;
	for(int i=0;i<longestArray.size();i++)
		cout<<longestArray[i]<<" ";
	cout<<endl;
}

int main()
{
	vector<vector<int>> mat {
		{1, 2, 9}, {5, 3, 8}, {4, 6, 7}
	};

	int size = 3;

	findLongestPath(mat, size);
}
*/

#include <bits/stdc++.h>
using namespace std;

int calculateAnswer(int n)
{
/*	if(n<0)
		return 0;
	if(n == 0)
		return 1;
	// if(n == 2)
	// 	return 2;
	// if(n == 3)
	// 	return 4;
	return calculateAnswer(n-1) + calculateAnswer(n-2) + calculateAnswer(n-3); */
	int tempArr[n+1];
	tempArr[0] = 1;
	tempArr[1] = 1;
	tempArr[2] = 2;
	for(int i = 3; i <= n;i++)
	{
		tempArr[i] = tempArr[i-1] + tempArr[i-2] + tempArr[i-3];
	}
	return tempArr[n];
}

int main()
{
	int n = 7;
	cout<<calculateAnswer(n)<<endl;
}