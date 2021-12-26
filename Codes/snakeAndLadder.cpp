#include <bits/stdc++.h>
using namespace std;

struct vertex
{
	int v;
	int distance;
};

int getMinDiceThrows(int moves[], int n)
{
	bool visited[n];
	memset(visited, false, sizeof(visited));

	queue <vertex> q;
	vertex a;
	a.v = moves[0];
	a.distance = 0;
	q.push(a);

	while(!q.empty())
	{
		a = q.front();
		if(a.v == n-1)
			break;

		q.pop();
		int val = a.v;
		for(int i=val+1; i<=(val+6); i++)
		{
			if(!visited[i])
			{
				vertex z;
				z.distance = (a.distance + 1);
				visited[i] = true;

				if(moves[i] != -1)
					z.v = moves[i];
				else
					z.v = i;
				q.push(z);
			}
		}
	}	
	return a.distance;
}

int main()
{
	int N = 30; 
    int moves[N]; 
    for (int i = 0; i<N; i++) 
        moves[i] = -1; 
  
    moves[2] = 28; 
    moves[4] = 7; 
    moves[10] = 25; 
    moves[19] = 28; 
  
    moves[26] = 0; 
    moves[20] = 8; 
    moves[16] = 3; 
    moves[18] = 6; 
  
    cout << "Min Dice throws required is " << getMinDiceThrows(moves, N); 
    return 0; 
}