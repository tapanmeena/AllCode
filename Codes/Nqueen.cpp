#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> &board, int col, int row)
{
	int n = board.size();
	//checking previous column for same row
	for(int i=0; i<col;i++)
	{
		if(board[row][i] == 1)
			return false;
	}

	//checking upper diagonal
	for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--)
	{
		if(board[i][j] == 1)
			return false;
	}
	//checking lower diagonal
	for(int i=row+1, j=col-1; i<n && j>=0;i++,j--)
	{
		if(board[i][j] == 1)
			return false;
	}
	return true;
}

bool solve(vector<vector<int>> &board, int col)
{
	int n = board.size();
	if(col == n)
		return true;
	for(int i=0;i<n;i++)
	{
		if(isSafe(board, col, i))
		{
			board[i][col] = 1;
			if(solve(board, col+1))
				return true;
			else
				board[i][col] = 0;
		}
	}
	return false;
}

int main()
{
	int n = 1;
	vector<vector<int>> board(n, vector<int> (n,0));
	cout<<solve(board,0)<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}