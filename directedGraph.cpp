#include <bits/stdc++.h>
using namespace std;

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

void printGraph(Graph *graph, int e)
{
	for(int i=0; i<e; i++)
	{
		cout<<graph->edge[int].src<<" --> "<<graph->edge[i].dest<<endl;
	}
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

    printGraph(graph, e);
}