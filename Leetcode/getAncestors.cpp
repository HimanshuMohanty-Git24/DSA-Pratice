// 2192. All Ancestors of a Node in a Directed Acyclic Graph
#include <bits/stdc++.h>
using namespace std;
void dfs(int x, int curr, vector<vector<int>> &ans, vector<vector<int>> &directChild)
{
    for (int ch : directChild[curr])
    {
        if (ans[ch].empty() || ans[ch].back() != x)
        {
            ans[ch].push_back(x);
            dfs(x, ch, ans, directChild);
        }
    }
}
vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> ans(n), directChild(n);
    for (auto &e : edges)
    {
        directChild[e[0]].push_back(e[1]);
    }
    for (int i = 0; i < n; i++)
    {
        dfs(i, i, ans, directChild);
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }
    vector<vector<int>> ans = getAncestors(n, edges);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}