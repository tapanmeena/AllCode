#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;//m is ending row and n is ending column
		int arr[m][n];
		for(int i=0;i<m;i++)
		{
			for(int j = 0; j<n; j++)
				cin>>arr[i][j];
		}

		int startingRow = 0,startingColumn = 0;
		while(startingRow < m && startingColumn < n)
		{
			//printing top row
			for(int i = startingColumn; i<n;i++)
			{
				cout<<arr[startingRow][i]<<" ";
				// cout<<" 1stloop ";
			}
			startingRow++;

			//printing lastcolumn
			for(int i = startingRow; i<m; i++)
			{
				cout<<arr[i][n-1]<<" ";
				// cout<<" 2ndloop ";
			}
			n--;

			//printing bottom row
			if(startingRow < m)
			{
				for(int i = n-1; i>=startingColumn; i--)
					cout<<arr[m-1][i]<<" ";
				m--;
			}

			//printing first column
			if(startingColumn < n)
			{
				for(int i = m-1; i >= startingRow; i--)
					cout<<arr[i][startingColumn]<<" ";
				startingColumn++;				
			}

		}
		cout<<endl;
	}
}