#include <bits/stdc++.h>
using namespace std;

int board[9][9];

void readBoard()
{
	cout<<"----------------------"<<endl;
	for(int i=0;i<9;i++)
	{
		cout<<"|";
		for(int j=0;j<9;j++)
		{
			board[i][j] = (j%3+1);
			cout<<board[i][j]<<" ";
			if((j+1)%3 == 0)
				cout<<"|";
		}
		if((i+1)%3 == 0)
		{
			cout<<endl;
			cout<<"----------------------";
		}
		cout<<endl;
	}
}

int main()
{
	/*
	string temp_board = ". . 2 . . 5 . . .
						 7 . 3 . . . 9 8 5
						 8 . . . . . 1 . 6
						 . . 7 . . . . . .
						 . . . 3 . 8 . . .
						 3 1 6 . 4 . . . .
						 . 3 . 8 1 . 7 9 2
						 . 7 8 . . 2 6 . .
						 2 . . . . . . . 3";
						 */
	string temp_board = "..2..5...7.3...9858.....1.6..7.........3.8...316.4.....3.81.792.78..26..2.......3";
	for(int i=0;i<temp_board.size(); i++)
	{
		if(i%3 == 0 && i>0)
			cout<<"|";
		cout<<temp_board[i]<<" ";
		if(i>0 && i%9 == 0)
			cout<<endl;
	}
	cout<<temp_board<<endl;
	readBoard();
	// cout<<board[2][2].row<<endl;
	return 0;
}