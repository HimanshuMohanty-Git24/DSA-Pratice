//2285. Maximum Total Importance of Roads
#include<bits/stdc++.h>
using namespace std;
long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0); // Array to store the degree of each city
        
        // Calculate the degree of each city
        for (const auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        // Create a list of cities and sort by degree
        vector<int> cities(n);
        for (int i = 0; i < n; i++) {
            cities[i] = i;
        }
        sort(cities.begin(), cities.end(), [&](int a, int b) {
            return degree[a] > degree[b];
        });
        
        // Assign values to cities starting from the highest degree
        long long totalImportance = 0;
        for (int i = 0; i < n; i++) {
            totalImportance += (long long)(n - i) * degree[cities[i]];
        }
        
        return totalImportance;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>> roads;
    for(int i=0;i<n-1;i++)
    {
        vector<int> temp;
        for(int j=0;j<3;j++)
        {
            int x;
            cin>>x;
            temp.push_back(x);
        }
        roads.push_back(temp);
    }
    cout<<maximumImportance(n,roads);
   return 0;
}