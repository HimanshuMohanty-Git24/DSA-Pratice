/*
4. Iterative Deepening Depth-First Search (IDDFS)
Iterative Deepening Depth-First Search is a combination of BFS and DFS. It repeatedly applies DFS with increasing depth limits until the goal
node is found. IDDFS combines the benefits of BFS (guaranteed shortest path) and DFS (less memory consumption) by gradually increasing the depth
limit.
*/

#include<bits/stdc++.h>

using namespace std;

class Graph {
    int V;
    list<int> *adj;
    bool DLS(int v, int target, int limit);
public:
    Graph(int V);
    void addEdge(int v, int w);
    bool IDDFS(int v, int target, int max_depth);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

bool Graph::DLS(int v, int target, int limit) {
    if (v == target) {
        return true;
    }
    if (limit <= 0) {
        return false;
    }
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (DLS(*i, target, limit - 1)) {
            return true;
        }
    }
    return false;
}

bool Graph::IDDFS(int v, int target, int max_depth) {
    for (int i = 0; i <= max_depth; i++) {
        if (DLS(v, target, i)) {
            return true;
        }
    }
    return false;
}

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    int target = 6;
    int max_depth = 3;
    cout << "Iterative Deepening Depth-First Search (starting from vertex 0 with max depth " << max_depth << "): ";
    if (g.IDDFS(0, target, max_depth)) {
        cout << "Target " << target << " is reachable from source 0 within max depth " << max_depth << endl;
    } else {
        cout << "Target " << target << " is not reachable from source 0 within max depth " << max_depth << endl;
    }
    return 0;
}