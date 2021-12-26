#include <bits/stdc++.h>
using namespace std;
class Graph 
{ 
    int V;              // No. of vertices 
    list<int> *adj;     // Pointer to an array containing 
                        // adjacency lists 
public: 
    Graph(int V);              // Constructor 
    void addEdge(int v, int w);// function to add an edge to graph 
    void longestPathLength();  // prints longest path of the tree 
    pair<int, int> bfs(int u); // function returns maximum distant 
                               // node from u with its distance 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w);    // Add w to v’s list. 
    adj[w].push_back(v);    // Since the graph is undirected 
} 
  
//  method returns farthest node and its distance from node u 
pair<int, int> Graph::bfs(int u) 
{ 
    //  mark all distance with -1 
    int dis[V]; 
    memset(dis, -1, sizeof(dis)); 
  
    queue<int> q; 
    q.push(u); 
  
    //  distance of u from u will be 0 
    dis[u] = 0; 
  
    while (!q.empty()) 
    { 
        int t = q.front();       q.pop(); 
  
        for (auto it = adj[t].begin(); it != adj[t].end(); it++) 
        { 
            int v = *it; 
            if (dis[v] == -1) 
            { 
                q.push(v); 
                dis[v] = dis[t] + 1; 
            } 
        } 
    } 
  
    int maxDis = 0; 
    int nodeIdx; 
  
    for (int i = 0; i < V; i++) 
    { 
        if (dis[i] > maxDis) 
        { 
            maxDis = dis[i]; 
            nodeIdx = i; 
        } 
    } 
    return make_pair(nodeIdx, maxDis); 
} 
  
void Graph::longestPathLength() 
{ 
    pair<int, int> t1, t2; 
    cout<<"ad";
    t1 = bfs(0); 
    t2 = bfs(t1.first); 
  
    cout << "Longest path is from " << t1.first << " to "
         << t2.first << " of length " << t2.second; 
} 
  

string FarthestNodes(string strArr[], int n)
{
	Graph g(n);
	for(int i=0;i<n;i++)
	{
		string temp = strArr[i];
		string first = "";
		string second = "";
		replace(temp.begin(), temp.end(), '-', ' ');
		stringstream geek(temp);
		int a = 0;
		int arr[2];
		int f = 0;
		while(geek>>a)
		{
			if(f==0)
				arr[0] = a;
			else
				arr[1] = a;
		}
		g.addEdge(arr[0], arr[1]);
	} 
    g.longestPathLength(); 
	return "asd";
}

int main()
{
	string A[] = {"b-e","b-c","c-d","a-b","e-f"};
	int n =sizeof(A)/sizeof(A[0]);
	cout<<FarthestNodes(A, n);
}