/*
5. Uniform-Cost Search (UCS)
Uniform-Cost Search is a variant of BFS where the cost of the path is taken into account. It explores the node with the lowest path cost first.
UCS guarantees finding the optimal path to the goal node when the path cost is non-negative.

Uniform-cost search (UCS) is a tree or graph search algorithm used in artificial intelligence that finds the least cost path from a given initial
 node to a goal node. It's useful in situations where paths have different costs associated with them. UCS expands the least costly node first,
 ensuring that when it reaches a goal node, it has found the least cost path to that node
*/

#include<bits/stdc++.h>

using namespace std;


class Graph {
    int V;
    list<pair<int, int>> *adj;
public:

    Graph(int V);
    void addEdge(int u, int v, int w);
    void UCS(int start, int goal);
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v, w));
}

void Graph::UCS(int start, int goal) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push(make_pair(0, start));
    dist[start] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        list<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i) {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    cout << "The shortest path from " << start << " to " << goal << " is " << dist[goal] << endl;
}

int main() {
    Graph g(6);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 5, 3);
    g.addEdge(4, 5, 1);
    g.UCS(0, 5);
    return 0;
}