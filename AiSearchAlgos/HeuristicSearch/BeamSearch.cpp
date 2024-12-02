/*
Beam Search
Beam search is a heuristic search algorithm that explores a graph by expanding the most promising nodes in a limited set or "beam".
The beam width, which limits the number of nodes stored in memory, plays a crucial role in the performance and accuracy of the search.
*/
#include<bits/stdc++.h>

using namespace std;

class Graph{
    int V;
    list<pair<int,int>> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void BeamSearch(int s, int d, int beamWidth);
};

Graph::Graph(int V){ //V = number of vertices
    this->V = V;
    adj = new list<pair<int,int>>[V];
}

void Graph::addEdge(int u, int v, int w){ //u = source, v = destination, w = weight
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
}

void Graph::BeamSearch(int s, int d, int beamWidth){ //s = source, d = destination
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
    Graph g(6);
    g.addEdge(0,1,5);
    g.addEdge(0,2,3);
    g.addEdge(1,3,6);
    g.addEdge(1,4,7);
    g.addEdge(2,5,9);
    g.addEdge(3,5,2);
    g.addEdge(4,5,1);
    g.BeamSearch(0,5,2);
    return 0;
}