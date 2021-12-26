#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int src, dest, weight;
};

int arr[100];

int find(int v)
{
    if(arr[v] == -1)
        return v;
    find(arr[v]);
    return arr[v];    
}


void krushkal(pair<int, pair<int,int>> graph[])
{
    Edge edge[5];
    int currEdge = 0;
    int minimumCost = 0;
    sort(graph, graph+5);
    for(int i=0; i<5; i++)
    {
        int x = find(graph[i].second.first);
        // cout<<"X value "<<x<<endl;
        int y = find(graph[i].second.second);
        // cout<<"Y value "<<y<<endl;
        int cost = graph[i].first;

        if(x != y)
        {
            edge[currEdge].src = y;
            edge[currEdge].dest = x;
            edge[currEdge].weight = cost;
            currEdge++;
            // cout<<"Edges Joined "<<graph[i].second.first<<" "<<graph[i].second.second<<endl;
            minimumCost += cost;
            arr[x] = y;
        }
    }
    for(int i=0; i<currEdge; i++)
        cout<<edge[i].src<<" -> "<<edge[i].dest<<" == "<<edge[i].weight<<endl;
    // cout<<minimumCost<<endl;
/*    for(int i=0;i<5;i++)
        cout<<arr[i]<<" ";
        */
}

int main()
{
    //initialising array 
    memset(arr,-1, sizeof(arr));

    pair<int, pair<int,int>> graph[5];

    graph[0].first = 10;
    graph[0].second = make_pair(0,1);

    graph[1].first = 6;
    graph[1].second = make_pair(0,2);

    graph[2].first = 5;
    graph[2].second = make_pair(0,3);

    graph[3].first = 15;
    graph[3].second = make_pair(1,3);

    graph[4].first = 4;
    graph[4].second = make_pair(2,3);

    krushkal(graph);
}

/*
class Edge
{
public:
	int src, dest, weight;
};

class Graph
{
public:
	int V, E;

	Edge *edge;
};

Graph* createGraph(int v, int e)
{
	Graph *graph = new Graph();
	graph->V = v;
	graph->E = e;

	graph->edge = new Edge[e];	
	return graph;
}

void krushkal(Graph *graph)
{

}

int main()
{
	int v = 4, e = 5;
	Graph* graph = createGraph(v, e);

	// add edge 0-1  
    graph->edge[0].src = 0;  
    graph->edge[0].dest = 1;  
    graph->edge[0].weight = 10;  
  
    // add edge 0-2  
    graph->edge[1].src = 0;  
    graph->edge[1].dest = 2;  
    graph->edge[1].weight = 6;  
  
    // add edge 0-3  
    graph->edge[2].src = 0;  
    graph->edge[2].dest = 3;  
    graph->edge[2].weight = 5;  
  
    // add edge 1-3  
    graph->edge[3].src = 1;  
    graph->edge[3].dest = 3;  
    graph->edge[3].weight = 15;  
  
    // add edge 2-3  
    graph->edge[4].src = 2;  
    graph->edge[4].dest = 3;  
    graph->edge[4].weight = 4;  

    krushkal(graph);
}*/