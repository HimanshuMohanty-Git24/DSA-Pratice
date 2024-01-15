// 2225. Find Players With Zero or One Losses
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
    unordered_map<int, int> winCount;
    unordered_map<int, int> lossCount;
    int n = matches.size();
    for (auto i = 0; i < matches.size(); i++)
    {
        winCount[matches[i][0]]++;
        lossCount[matches[i][1]]++;
    }
    vector<int> lostOnce;
    auto it = lossCount.begin();
    while (it != lossCount.end())
    {
        if (it->second == 1)
            lostOnce.push_back(it->first);
        it++;
    }
    vector<int> lostZero;
    auto it2 = winCount.begin();
    while (it2 != winCount.end())
    {
        if (it2->second >= 1 && lossCount[it2->first] == 0)
            lostZero.push_back(it2->first);
        it2++;
    }
    sort(lostZero.begin(), lostZero.end());
    sort(lostOnce.begin(), lostOnce.end());
    vector<vector<int>> ans;
    ans.push_back(lostZero);
    ans.push_back(lostOnce);
    return ans;
}

int main()
{
    vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
    vector<vector<int>> ans = findWinners(matches);

    // Printing both the pushed array WinnerAlways and LostOnce
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Array " << i + 1 << ": ";
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
