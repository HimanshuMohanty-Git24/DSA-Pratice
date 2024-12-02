/*
A Search Algorithm*
A* Search Algorithm is perhaps the most well-known heuristic search algorithm. It uses a best-first search and finds the least-cost path from
a given initial node to a target node. It has a heuristic function, often denoted as f(n)=g(n)+h(n), where g(n) is the cost from the start node 
to n, and h(n) is a heuristic that estimates the cost of the cheapest path from n to the goal.A* is widely used in pathfinding and graph traversal.
*/

#include<bits/stdc++.h>
using namespace std;


class Graph{
    int V;
    list<pair<int,int>> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void AStar(int s, int d);
};

Graph::Graph(int V){ //V = number of vertices
    this->V = V;
    adj = new list<pair<int,int>>[V];
}

void Graph::addEdge(int u, int v, int w){ //u = source, v = destination, w = weight
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

void Graph::AStar(int s, int d){ //s = source, d = destination
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    vector<int> parent(V,-1);
    vector<bool> visited(V,false);
    pq.push({0,s});
    dist[s] = 0;
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        for(auto i = adj[u].begin(); i != adj[u].end(); i++){
            int v = (*i).first;
            int w = (*i).second;
            if(!visited[v] && dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
                parent[v] = u;
            }
        }
    }
    cout<<"Shortest Path from "<<s<<" to "<<d<<" is: ";
    int temp = d;
    stack<int> path;
    while(temp != -1){
        path.push(temp);
        temp = parent[temp];
    }
    while(!path.empty()){
        cout<<path.top()<<" ";
        path.pop();
    }
    cout<<"\nShortest Distance: "<<dist[d];
}

int main(){
    Graph g(5);
    g.addEdge(0,1,4);//u = source, v = destination, w = weight
    g.addEdge(0,2,1);
    g.addEdge(2,1,2);
    g.addEdge(1,3,1);
    g.addEdge(2,3,5);
    g.addEdge(3,4,3);
    g.AStar(0,4);
    return 0;
}