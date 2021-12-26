//for undirected graphs
//for directed graphs change add edge
#include <bits/stdc++.h>
using namespace std;
#define printArr(arr, n) for(int i=0; i<n; i++) cout<<arr[i]<<" ";

class Graph{
	int data;
	list<int> *adj;
public:
	Graph(int d)
	{
		this->data = d;
		adj = new list<int>[d];
	}

	void addEdge(int x, int y)
	{
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	void bfs(int start = 1)
	{
		int check[data];
		memset(check, -1 , sizeof(check));
		queue<int> q;
		q.push(start);
		cout<<"BFS :- ";
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			if(check[x] == -1)
			{
				check[x] = 1;
				for(auto c : adj[x])
					q.push(c);
				cout<<x<<" ";
			}
		}
	}
	void dfs(int start = 1)
	{
		int check[data];
		memset(check, -1, sizeof(check));
		stack<int> s;
		s.push(start);
		cout<<"DFS -> ";
		while(!s.empty())
		{
			int x = s.top();
			s.pop();
			if(check[x] == -1)
			{
				check[x] = 1;
				for(auto c : adj[x])
					s.push(c);
				cout<<x<<" ";
			}
		}
		cout<<endl;
	}

	pair<int,int> findMaxDistance(int child, int disArray[])
	{
		// cout<<"sd"<<endl;
		// printArr(disArray, data);
		// cout<<"sd"<<endl;
		int dis = 90, ind;
		for(auto c : adj[child])
		{
			if(dis > disArray[c])
			{
				dis = disArray[c];
				ind = c;
			}
		}
		pair<int,int> t;
		t.first = dis;
		t.second = ind;
		return t;
	}

	void longestpathlength(int start = 0)
	{
		int check[data];
		memset(check, -1, sizeof(check));
/*		cout<<endl;
		printArr(check, data);
		cout<<endl;
*/
		queue<int> q;
		q.push(start);

		bool first = true;
		cout<<"Nodes Visited :- ";
		bool visited[data];
		memset(visited, false, sizeof(visited));
		int parent[data];
		memset(parent, -1, sizeof(parent));
		while(!q.empty())
		{
			int temp = q.front();
			q.pop();
			cout<<temp<<" ";
			visited[temp] = true;
			pair<int, int> dis;
			if(first)
			{
				dis.first = 0;
				dis.second = 0;
				first = false;
			}
			else
				dis = findMaxDistance(temp, check);
			// cout<<" max "<<dis<<endl;
			if(check[temp] == -1)
			{
				for(auto c : adj[temp])
				{
					if(!visited[c])
						q.push(c);
				}
				check[temp] += dis.first;
				parent[temp] = dis.second;
			}
		}
		cout<<endl;

		// for(int i=0;i<data; i++)
		// 	cout<<check[i]<<" ";
		int des = 100;
		int c;
		for(int i=0;i<data;i++)
			if(des > check[i])
			{
				des = check[i];
				c = i;
			}
		printArr(check, data);
		cout<<endl;
		printArr(parent, data);
		string path = "";
		int p = -100;
		while(p != c)
		{
			// cout<<"sd";
			p = c;
			c = parent[c];
			path = path + to_string(p) + " ";
		}
		reverse(path.begin(), path.end());
		cout<<"Length of longest Path "<<-1*des<<" and Path is"<<path<<endl;
		// check[start]++;
	}
};

int main()
{
	Graph g(13);
/*	g.addEdge(0,2);
	g.addEdge(0,3);
	g.addEdge(0,4);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(1,4);
	g.addEdge(1,5);
	g.addEdge(2,4);*/
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,4);
	g.addEdge(2,5);
	g.addEdge(5,3);
	g.addEdge(2,6);
	g.addEdge(6,7);
	g.addEdge(7,8);
	g.addEdge(3,9);
	g.addEdge(9,10);
	g.addEdge(10,11);
	g.addEdge(11,12);
	g.bfs(0);
	cout<<endl;
	g.dfs(0);
	g.longestpathlength();
}