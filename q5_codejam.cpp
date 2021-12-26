#include<bits/stdc++.h>
using namespace std;

int arr[52][52],n,k;
bool rowCheck[52][52], colCheck[52][52];
bool found;
int casen = 1;

void calc(int row, int column, int m)
{
	if(row == n && column == n+1 && m==k && !found)
	{
		found =true;
        cout << "Case #" << casen << ": " << "POSSIBLE\n";
        for(int i=1; i<=n;i++)
        {
        	for(int j=1;j<=n;j++)
        		cout<<arr[i][j]<<" ";
        cout<<endl;
        }
		return;
	}
	else if(row>n)
		return;
	else if(column>n)
		calc(row+1, 1, m);

	for(int i=1; i<=n && !found; i++)
	{
		if(!rowCheck[row][i] && !colCheck[column][i])
		{
			rowCheck[row][i] = true;
			colCheck[column][i] = true;
			if(row == column)
				m += i;
			arr[row][column] = i;

			calc(row, column+1, m);
			rowCheck[row][i] = false;
			colCheck[column][i] = false;
			if(row == column)
				m -= i;
			arr[row][column] = 0;
		}
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		calc(1,1,0);
		if(!found)
			cout<<"Case #"<<casen<<": IMPOSSIBLE"<<endl;
		casen++;
		found = false;
	}
	return 0;
}