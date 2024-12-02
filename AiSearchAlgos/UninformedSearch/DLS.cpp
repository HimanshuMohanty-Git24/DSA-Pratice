//Depth-Limited Search (DLS)
//Depth-Limited Search is a variant of Depth-First Search where the depth of the search is limited. This is done to avoid infinite loops in case of cyclic graphs.

#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adj;
    void DLSUtil(int v, bool visited[], int limit);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DLS(int v, int limit);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DLSUtil(int v, bool visited[], int limit) {
    visited[v] = true;
    cout << v << " ";
    if (limit <= 0) {
        return;
    }
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DLSUtil(*i, visited, limit - 1);
        }
    }
}

void Graph::DLS(int v, int limit) {
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++) {
        visited[i] = false;
    }
    DLSUtil(v, visited, limit);
}

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    cout << "Depth-Limited Search (starting from vertex 0 with limit 2): ";
    g.DLS(0, 2);
    return 0;
}