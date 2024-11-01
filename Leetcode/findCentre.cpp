//1791. Find Center of Star Graph
#include<bits/stdc++.h>
using namespace std;
int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> degree(n+2,0);
        for(int i=0;i<n;i++)
        {
            degree[edges[i][0]]++;
            degree[edges[i][1]]++;
        }
        for(int i=1;i<=n+1;i++)
        {
            if(degree[i]==n)
                return i;
        }
        return -1;
}
int main()
{
    vector<vector<int>> edges = {{1,2},{2,3},{4,2}};
    cout<<findCenter(edges);
   return 0;
}